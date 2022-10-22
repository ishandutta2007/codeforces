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
int n,t,s[201],start;
bool flag;
signed main()
{
	rd(t);
	while(t>0)
	{
		--t;
		rd(n);
		for(int i=0;i<n;++i)
		{
			rd(s[i]);
			if(s[i]==1)
			{
				start=i;
			}
		}
		flag=false;
		if(s[(start+n-1)%n]==n)
		{
			flag=true;
			for(int i=start+n-2;i>start;--i)
			{
				if(s[i%n]+1!=s[(i+1)%n])
				{
					flag=false;
					break;
				}
			}
		}
		if(s[(start+n+1)%n]==n)
		{
			flag=true;
			for(int i=start+2;i<start+n;++i)
			{
				if(s[i%n]+1!=s[(i-1)%n])
				{
					flag=false;
					break;
				}
			}
		}
		if(flag)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}