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
int n,a[150001],last,ans;
signed main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		rd(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		if(a[i]-1>last)
		{
			last=a[i]-1;
			++ans;
		}
		else if(a[i]>last)
		{
			last=a[i];
			++ans;
		}
		else if(a[i]+1>last)
		{
			last=a[i]+1;
			++ans;
		}
	}
	printf("%lld",ans);
	return 0;
}