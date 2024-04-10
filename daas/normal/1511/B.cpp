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
int T;
void print1(int len,int suf)
{
	if(len==suf) putchar('2');
	else
	{
		putchar('1');
		for(int i=2;i<=len-suf;++i) putchar('0');
		putchar('1');
	}
	for(int i=1;i<suf;++i) putchar('0');
}
void print2(int len,int suf)
{
	putchar('1');
	for(int i=2;i<=len;++i) putchar('0');
}
int main()
{
	T=read();
	while(T--)
	{
		int a=read(),b=read(),c=read();
		if(a>b)
		{
			print1(a,c);
			putchar(' ');
			print2(b,c);
			putchar('\n');
		}
		else
		{
			print2(a,c);
			putchar(' ');
			print1(b,c);
			putchar('\n');
		}
	}
	return 0;
}