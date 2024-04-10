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
#define INF (int)1e9
using namespace std;
int n,m,ct,a[N+5];
template<int PS,int ES> struct Graph
{
	int ee,lnk[PS+5];struct edge {int to,nxt;}e[2*ES+5];
	I void add(CI x,CI y) {e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y;}
	I void Add(CI x,CI y) {add(x,y),add(y,x);}
	I int operator [] (CI x) Cn {return lnk[x];}I edge operator () (CI x) Cn {return e[x];}
};Graph<N,N> G;Graph<N<<1,N<<1> T;
int d,dfn[N+5],low[N+5],TT,S[N+5];I void Tarjan(CI x=1)
{
	dfn[S[++TT]=x]=low[x]=++d;for(RI i=G[x],y;i;i=G(i).nxt) if(dfn[y=G(i).to]) low[x]=min(low[x],dfn[y]);
		else if(Tarjan(y),low[y]>=dfn[x]) {T.Add(n+(++ct),x);W(T.Add(n+ct,S[TT]),S[TT--]^y);}else low[x]=min(low[x],low[y]);
}
namespace TCD
{
	#define PS 2*N
	int d,dfn[PS+5],fac[PS+5],low[PS+5],f[PS+5],g[PS+5],sz[PS+5],tp[PS+5],D[PS+5];multiset<int> G[PS+5];
	class SegmentTree
	{
		private:
			#define PT CI l=1,CI r=n+ct,CI rt=1
			#define LT l,mid,rt<<1
			#define RT mid+1,r,rt<<1|1
			#define PU(x) (V[x]=min(V[x<<1],V[x<<1|1]))
			int V[PS<<2];
		public:
			I void Bd(PT) {if(l==r) return (void)(V[rt]=fac[l]>n?*G[fac[l]].begin():INF);RI mid=l+r>>1;Bd(LT),Bd(RT),PU(rt);}
			I void U(CI x,CI v,PT) {if(l==r) return (void)(V[rt]=v);RI mid=l+r>>1;x<=mid?U(x,v,LT):U(x,v,RT),PU(rt);}
			I int Q(CI L,CI R,PT) {if(L<=l&&r<=R) return V[rt];RI mid=l+r>>1;return min(L<=mid?Q(L,R,LT):INF,R>mid?Q(L,R,RT):INF);}
	}S;
	I void dfs1(CI x) {sz[x]=1;for(RI i=T[x],y;i;i=T(i).nxt) (y=T(i).to)^f[x]&&(D[y]=D[f[y]=x]+1,dfs1(y),sz[x]+=sz[y],sz[y]>sz[g[x]]&&(g[x]=y));}
	I void dfs2(CI x,CI t) {if(fac[dfn[x]=++d]=x,tp[x]=t,!g[x]) return;dfs2(g[x],t);for(RI i=T[x],y;i;i=T(i).nxt) (y=T(i).to)^f[x]&&y^g[x]&&(dfs2(y,y),0);}
	I void Init() {dfs1(1),dfs2(1,1);for(RI i=1;i<=n;++i) G[f[i]].insert(a[i]);S.Bd();}
	I void U(CI x,CI y) {x^1&&(G[f[x]].erase(G[f[x]].find(a[x])),G[f[x]].insert(y),S.U(dfn[f[x]],*G[f[x]].begin()),0),a[x]=y;}
	I int Q(RI x,RI y)
	{
		RI t=INF;W(tp[x]^tp[y]) D[tp[x]]<D[tp[y]]&&(swap(x,y),0),t=min(t,S.Q(dfn[tp[x]],dfn[x])),x=f[tp[x]];
		D[x]>D[y]&&(swap(x,y),0),t=min(t,S.Q(dfn[x],dfn[y])),x<=n?t=min(t,a[x]):t=min(t,a[f[x]]);return t;
	}
}
int main()
{
	RI Qt,i;for(scanf("%d%d%d",&n,&m,&Qt),i=1;i<=n;++i) scanf("%d",a+i);
	RI x,y;for(i=1;i<=m;++i) scanf("%d%d",&x,&y),G.Add(x,y);Tarjan(),TCD::Init();
	char op;W(Qt--) cin>>op,scanf("%d%d",&x,&y),op=='C'?(TCD::U(x,y),0):printf("%d\n",TCD::Q(x,y));return 0;
}