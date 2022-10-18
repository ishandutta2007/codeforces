#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
typedef long long LL;
inline int read()
{
	int x=0;bool f=0;char c=getchar();
	for (;c<'0'||c>'9';c=getchar()) f=c=='-'?1:0;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return f?-x:x;
}
LL m,b1,q,l,ans=0;
map<LL,bool> na;

int main()
{
	b1=read();q=read();l=read();m=read();
	for (int i=1;i<=m;i++) na[read()]=1;
	if (!b1) return printf(na[0]?"0":"inf"),0;
	if (abs(b1)>l) return printf("0"),0;
	if (!q) 
	{
		if (abs(b1)<=l)
		{
			if (!na[0]) return printf("inf"),0;
			else if (!na[b1]) return printf("1"),0;
			else return printf("0"),0;
		}
		else
		{
			if (!na[0]) return printf("inf"),0;
			else return printf("0"),0;
		}
	}
	if (q==1)
	{
		if (abs(b1)<=l)
		{
			if (!na[b1]) return printf("inf"),0;
			else return printf("0"),0;
		}
		else return printf("0"),0;
	}
	if (q==-1) 
	{
		if (abs(b1)<=l)
		{
			if (!na[b1]||!na[-b1]) return printf("inf"),0;
			else return printf("0"),0;
		}
		else return printf("0"),0;
	}
	for (;abs(b1)<=l;b1*=q)
	{
		int ok=1;
		for (int i=1;i<=m&&ok;i++) if (na[b1]) ok=0;
		ans+=ok;
	}
	printf("%d",ans);
	return 0;
}