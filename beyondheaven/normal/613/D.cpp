#include<bits/stdc++.h>
#define MaxN 100123
typedef long long LL;

int n,q;
std::vector<int>G[MaxN],H[MaxN];
int fa[MaxN],son[MaxN],size[MaxN],dep[MaxN],top[MaxN],dfn[MaxN];
int vis[MaxN],stk[MaxN];
LL dp[MaxN][2],ans;

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	std::function<void(int,int)> Dfs1=[&](int u,int f)
	{
		fa[u]=f;size[u]=1;
		dep[u]=dep[f]+1;
		for(int v:G[u])
		if(v!=f)
		{
			Dfs1(v,u);
			size[u]+=size[v];
			if(size[v]>size[son[u]])son[u]=v;
		}
	};
	
	std::function<void(int,int)> Dfs2=[&](int u,int tp)
	{
		static int dfs_clock=0;
		top[u]=tp;dfn[u]=++dfs_clock;
		if(son[u])Dfs2(son[u],tp);
		for(int v:G[u])
		if(!top[v])Dfs2(v,v);
	};
	
	Dfs1(1,0);
	Dfs2(1,1);
	
	auto Lca=[&](int u,int v)
	{
		while(top[u]!=top[v])
		{
			if(dep[top[u]]>dep[top[v]])u=fa[top[u]];
			else v=fa[top[v]];
		}
		return dep[u]<dep[v]?u:v;
	};
	
	scanf("%d",&q);
	for(int i=1,k;i<=q;++i)
	{
		scanf("%d",&k);
		std::vector<int>V={1};
		for(int j=1,x;j<=k;++j)
		scanf("%d",&x),V.push_back(x),vis[x]=1;
		
		auto dfn_sort=[](int x,int y){return dfn[x]<dfn[y];};
		std::sort(V.begin(),V.end(),dfn_sort);
		for(int i=0,t=static_cast<int>(V.size());i+1<t;++i)
		V.push_back(Lca(V[i],V[i+1]));
		
		std::sort(V.begin(),V.end(),dfn_sort);
		V.erase(std::unique(V.begin(),V.end()),V.end());
		
		int tp=0;
		stk[++tp]=1;
		for(int u:V)if(u!=1)
		{
			while(dfn[stk[tp]]+size[stk[tp]]<=dfn[u])--tp;
			H[stk[tp]].push_back(u);
			stk[++tp]=u;
		}
		
		ans=0;
		std::function<void(int)>Dfs=[&](int u)
		{
			for(int v:H[u])Dfs(v);
			if(vis[u])
			{
				for(int v:H[u])
				if(vis[v]&&fa[v]==u)ans=-1;
				else dp[u][0]+=std::min(dp[v][0]+1,dp[v][1]);
				dp[u][1]=0x3f3f3f3f;
			}
			else
			{
				dp[u][0]=0x3f3f3f3f;
				for(int v:H[u])
				dp[u][0]=std::min(dp[u][0],dp[v][0]-dp[v][1]);
				for(int v:H[u])
				dp[u][0]+=dp[v][1];
				
				dp[u][1]=1;
				for(int v:H[u])
				dp[u][1]+=std::min(dp[v][0],dp[v][1]);
				
				LL tmp=0;
				for(int v:H[u])tmp+=dp[v][1];
				dp[u][1]=std::min(dp[u][1],tmp);
			}
		};
		Dfs(1);
		if(ans==-1)puts("-1");
		else printf("%lld\n",std::min(dp[1][0],dp[1][1]));
		
		for(int u:V)vis[u]=0,dp[u][0]=dp[u][1]=0,H[u].clear();
	}
	return 0;
}