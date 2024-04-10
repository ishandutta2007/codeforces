#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,T;
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		if(n%2)
		{
			int D=(2*K-1)/(n-1);
			printf("%d\n",(K+D)%n==0?n:(K+D)%n);
		}
		else
			printf("%d\n",(K%n==0?n:K%n));
	}
	return 0;
}