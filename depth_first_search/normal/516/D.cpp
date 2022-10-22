#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define LL long long
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
using namespace std;
int n,p[N+5],Ex[N+5],ee,lnk[N+5];struct edge {int to,nxt,v;}e[N<<1];
int fa[N+5],g[N+5];I int getfa(CI x) {return fa[x]^x?fa[x]=getfa(fa[x]):x;}
namespace TreeDP
{
	LL Mx[N+5],Sx[N+5];int P[N+5];I void dfs1(CI x,CI lst=0)
	{
		LL t;for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(dfs1(e[i].to,x),
			(t=Mx[e[i].to]+e[i].v)>Mx[x]?(Sx[x]=Mx[x],Mx[x]=t,P[x]=e[i].to):Sx[x]<t&&(Sx[x]=t));
	}
	LL f[N+5];I void dfs2(CI x,CI lst=0,Con LL& M=0)
	{
		f[x]=max(Mx[x],M);for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
			(dfs2(e[i].to,x,max(M,P[x]^e[i].to?Mx[x]:Sx[x])+e[i].v),0);
	}
}
using namespace TreeDP;
I bool cmp(CI x,CI y) {return f[x]<f[y];}
int main()
{
	RI Qt,i,x,y,z;for(scanf("%d",&n),i=1;i^n;++i) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	LL t;for(dfs1(1),dfs2(1),i=1;i<=n;++i) p[i]=i;sort(p+1,p+n+1,cmp);
	RI ans;scanf("%d",&Qt);W(Qt--)
	{
		for(scanf("%lld",&t),i=1;i<=n;++i) fa[i]=i,g[i]=Ex[i]=0;
		for(ans=0,x=y=n;y;ans=max(ans,g[p[y]]),--y)
		{
			W(f[p[x]]-f[p[y]]>t) --g[getfa(p[x])],Ex[p[x--]]=0;g[p[y]]=Ex[p[y]]=1;
			for(i=lnk[p[y]];i;i=e[i].nxt) Ex[e[i].to]&&(fa[z=getfa(e[i].to)]=p[y],g[p[y]]+=g[z]);
		}printf("%d\n",ans);
	}return 0;
}