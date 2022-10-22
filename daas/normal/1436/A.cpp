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
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,sum;
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		sum=0;
		for(int i=1;i<=n;++i)
			sum+=read();
		puts(sum==m?"YES":"NO");
	}
	return 0;
}