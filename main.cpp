#include <iostream>
#include <string>
#include <math.h>
#include <stack>
using namespace std;

int jakiZnak(string linia, int i);
bool czyCyfra(string linia, int i);
int strToInt(string linia, int dlugosc_liczby, int i);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	stack < int > stos1;
	stack < int > stos2;
	string linia;
	int liczba;
	int dlugosc_liczby = 0;
	float liczby[10];
	cout<<"Podaj tekst : ";
	getline(cin,linia);
	linia = linia+'k';
	cout<<"Podany tekst :"<<linia<<endl;
	cout<<"Dlugosc tekstu: "<<linia.size()<<endl;
	for(int i = 0; i<linia.size() ; i++)
	{
		cout<<endl<<linia[i];		
		if( czyCyfra(linia, i) )
			{
				dlugosc_liczby++;
			}
		if( jakiZnak(linia, i) != 0 || i==linia.size()-1 )
		{
			cout<<"\tDlugosc liczby : "<<dlugosc_liczby;
			liczba = strToInt(linia, dlugosc_liczby, i);
			
			stos1.push(liczba);			// tu siê cuda dziej¹
								
			cout<<"\tliczba : "<<liczba;
			dlugosc_liczby = 0;
			cout<<"\tZnak nr : "<<jakiZnak(linia, i)<<endl;
			if( jakiZnak(linia, i) != 0)
			{			
				stos2.push(jakiZnak(linia, i));
			}
		}

	}
	cout<<"\nZawartosc stosu z liczbami:\n";
	do
	{	
		int s = stos1.top();
		cout<<s<<endl;
		stos1.pop();
	}while(stos1.empty()!=1);
	
	cout<<"\nZawartosc stosu ze znakami:\n";
	do
	{	
		int s = stos2.top();
		cout<<s<<endl;
		stos2.pop();
	}while(stos2.empty()!=1);
	
	return 0;
}

int jakiZnak (string linia, int i)
{
	int znak;
		if (linia[i] == '+')
			znak = 1;
		else if (linia[i] == '-')
			znak = 2;
		else if (linia[i] == '*')
			znak = 3;
		else if (linia[i] == '/')
			znak = 4;
		else if (linia[i] == '(')
			znak = 5;
		else if (linia[i] == ')')
			znak = 6;
		else
			znak=0;
		return znak;
}

bool czyCyfra(string linia, int i)
{
	bool cyfra = 0;
	if (linia[i] >= '0' && linia[i] <= '9')
		cyfra = 1;
	else
		cyfra = 0;
	
	return cyfra;	
}

int strToInt(string linia, int dlugosc_liczby, int i)
{
	int liczba = 0;
	for (int x = i-dlugosc_liczby; x < i  ; x++)
	{
		liczba = liczba +  (linia[x] - 48)*pow(10, dlugosc_liczby-1);
		dlugosc_liczby--;
	}
	return liczba;
}
