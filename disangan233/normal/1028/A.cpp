#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define re register int
int n,m,a1=10000,a2=10000,a3,a4;
int main()
{
	cin>>n>>m;
	for(re i=1;i<=n;i++)
	for(re j=1;j<=m;j++)
	{
		char a;
		cin>>a;
		if(a=='B')
		{
			if(i+j<=a1+a2) a1=i,a2=j;
			if(i+j>=a3+a4) a3=i,a4=j; 
		}
	}
	cout<<(a1+a3)/2<<" "<<(a2+a4)/2;
	return 0;
}