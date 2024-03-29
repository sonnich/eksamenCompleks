// Eksamen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <regex>
#include <math.h>
#include <algorithm>


class ComplexNR
{
private:
	double m_realPart;
	double m_imagPart;

public:
	ComplexNR(double real=0, double imag=0) :
		m_realPart(real), m_imagPart(imag) 
	{

	}

	friend ComplexNR operator+(const ComplexNR &c1, const ComplexNR &c2);
	friend ComplexNR operator-(const ComplexNR &c1, const ComplexNR &c2);
	friend ComplexNR operator/(const ComplexNR &c1, const ComplexNR &c2);
	friend ComplexNR operator*(const ComplexNR &c1, const ComplexNR &c2);


	friend std::ostream& operator<<(std::ostream& out, const ComplexNR &c1);
	friend std::istream& operator>>(std::istream& in, ComplexNR &c1);

	void print() {

		std::cout << m_realPart << " +i" << m_imagPart << "\n";
	
	}
	double& getReal() {
		return m_realPart;
	}

	double getImag() {
		return m_imagPart;
	}

};


ComplexNR operator+(const ComplexNR &c1, const ComplexNR &c2) {
	ComplexNR result(c1.m_realPart + c2.m_realPart, c1.m_imagPart + c2.m_imagPart);
	return result;

}

ComplexNR operator-(const ComplexNR &c1, const ComplexNR &c2) {
	ComplexNR result(c1.m_realPart + c2.m_realPart, c1.m_imagPart + c2.m_imagPart);
	return result;
}

ComplexNR operator*(const ComplexNR &c1, const ComplexNR &c2) {
	double newReal = c1.m_realPart * c2.m_realPart - c1.m_imagPart * c2.m_imagPart;
	double newImag = c1.m_realPart * c2.m_imagPart + c1.m_imagPart * c2.m_realPart;
	ComplexNR result(newReal, newImag);
	return result;
}

ComplexNR operator/(const ComplexNR &c1, const ComplexNR &c2 ) {
	double denominator = c2.m_realPart * c2.m_realPart + c2.m_imagPart * c2.m_imagPart;
	double newReal = (c1.m_realPart * c2.m_realPart + c1.m_imagPart * c2.m_imagPart) / denominator;
	double newImag = (c1.m_imagPart * c2.m_realPart - c1.m_realPart * c2.m_imagPart) / denominator;
	ComplexNR result(newReal, newImag);
	return result;
}

std::ostream& operator<<(std::ostream& out, const ComplexNR &c1) {
	
	out << "(" << c1.m_realPart << " +i" << c1.m_imagPart << ")";
	
	return out;

}

std::istream& operator>>(std::istream& in, ComplexNR &c1) {
	char p, i;

	in >> c1.m_realPart;
	in >> p;
	in >> i;
	in >> c1.m_imagPart;

	return in;

}



ComplexNR getComplex(int i) {
	while (true) {
		std::cout << "Indtast det "<< i<<". komplekse tal paa formen 2.0 + i5.6\n";

		
		ComplexNR c1;
		std::string input;
		std::cin >> c1;


		if (c1.getImag()==0) {
			std::cin.clear();
			std::cin.ignore(32767, '\n'); 
			std::cout << "Kan ikke tolke det som et komplekst tal proev som: 2.0 + i5.6.\n";

		}
		std::cin.ignore(32767, '\n'); 
							  
		if (c1.getReal() != 0 && c1.getImag() != 0) {
			return c1;
		}
		

	}
}


char getOperator()
{
	while (true) 
	{
		std::cout << "Indtast en af foelgende operatorer: +, -, *, or /: ";
		char op1;
		std::cin >> op1;

		

		std::cin.ignore(32767, '\n');
		
		if (op1 == '+' || op1 == '-' || op1 == '*' || op1 == '/')
			return op1; 
		else 
			std::cout << "Kan ikke tolke: " << op1 << " som en gyldig operator. Prøv igen.\n";
	} 
}

void doTheMath(const ComplexNR &c1, const ComplexNR &c2, const char &op) {


		if (op == '+') {
			std::cout << c1 << " + " << c2 << " is " << c1 + c2 << '\n';
		}
		else if (op == '-') {
			std::cout << c1 << " - " << c2 << " is " << c1 - c2 << '\n';
		}
		else if (op == '*') {
			std::cout << c1 << " * " << c2 << " is " << c1 * c2 << '\n';
		}
		else if (op == '/') {
			std::cout << c1 << " / " << c2 << " is " << c1 / c2 << '\n';
		}
		else // 
			std::cout << "Endte her??????";


	
}



int main()
{
	
		ComplexNR t1 = getComplex(1);
		char op = getOperator();
		ComplexNR t2 = getComplex(2);
		doTheMath(t1, t2, op);


    return 0;
}

