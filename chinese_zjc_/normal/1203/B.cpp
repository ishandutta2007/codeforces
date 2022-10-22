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
int m,n,t,s[401],stds;
bool flag;
signed main()
{
	rd(t);
	while(t>0)
	{
		--t;
		rd(n);
		m=n<<2;
		for(int i=1;i<=m;++i)
		{
			rd(s[i]);
		}
		sort(s+1,s+1+m);
		flag=false;
		for(int i=1;i<=m;i+=2)
		{
			if(s[i]!=s[i+1])
			{
				puts("NO");
				flag=true;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		stds=s[1]*s[m];
		flag=false;
		for(int i=2;i<=n;++i)
		{
			if(s[i<<1]*s[((n<<1)-i+1)<<1]!=stds)
			{
				puts("NO");
				flag=true;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		puts("YES");
	}
	return 0;
}