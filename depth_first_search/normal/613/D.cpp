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
#define LN 20
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
namespace VirtualTree
{
	int cnt,o[N+5],d,dI[N+5],dO[N+5],dep[N+5],fa[N+5][LN+5];
	I bool cmp(CI x,CI y) {return dI[x]<dI[y];}
	I int LCA(RI x,RI y)
	{
		RI i;dep[x]<dep[y]&&(x^=y^=x^=y);
		for(i=0;dep[x]^dep[y];++i) (dep[x]^dep[y])>>i&1&&(x=fa[x][i]);if(x==y) return x;
		for(i=LN;~i;--i) fa[x][i]^fa[y][i]&&(x=fa[x][i],y=fa[y][i]);return fa[x][0];
	}
	I void dfs(CI x=1,CI lst=0)
	{
		RI i;for(dI[x]=++d,i=1;i<=LN;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
		for(i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
			(dep[e[i].to]=dep[fa[e[i].to][0]=x]+1,dfs(e[i].to,x),0);dO[x]=d;
	}
	int vis[N+5],S[N+5],anc[N+5],g[N+5];I void Solve()
	{
		RI i;for(sort(o+1,o+cnt+1,cmp),i=1;i<=cnt;++i) vis[o[i]]=1;
		#define Ins(x) (!vis[x]&&(vis[o[++cnt]=x]=2))
		RI x,t=cnt,ans=0;for(i=1;i^t;++i) x=LCA(o[i],o[i+1]),Ins(x);
		RI T=0;for(sort(o+1,o+cnt+1,cmp),i=1;i<=cnt;++i)
			{W(T&&dO[o[S[T]]]<dI[o[i]]) --T;anc[i]=S[T],S[++T]=i,g[i]=0;}
		for(i=2;i<=cnt;++i) if(vis[o[anc[i]]]==1)
			if(vis[o[i]]==1&&dep[o[anc[i]]]+1==dep[o[i]]) {puts("-1");goto Cl;}
		for(i=cnt;i;--i) vis[o[i]]==1?(ans+=g[i],++g[anc[i]]):g[i]&&(g[i]==1?++g[anc[i]]:++ans);
		printf("%d\n",ans);Cl:for(i=1;i<=cnt;++i) vis[o[i]]=0;cnt=0;
	}
}
int main()
{
	using namespace VirtualTree;
	RI i,x,y;for(scanf("%d",&n),i=1;i^n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);dfs();
	RI Qt;scanf("%d",&Qt);W(Qt--) {for(scanf("%d",&x);x;--x) scanf("%d",o+(++cnt));Solve();}
	return 0;
}