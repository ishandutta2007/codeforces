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
string s,t;
int l[200001],r[200001],sl,tl,ans;
signed main()
{
	cin>>s>>t;
	s=" "+s+" ";
	t=" "+t+" ";
	sl=s.length();
	tl=t.length();
	for(int i=0,j=0;i<=tl;++i)
	{
		while(t[i]!=s[j])
		{
			++j;
		}
		l[i]=j;
		++j;
	}
	for(int i=tl-1,j=sl-1;i>=0;--i)
	{
		while(t[i]!=s[j])
		{
			--j;
		}
		r[i]=j;
		--j;
	}
	for(int i=1;i<tl;++i)
	{
		ans=max(r[i]-l[i-1],ans);
	}
	printf("%lld",ans-1);
	return 0;
}