#include<bits/stdc++.h>
#define MaxN 100123
int n,rt;
std::vector<int>G[MaxN];
int deg[MaxN],fa[MaxN],dis[MaxN];
inline void Init()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		++deg[u];++deg[v];
		G[u].push_back(v);G[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
	if(deg[i]>1)rt=i;
}
inline void Dfs(int u,int f)
{
	fa[u]=f;
	if(u!=rt)dis[u]=dis[f]+1;
	for(auto v:G[u])
	if(v!=f)Dfs(v,u);
}
inline void Solve()
{
	Dfs(rt,0);
	int ans1=0,ans2=n-1;
	for(int u=1;u<=n;++u)
	{
		int leaf_son=0;
		for(auto v:G[u])
		if(v!=fa[u]&&deg[v]==1)++leaf_son;
		if(leaf_son>1)ans2-=(leaf_son-1);
	}
	std::vector<int>leaf;
	for(int i=1;i<=n;++i)
	if(deg[i]==1)leaf.push_back(i);
	int even=0,odd=0;
	for(auto u:leaf)
	if(dis[u]%2==0)even=1;
	else odd=1;
	ans1=(even+odd<2?1:3);
	printf("%d %d\n",ans1,ans2);
}
int main()
{
	Init();
	Solve();
	return 0;
}