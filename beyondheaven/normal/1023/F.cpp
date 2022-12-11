#include<bits/stdc++.h>
#define MaxN 500123
typedef long long LL;
const int INF=0x3f3f3f3f;
int n,k,m;
struct Edge
{
	int u,v,w;
	Edge(int _u=0,int _v=0,int _w=0):
		u(_u),v(_v),w(_w){}
};
std::vector<Edge>G[MaxN];
std::vector<Edge>F;
int pre[MaxN];
inline int Find(int x){return pre[x]==x?x:pre[x]=Find(pre[x]);}
inline void Init()
{
	scanf("%d%d%d",&n,&k,&m);
	std::iota(pre+1,pre+n+1,1);
	#ifdef Dubug
	printf("pre[1]=%d\n",pre[1]);
	#endif
	for(int i=1,u,v;i<=k;++i)
	{
		scanf("%d%d",&u,&v);
		#ifdef Dubug
		printf("add_edge(%d,%d,%d);\n",u,v,0);
		#endif
		G[u].push_back(Edge(u,v,0));
		G[v].push_back(Edge(v,u,0));
		pre[Find(u)]=Find(v);
	}
	for(int i=1,u,v,w;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		if(Find(u)!=Find(v))
		{
			G[u].push_back(Edge(u,v,w));
			G[v].push_back(Edge(v,u,w));
			#ifdef Dubug
			printf("add_edge(%d,%d,%d);\n",u,v,w);
			#endif
			pre[Find(u)]=Find(v);
		}
		else
		F.push_back(Edge(u,v,w));
	}
}
int val[MaxN],fa[MaxN],son[MaxN];
int dep[MaxN],size[MaxN];
int top[MaxN],dfn[MaxN],rev[MaxN],dfs_clock;
inline void Dfs1(int u,int f,int d)
{
	val[u]=(d?0:INF);fa[u]=f;
	dep[u]=dep[f]+1;size[u]=1;
	for(auto&e:G[u])
	if(e.v!=f)
	{
		Dfs1(e.v,u,e.w);
		size[u]+=size[e.v];
		if(size[e.v]>size[son[u]])
		son[u]=e.v;
	}
}
inline void Dfs2(int u,int tp)
{
	top[u]=tp;dfn[u]=++dfs_clock;rev[dfs_clock]=u;
	if(son[u])Dfs2(son[u],tp);
	for(auto&e:G[u])
	if(!top[e.v])Dfs2(e.v,e.v);
}
#define Mid ((L+R)>>1)
int minv[MaxN<<2],tag[MaxN<<2];
inline void Build(int k=1,int L=1,int R=n)
{
	tag[k]=0x3f3f3f3f;
	if(L==R)
	{
		minv[k]=val[rev[L]];
		return;
	}
	Build(k<<1,L,Mid);Build(k<<1|1,Mid+1,R);
	minv[k]=std::min(minv[k<<1],minv[k<<1|1]);
}
inline void PushDown(int k)
{
	minv[k<<1]=std::min(minv[k<<1],tag[k]);
	minv[k<<1|1]=std::min(minv[k<<1|1],tag[k]);
	tag[k<<1]=std::min(tag[k<<1],tag[k]);
	tag[k<<1|1]=std::min(tag[k<<1|1],tag[k]);
}
inline void Modify(int l,int r,int v,int k=1,int L=1,int R=n)
{
	if(l<=L&&R<=r)
	{
		minv[k]=std::min(minv[k],v);
		tag[k]=std::min(tag[k],v);
		return;
	}
	PushDown(k);
	if(l<=Mid)Modify(l,r,v,k<<1,L,Mid);
	if(Mid<r)Modify(l,r,v,k<<1|1,Mid+1,R);
	minv[k]=std::min(minv[k<<1],minv[k<<1|1]);
}
LL ans[MaxN];
inline void Print(int k=1,int L=1,int R=n)
{
	if(L==R)
	{
		ans[rev[L]]=minv[k];
		return;
	}
	PushDown(k);
	Print(k<<1,L,Mid);Print(k<<1|1,Mid+1,R);
}
#undef Mid
inline void ChainModify(int u,int v,int w)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])std::swap(u,v);
		Modify(dfn[top[u]],dfn[u],w);
		u=fa[top[u]];
	}
	if(u==v)return;
	if(dep[u]>dep[v])std::swap(u,v);
	Modify(dfn[son[u]],dfn[v],w);
}
inline void Solve()
{
	Dfs1(1,0,1);
	Dfs2(1,1);
	Build();
	#ifdef Dubug
	for(int i=2;i<=n;++i)
	printf("val[%d]=%d\n",i,val[i]);
	#endif
	for(auto&e:F)
	ChainModify(e.u,e.v,e.w);
	Print();
	if(std::all_of(ans+2,ans+n+1,[](LL x){return x!=INF;}))
	printf("%lld\n",std::accumulate(ans+2,ans+n+1,0LL));
	else puts("-1");
}
int main()
{
	Init();
	Solve();
	return 0;
}