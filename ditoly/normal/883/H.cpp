#include <cstdio>
#include <cstring>
#include <algorithm>
#define MS 305
#define MN 400005
using namespace std;
int n,sig,len,ans,tp,lim;
int gs[MS],md[MN];
char c[MN];

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

int main()
{
	register int i,j;
	n=read();
	scanf("%s",c+1);
	for (i=1;i<=n;++i) ++gs[c[i]];
	for (i=0;i<MS;++i) if (gs[i]&1) ++sig;
	if (!sig)
	{
		puts("1");
		for (i=0;i<MS;++i)
			for (j=1;j<=gs[i]/2;++j) putchar(i);
		for (i=MS-1;i>=0;--i)
			for (j=1;j<=gs[i]/2;++j) putchar(i);
		return 0;
	}
	for (i=1;i<=n;++i)
	{
		if (n%i||i<sig) continue;
		len=n/i;
		if (~len&1) continue;
		if ((i-sig)&1) continue;
		break;
	}
	ans=i; printf("%d\n",ans); tp=0;
	for (i=0;i<MS;++i) if (gs[i]&1) md[++tp]=i,--gs[i];
	for (i=0;i<MS&&tp<ans;++i)
		while (gs[i]&&tp<ans) gs[i]-=2,md[++tp]=i,md[++tp]=i;
	tp=0;
	for (i=0;i<MS;++i)
		for (j=1;j<=gs[i]/2;++j) c[++tp]=i;
	lim=0;
	for (i=1;i<=ans;++i,lim+=len/2)
	{
		for (j=1;j<=len/2;++j) putchar(c[lim+j]);
		putchar(md[i]);
		for (j=len/2;j>=1;--j) putchar(c[lim+j]);
		putchar(' ');
	}
}