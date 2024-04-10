#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
const int mod=998244353;
int n,m;
int dp[N][N],dep[N];
int tmp[N];
vector<int> g[N];
void dfs(int u,int last){
	dp[u][0]=1;
	int i,j;
	for(auto v:g[u]){
		if(v==last) continue;
		dfs(v,u);
		for(i=dep[v]+1;i;i--) dp[v][i]=dp[v][i-1];
		dp[v][0]=0;
		for(i=1;i<=dep[v]+1;i++) dp[v][0]=(dp[v][0]+dp[v][i])%mod;
		for(i=0;i<=max(dep[u],dep[v]+1);i++) tmp[i]=0;
		for(i=0;i<=dep[u];i++){
			for(j=0;j<=dep[v]+1&&i+j<=m;j++)
				tmp[max(i,j)]=(tmp[max(i,j)]+1ll*dp[u][i]*dp[v][j])%mod;
		}
		dep[u]=max(dep[u],dep[v]+1);
		for(i=0;i<=dep[u];i++) dp[u][i]=tmp[i];
	}
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	int ans=0;
	for(i=0;i<=m;i++) ans=(ans+dp[1][i])%mod;
	cout<<ans;
	return 0;
}