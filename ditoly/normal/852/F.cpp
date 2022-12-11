#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MA 1000129
using namespace std;
int n,m,p,pri,zs;
int pro[MA],npr[MA],a[MA];

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

inline int C(int x,int y,int MOD) {return 1LL*pro[x]*npr[y]%MOD*npr[x-y]%MOD;}
int mi(int a,int y,int MOD)
{
	int z=1;
	for (;y;y>>=1,a=1LL*a*a%MOD) if (y&1) z=1LL*z*a%MOD;
	return z;
}

int main()
{
	register int i,mod;
	n=read(); m=read(); p=read(); mod=read();
	for (pri=1;pri<MA;++pri) if (mi(p,pri,mod)==1) break;
//	gh=(int)sqrt(MA)*25;
//	nwp=mi(p,gh,mod);
//	memset(ha,127,sizeof(ha));
//	for (i=1;i<=gh;++i) lh=geth(mi(nwp,i,mod)),ha[lh]=min(ha[lh],i);
//	for (i=0;i<gh;++i) lh=geth(mi(p,i,mod)),pri=min(pri,ha[lh]<=gh?gh*ha[lh]-i:pri);
	for (pro[0]=i=1;i<=m;++i) pro[i]=1LL*pro[i-1]*i%pri;
	for (npr[m]=mi(pro[m],pri-2,pri),i=m-1;i>=0;--i) npr[i]=1LL*npr[i+1]*(i+1)%pri;
	for (i=zs=0;i<=m&&i<n;++i)
	{
		zs+=C(m,i,pri);
		if (zs>=pri) zs-=pri;
		a[n-i]=mi(p,zs,mod);
	}
	for (;i<n;++i) a[n-i]=a[n-i+1];
	for (i=1;i<=n;++i) printf("%d ",a[i]);
}