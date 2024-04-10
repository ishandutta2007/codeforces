#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
struct node{
	int to;
	long long v;
};
vector<int> G[maxn];
int val[maxn];
int dep[maxn];
long long dp[maxn];
vector<node> son[maxn];
long long ans=0;
long long dfs(int u,int fa)
{
	long long ret=val[u];
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		long long temp=dfs(v,u);
		son[u].push_back(node {v,temp});
		ret+=temp;
	}
	return ret;
}
long long tot=0;
void dfs2(int u)
{
	for(int i=0;i<son[u].size();i++)
	{
		int v=son[u][i].to;
		dp[v]=dp[u]-son[u][i].v*2+tot;
		ans=max(ans,dp[v]);
		dfs2(v);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
		tot+=val[i];
	}
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dep[1]=0;
	dfs(1,-1);
	for(int i=1;i<=n;i++)
	{
		ans+=1LL*dep[i]*val[i];
	}
	dp[1]=ans;
	dfs2(1);
	printf("%lld\n",ans);
}