#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500000
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
#define Gmax(x,y) (x<(y)&&(x=(y)))
using namespace std;
int n,res,Mx[1<<22],ee,lnk[N+5];struct edge {int to,nxt,v;}e[N+5];
int D[N+5],V[N+5],g[N+5],sz[N+5];I void dfs(CI x)
{
	sz[x]=1;for(RI i=lnk[x];i;i=e[i].nxt) D[e[i].to]=D[x]+1,
		V[e[i].to]=V[x]^e[i].v,dfs(e[i].to),sz[x]+=sz[e[i].to],sz[e[i].to]>sz[g[x]]&&(g[x]=e[i].to);
}
I void Mark(CI x) {Mx[V[x]]=max(Mx[V[x]],D[x]);for(RI i=lnk[x];i;i=e[i].nxt) Mark(e[i].to);}
I void Clear(CI x) {Mx[V[x]]=0;for(RI i=lnk[x];i;i=e[i].nxt) Clear(e[i].to);}
I void Q(CI x)
{
	Mx[V[x]]&&Gmax(res,Mx[V[x]]+D[x]);for(RI i=0;i^22;++i) Mx[V[x]^(1<<i)]&&Gmax(res,Mx[V[x]^(1<<i)]+D[x]);
	for(RI i=lnk[x];i;i=e[i].nxt) Q(e[i].to);
}
int ans[N+5];I void DSU(CI x)
{
	if(!g[x]) return (void)(Mx[V[x]]=D[x]);
	RI i;for(i=lnk[x];i;i=e[i].nxt) e[i].to^g[x]&&(DSU(e[i].to),Clear(e[i].to),0);
	for(DSU(g[x]),res=0,i=lnk[x];i;i=e[i].nxt) e[i].to^g[x]&&(Q(e[i].to),Mark(e[i].to),0);
	for(Mx[V[x]]&&Gmax(res,Mx[V[x]]+D[x]),i=0;i^22;++i) Mx[V[x]^(1<<i)]&&Gmax(res,Mx[V[x]^(1<<i)]+D[x]);Gmax(Mx[V[x]],D[x]);
	for(ans[x]=res-2*D[x],i=lnk[x];i;i=e[i].nxt) ans[x]=max(ans[x],ans[e[i].to]);
}
int main()
{
	RI i,x;char c;for(scanf("%d",&n),i=2;i<=n;++i) scanf("%d %c",&x,&c),add(x,i,1<<c-'a');
	for(D[1]=1,dfs(1),DSU(1),i=1;i<=n;++i) printf("%d%c",ans[i]," \n"[i==n]);return 0;
}