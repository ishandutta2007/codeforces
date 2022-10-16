#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+c>=b&&b+c>=a)
		cout<<(a+b+c)/2*2;
	else
		cout<<(min(a,b)+c)*2;
}