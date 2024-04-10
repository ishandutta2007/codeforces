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
int T,l,r;
int main()
{
	T=read();
	while(T--)
	{
		l=read(),r=read();
		int x,y=r;
		if(r%2)
			--y;
		x=y/2;
		if(x>=l)
			printf("%d %d\n",x,y);
		else
			printf("%d %d\n",-1,-1);
	}
	return 0;
}