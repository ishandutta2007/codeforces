#include<bits/stdc++.h>
#define MaxN 100123
int n,m;
std::vector<int>G[MaxN];
std::vector<int>F[MaxN];

struct Query
{
	int k,id,save;
	Query(int _k=0,int _id=0):
		k(_k),id(_id),save(0){}
};
std::vector<Query>q[MaxN];
int dep[MaxN],ans[MaxN];

inline void Dfs1(int u,int f)
{
	if(f)
	{
		dep[u]=dep[f]+1;
		F[u].emplace_back(f);
		for(std::size_t i=1u;i<=20u;++i)
		if(F[F[u][i-1]].size()>=i)
		F[u].emplace_back(F[F[u][i-1]][i-1]);
		else break;
	}
	
	for(int v:G[u])Dfs1(v,u);
}
inline int Kfa(int u,int k)
{
	for(int i=20;~i;--i)
	if((k>>i)&1)u=F[u][i];
	return u;
}

inline void Init()
{
	scanf("%d",&n);
	for(int i=1,f;i<=n;++i)
	{
		scanf("%d",&f);
		G[f].emplace_back(i);
	}
	for(int u:G[0])Dfs1(u,0);
	scanf("%d",&m);
	for(int i=1,v,p;i<=m;++i)
	{
		scanf("%d%d",&v,&p);
		if(p<=dep[v])
		q[Kfa(v,p)].emplace_back(Query(dep[v],i));
	}
}

int cnt[MaxN];

inline void Dfs2(int u)
{
	for(auto&p:q[u])
	p.save=cnt[p.k];
	
	++cnt[dep[u]];
	for(int v:G[u])Dfs2(v);
	
	for(auto&p:q[u])
	ans[p.id]=cnt[p.k]-p.save-1;
}

int main()
{
	Init();
	for(int u:G[0])Dfs2(u);
	for(int i=1;i<=m;++i)
	printf("%d%c",ans[i]," \n"[i==m]);
	return 0;
}