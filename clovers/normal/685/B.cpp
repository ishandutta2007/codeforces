#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define mk make_pair
const int N=400005;
int n,dp[N],sz[N],f[N],mx[N],son[N]; 
vector<int> v[N];

int calc(int x,int F)
{
	return max(mx[x],sz[F]-sz[x]);
}

void dfs(int u)
{
	dp[u]=u;
	sz[u]=1; mx[u]=0;
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		f[to]=u;
		dfs(to);
		sz[u]+=sz[to];
		if(sz[to]>mx[u]) mx[u]=sz[to],son[u]=to;
	}
	if(son[u]==-1) return;
	int now=dp[son[u]];
	while(now!=u&&(sz[u]-sz[now])*2>sz[u]) now=f[now];
	dp[u]=now; 
}

int main()
{
	int m;
	memset(son,-1,sizeof(son));
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
	{
		int x; int y;
		scanf("%d",&x);
		v[x].push_back(i);
	}
	f[1]=0;
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",dp[x]);
	}
	return 0;
}