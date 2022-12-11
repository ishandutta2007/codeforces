#include<bits/stdc++.h>
#define MaxN 200123
typedef long long LL;
int n,k;
std::vector<int>G[MaxN];
inline void Init()
{
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}
int dep[MaxN],size[MaxN];
std::vector<LL>a;
inline void Dfs(int u,int f)
{
	dep[u]=dep[f]+1;size[u]=1;
	for(auto v:G[u])
	if(v!=f)
	{
		Dfs(v,u);
		size[u]+=size[v];
	}
	a.push_back((LL)(dep[u]-size[u]));
}
inline void Solve()
{
	Dfs(1,0);
	std::sort(a.begin(),a.end());
	std::reverse(a.begin(),a.end());
	printf("%lld\n",std::accumulate(a.begin(),a.begin()+k,0LL));
}
int main()
{
	Init();
	Solve();
	return 0;
}