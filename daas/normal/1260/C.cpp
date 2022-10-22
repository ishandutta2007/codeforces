#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,p1,p2,K,a,b;
inline int gcd(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
int main()
{
	T=read();
	while(T--)
	{
		p1=read(),p2=read(),K=read();
		if(p1==p2)
		{
			puts("OBEY");
			continue;
		}
		int d=gcd(p1,p2);
		p1/=d;
		p2/=d;
		if(p1>p2)
			swap(p1,p2);
		if((p2-2)/p1+1>=K)
		{
			puts("REBEL");
			continue;
		}
		puts("OBEY");
	}
	return 0;
}