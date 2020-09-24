#include <iostream>

class FuzzyNumber {		//Описание класса. Все его объекты и методы.
public:
	double Rinfelicity, number, Linfelicity;
	void show() {
		std::cout << "(" << Linfelicity << "," << number << "," << Rinfelicity << ")";
	}

	void init(double E, double e) { //Метод инициализации Числа вида (x-a,x,x+a) из пары чисел <x,a>
		Rinfelicity = E + e;
		number = E;
		Linfelicity = E - e;
	}

	void  sum(FuzzyNumber I, FuzzyNumber L) //Метод сложения объектов класса 
	{
		Rinfelicity = I.Rinfelicity + L.Rinfelicity;
		number = I.number + L.number;
		Linfelicity = I.Linfelicity + L.Linfelicity;
	}

	void  difference(FuzzyNumber I, FuzzyNumber L) //Метод вычитания объектов класса 
	{
		Rinfelicity = I.Rinfelicity - L.Linfelicity;
		number = I.number - L.number;
		Linfelicity = I.Linfelicity - L.Rinfelicity;
	}

	void  devide(FuzzyNumber I, FuzzyNumber L) //Метод деления объектов класса
	{
		Rinfelicity = I.Rinfelicity / L.Linfelicity;
		number = I.number / L.number;
		Linfelicity = I.Linfelicity / L.Rinfelicity;
	}

	void  multiply(FuzzyNumber I, FuzzyNumber L) //Метод умножения объектов класса
	{
		Rinfelicity = I.Rinfelicity * L.Rinfelicity;
		number = I.number * L.number;
		Linfelicity = I.Linfelicity * L.Linfelicity;
	}

	void  reversion(FuzzyNumber L) //Метод риверсии объектов класса (1/x+a,1/x,1/x-a)
	{
		Rinfelicity = 1 / L.Linfelicity;
		number = 1 / L.number;
		Linfelicity = 1 / L.Rinfelicity;
	}

	void  comparison(FuzzyNumber I, FuzzyNumber L) //Метод сравнения объектов класса
	{
		if (I.number > L.number) //Если  первый объект больше
		{
			number = I.number;
			Rinfelicity = I.Rinfelicity;
			Linfelicity = I.Linfelicity;
		}
		if (I.number < L.number) //Если  второй объект больше
		{
			number = L.number;
			Rinfelicity = L.Rinfelicity;
			Linfelicity = L.Linfelicity;
		}

	}
};

int main()
{
	char operation = '0';
	double E, e;
	FuzzyNumber A; FuzzyNumber B; FuzzyNumber RES;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl; // Краткое описанние программы
	std::cout << "This programm is created for working on Fuzzy Numbers " << std::endl;
	std::cout << "aka (x - e, x, x + e), where x is number and e is infelicity.  " << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Enter First number and it's infelicity    " << std::endl;
	std::cin >> E >> e; //Считывание первого числа
	A.init(E, e);
	std::cout << "Enter operation (+ - * / r ?)\n r stands for renversion of number\n ? stands for comparison   " << std::endl;
	std::cin >> operation; //Считывание операции
	if (operation != 'r')
	{
		std::cout << "Enter Second number and it's infelicity   " << std::endl;
		std::cin >> E >> e; //Считывание второго числа
		B.init(E, e);
	}
	if (operation == '+') 	RES.sum(A, B);
	if (operation == '-') 	RES.difference(A, B);
	if (operation == '/') 	RES.devide(A, B);
	if (operation == '*') 	RES.multiply(A, B);
	if (operation != '?' && operation != 'r')
	{
		std::cout << "Your equity:   "; //Вывод равенства
		A.show();
		std::cout << " " << operation << " ";
		B.show();
		std::cout << " = ";
		RES.show();
	}
	if (operation == 'r')
	{
		RES.reversion(A);
		RES.show();
		std::cout << "   is reversed number" << std::endl;
	}
	if (operation == '?')
	{
		RES.comparison(A, B);
		RES.show();
		std::cout << "   is bigger number" << std::endl;
	}

}