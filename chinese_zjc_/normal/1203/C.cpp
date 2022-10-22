//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
inline int rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-'&&tmp!=EOF)
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
	}
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	return ddd*=xxx;
}
inline char rd(char &ddd)
{
	char tmp=getchar();
	while(tmp==' '||tmp=='\n')
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
	}
	return ddd=tmp;
}
inline int max(const int &A,const int &B)
{
	return A<B?B:A;
}
inline int min(const int &A,const int &B)
{
	return A<B?A:B;
}
inline int _gcd(int a,int b)
{
	return a%b?_gcd(b,a%b):b;
}
inline int gcd(int a,int b)
{
	return a>b?_gcd(a,b):_gcd(b,a);
}
int n,tmp,num,ans;
signed main()
{
	rd(n);
	rd(num);
	for(int i=2;i<=n;++i)
	{
		rd(tmp);
		num=gcd(tmp,num);
	}
	for(int i=1;i*i<num;++i)
	{
		if(!(num%i))
		{
			++ans;
		}
	}
	ans<<=1;
	if(((int)sqrt(num))*((int)sqrt(num))==num)
	{
		++ans;
	}
	printf("%lld",ans);
	return 0;
}