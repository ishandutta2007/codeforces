#include<iostream>
using namespace std;
int calc(int x,int y)
{
	int temp=y/2;
	if (temp*2==y) return temp*x;
	else return temp*x+x/2;
}
int main()
{
	int m,n;
	cin>>m>>n;
	if(calc(m,n)>calc(n,m)) cout<<calc(m,n);
	else cout<<calc(n,m);
	return 0;
}