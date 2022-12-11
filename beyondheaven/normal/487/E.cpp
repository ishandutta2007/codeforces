#include<bits/stdc++.h>
#define MaxN 200123

int n,m,q,tot;
std::vector<int>A[MaxN],G[MaxN];
std::multiset<int>s[MaxN];
int w[MaxN],stk[MaxN],dfn[MaxN],low[MaxN];
int fa[MaxN],son[MaxN],size[MaxN],dep[MaxN],top[MaxN],rev[MaxN];

#define Mid ((L+R)>>1)
int minv[MaxN<<2];
inline void Build(int k=1,int L=1,int R=tot)
{
	if(L==R)
	{
		minv[k]=w[rev[L]];
		return;
	}
	Build(k<<1,L,Mid);Build(k<<1|1,Mid+1,R);
	minv[k]=std::min(minv[k<<1],minv[k<<1|1]);
}
inline void Modify(int l,int v,int k=1,int L=1,int R=tot)
{
	if(L==R)
	{
		minv[k]=v;
		return;
	}
	if(l<=Mid)Modify(l,v,k<<1,L,Mid);
	else Modify(l,v,k<<1|1,Mid+1,R);
	minv[k]=std::min(minv[k<<1],minv[k<<1|1]);
}
inline int Query(int l,int r,int k=1,int L=1,int R=tot)
{
	if(l<=L&&R<=r)return minv[k];
	int res=INT_MAX;
	if(l<=Mid)res=std::min(res,Query(l,r,k<<1,L,Mid));
	if(Mid<r)res=std::min(res,Query(l,r,k<<1|1,Mid+1,R));
	return res;
}
#undef Mid

int main()
{
	scanf("%d%d%d",&n,&m,&q);tot=n;
	for(int i=1;i<=n;++i)scanf("%d",w+i);
	
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		A[u].push_back(v);
		A[v].push_back(u);
	}
	
	auto AddEdge=[](int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	};
	
	std::function<void(int)>Tarjan=[&](int u)
	{
		static int dfs_clock=0,tp=0;
		low[u]=dfn[u]=++dfs_clock;
		stk[++tp]=u;
		for(int v:A[u])
		if(!dfn[v])
		{
			Tarjan(v);
			low[u]=std::min(low[u],low[v]);
			if(low[v]==dfn[u])
			{
				AddEdge(++tot,u);
				for(int x=0;x!=v;AddEdge(tot,(x=stk[tp--])));
			}
		}
		else low[u]=std::min(low[u],dfn[v]);
	};
	
	Tarjan(1);
	
	std::function<void(int,int)>Dfs1=[&](int u,int f)
	{
		fa[u]=f;size[u]=1;dep[u]=dep[f]+1;
		for(int v:G[u])
		if(v!=f)
		{
			Dfs1(v,u);
			size[u]+=size[v];
			if(size[v]>size[son[u]])son[u]=v;
		}
	};
	
	std::function<void(int,int)>Dfs2=[&](int u,int tp)
	{
		static int dfs_clock=0;
		dfn[u]=++dfs_clock;rev[dfs_clock]=u;
		top[u]=tp;
		if(son[u])Dfs2(son[u],tp);
		for(int v:G[u])
		if(!top[v])Dfs2(v,v);
	};
	
	Dfs1(1,0);
	Dfs2(1,1);
	
	for(int i=1;i<=n;++i)
	if(fa[i]>n)s[fa[i]].insert(w[i]);
	for(int i=n+1;i<=tot;++i)w[i]=(*s[i].begin());
	
	Build();
	
	auto Lca=[](int u,int v)
	{
		while(top[u]!=top[v])
		{
			if(dep[top[u]]>dep[top[v]])u=fa[top[u]];
			else v=fa[top[v]];
		}
		return dep[u]<dep[v]?u:v;
	};
	
	auto ChainQuery=[&](int u,int v)
	{
		int res=(Lca(u,v)>n?w[fa[Lca(u,v)]]:INT_MAX);
		while(top[u]!=top[v])
		{
			if(dep[top[u]]<dep[top[v]])std::swap(u,v);
			res=std::min(res,Query(dfn[top[u]],dfn[u]));
			u=fa[top[u]];
		}
		if(dep[u]>dep[v])std::swap(u,v);
		res=std::min(res,Query(dfn[u],dfn[v]));
		return res;
	};
	
	for(int i=1,a,b;i<=q;++i)
	{
		char op=getchar();
		while(!isalpha(op))op=getchar();
		scanf("%d%d",&a,&b);
		
		if(op=='A')
		printf("%d\n",ChainQuery(a,b));
		else
		{
			Modify(dfn[a],b);
			if(fa[a]>n)
			{
				s[fa[a]].erase(w[a]);
				s[fa[a]].insert(b);
				w[fa[a]]=(*s[fa[a]].begin());
				Modify(dfn[fa[a]],w[fa[a]]);
			}
			w[a]=b;
		}
	}
	
	return 0;
}