#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+7;
vector<int> G[maxn];
int far[maxn][20];
int st[maxn],ed[maxn];
int tot=0;
int dep[maxn];
void dfs(int u,int fa)
{
	if(fa)
	{
		far[u][0]=fa;
		for(int i=1;i<20;i++)
			far[u][i]=far[far[u][i-1]][i-1];
	}
	st[u]=++tot;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
	ed[u]=tot;
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int j=20-1;j>=0;j--)
	{
		if(dep[far[u][j]]>=dep[v])
			u=far[u][j];
	}
	if(u==v) return u;
	for(int j=20-1;j>=0;j--)
	{
		if(far[u][j]!=far[v][j])
		{
			u=far[u][j];
			v=far[v][j];
		}
	}
	return far[u][0];
}
int tree[maxn];
void add(int x,int val)
{
	while(x<maxn)
	{
		tree[x]+=val;
		x+=x&-x;
	}
}
int query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
int arr[maxn];
long long dp[305];
int ndep[maxn];
map<int,int> mark;
int main()
{
	memset(far,0,sizeof(far));
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0,u,v;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dep[1]=1;
	dfs(1,0);
	while(q--)
	{
		int k,m,r;
		mark.clear();
		scanf("%d%d%d",&k,&m,&r);
		for(int i=1;i<=k;i++) 
		{
			scanf("%d",&arr[i]);
			mark[arr[i]]=1;
			add(st[arr[i]],1);
			add(ed[arr[i]]+1,-1);
		}
		for(int i=1;i<=k;i++)
		{
			int hhh=lca(arr[i],r);
			ndep[i]=query(st[arr[i]])+query(st[r])-2*query(st[hhh])+mark[hhh]-1;
		}
		sort(ndep+1,ndep+k+1);
		dp[0]=1;
		for(int i=1;i<=k;i++)
		{
			for(int j=min(i,m);j>=0;j--)
			{
				if(j<=ndep[i]) dp[j]=0;
				else dp[j]=(dp[j]*(j-ndep[i])%mod+dp[j-1])%mod;
			}
		}
		long long ans=0;
		for(int i=1;i<=m;i++) ans=(ans+dp[i])%mod;
		printf("%lld\n",ans);
		for(int i=1;i<=k;i++)
		{
			add(st[arr[i]],-1);
			add(ed[arr[i]]+1,1);
		}
		for(int i=0;i<=m;i++)
				dp[i]=0;
	}
}