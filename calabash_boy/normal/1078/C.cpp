#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N=3e5+7,mod=998244353;
vector<int>G[N];
int n,f[N][3],g[3];
void dfs(int u,int fa)
{
	f[u][0]=1;
	for(int v:G[u])
	if(v!=fa)
	{
		dfs(v,u);
		g[0]=1ll*f[u][0]*(f[v][0]+f[v][2])%mod;
		g[1]=(1ll*f[u][0]*f[v][2]+(f[v][0]+2ll*f[v][2])*f[u][1])%mod;
		g[2]=(1ll*(f[u][0]+f[u][1])*(f[v][0]+f[v][1])+(f[v][0]+2ll*f[v][2])*f[u][2])%mod;
		memcpy(f[u],g,sizeof g);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	dfs(1,0);
	printf("%d",(f[1][0]+f[1][2])%mod);
}