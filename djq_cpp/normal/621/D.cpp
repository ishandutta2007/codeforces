/*
log: 
z log y+log log x
y log z+log log x
log y+log z+log log x
log y+log z+log log x
z log x+log log y
x log z+log log y
log x+log z+log log y
log x+log z+log log y
y log x+log log z
x log y+log log z
log x+log y+log log z
log x+log y+log log z
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
double a[12];
string S[12]={"x^y^z",
			  "x^z^y",
			  "(x^y)^z",
			  "(x^z)^y",
			  "y^x^z",
			  "y^z^x",
			  "(y^x)^z",
			  "(y^z)^x",
			  "z^x^y",
			  "z^y^x",
			  "(z^x)^y",
			  "(z^y)^x"};
int main()
{
	double x,y,z;
	cin>>x>>y>>z;
	a[0]=z*log(y)+log(log(x));
	a[1]=y*log(z)+log(log(x));
	a[2]=log(y)+log(z)+log(log(x));
	a[3]=log(y)+log(z)+log(log(x));
	a[4]=z*log(x)+log(log(y));
	a[5]=x*log(z)+log(log(y));
	a[6]=log(x)+log(z)+log(log(y));
	a[7]=log(x)+log(z)+log(log(y));
	a[8]=y*log(x)+log(log(z));
	a[9]=x*log(y)+log(log(z));
	a[10]=log(x)+log(y)+log(log(z));
	a[11]=log(x)+log(y)+log(log(z));
	int A=0;
	for(int i=0;i<12;i++)
	if(a[i]>a[A]||(!a[A]==a[A]))
	A=i;
	if(a[A]!=a[A])
	{
		a[0]=pow(y,z)*log(x);
		a[1]=pow(z,y)*log(x);
		a[2]=y*z*log(x);
		a[3]=y*z*log(x);
		a[4]=pow(x,z)*log(y);
		a[5]=pow(z,x)*log(y);
		a[6]=x*z*log(y);
		a[7]=x*z*log(y);
		a[8]=pow(x,y)*log(z);
		a[9]=pow(y,x)*log(z);
		a[10]=x*y*log(z);
		a[11]=x*y*log(z);
		A=0;
		for(int i=0;i<12;i++)
		if(a[i]>a[A])
		A=i;
	}
	cout<<S[A]<<endl;
	return 0;
}