#include<bits/stdc++.h>
#define MaxN 200123
int n,m;
std::vector<int>G[MaxN];
int qv[MaxN];
inline void Init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);G[v].push_back(u);
	}
}
int dfn[MaxN],size[MaxN],fa[MaxN],dfs_clock;
inline void Dfs(int u,int f)
{
	fa[u]=f;dfn[u]=++dfs_clock;size[u]=1;
	for(auto v:G[u])
	if(v!=f)
	{
		Dfs(v,u);
		size[u]+=size[v];
	}
}
inline void Solve()
{
	std::vector<int>qv;
	for(int i=1,k;i<=m;++i)
	{
		scanf("%d",&k);qv.clear();
		for(int j=1,x;j<=k;++j)
		{
			scanf("%d",&x);
			qv.push_back(fa[x]);
		}
		auto cmp=[](int a,int b){return dfn[a]<dfn[b];};
		std::sort(qv.begin(),qv.end(),cmp);
		bool flag=true;
		for(int j=0;j<k-1;++j)
		if(!(dfn[qv[j]]<=dfn[qv[j+1]]&&dfn[qv[j+1]]<dfn[qv[j]]+size[qv[j]]))
		flag=false;
		if(flag)puts("YES");
		else puts("NO");
	}
}
int main()
{
	Init();
	Dfs(1,1);
	Solve();
	return 0;
}