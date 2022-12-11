#include <cstdio>
#include <algorithm>
#define MN 10005
using namespace std;
//struct edge{int nex,to,wt;}e[MN<<1];
int a[MN],ans,n,m;

inline int read()
{
	int n=0,f=1;char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

int main()
{
	register int i,x,y,z;
	n=read(); m=read();
	for (i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	for (i=1;i<=m;++i) ans+=a[i];
	printf("%d",ans);
}