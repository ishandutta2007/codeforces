#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define LL long long 
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,a[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
LL f[N+5],g[N+5],h[N+5],ans[N+5];I void DP(CI x,CI lst=0)
{
	RI i,y,p,q;LL A=0,B=0,C=0;for(g[x]=h[x]=ans[x]=a[x],i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
	(
		DP(y=e[i].to,x),f[y]>f[x]?(B=A,A=f[x],q=p,f[x]=f[p=y]):(f[y]>A?(B=A,A=f[q=y]):B=max(B,f[y])),
		g[y]>g[x]?(C=g[x],g[x]=g[y]):C=max(C,g[y]),h[x]=max(h[x],h[y]+a[x]),ans[x]=max(ans[x],ans[y])
	);
	f[x]+=a[x],ans[x]=max(ans[x],g[x]+C),g[x]=max(g[x],f[x]+A);
	for(i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(h[x]=max(h[x],g[e[i].to]+(e[i].to^p?f[x]:A+a[x])));
	for(i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
	(
		ans[x]=max(ans[x],h[e[i].to]+(e[i].to^p?f[x]:A+a[x])),
		ans[x]=max(ans[x],g[e[i].to]+(e[i].to^p?f[x]+(e[i].to^q?A:B):A+B+a[x]))
	);
}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	RI x,y;for(i=1;i^n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);return DP(1),printf("%lld\n",ans[1]),0;
}