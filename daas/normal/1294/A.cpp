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
int T,a,b,c,n;
int main()
{
	T=read();
	while(T--)
	{
		a=read(),b=read(),c=read(),n=read();
		int maxn=max(max(a,b),c);
		n-=(maxn-a);
		n-=(maxn-b);
		n-=(maxn-c);
		if(n<0 || n%3)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}