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
int T,x,y;
int main()
{
	T=read();
	while(T--)
	{
		x=read(),y=read();
		if(x>y)
			swap(x,y);
		if(!y)
			puts("0");
		else
			if(x==y)
				printf("%d\n",2*y);
			else
				printf("%d\n",2*y-1);
	}
	return 0;
}