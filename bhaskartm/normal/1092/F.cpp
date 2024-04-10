#include<bits/stdc++.h>
using namespace std;

long long int val[200005];
vector<vector<int>>adj;
long long int sub[200005];
long long int dp[200005];
long long int ans;
void dfs(int v, int p){
	sub[v]=val[v];
	for(auto u:adj[v]){
		if(u!=p){
			dfs(u, v);
			sub[v]=sub[v]+sub[u];
			dp[v]=dp[v]+dp[u]+sub[u];
		}
	}
}

void dfs2(int v, int p){
	for(auto u:adj[v]){
		if(u!=p){
			dp[v]=dp[v]-dp[u]-sub[u];
			sub[v]=sub[v]-sub[u];
			sub[u]=sub[u]+sub[v];
			dp[u]=dp[u]+dp[v]+sub[v];
			ans=max(ans, dp[u]);
			dfs2(u, v);
			dp[u]=dp[u]-dp[v]-sub[v];
			sub[u]=sub[u]-sub[v];
			sub[v]=sub[v]+sub[u];
			dp[v]=dp[v]+dp[u]+sub[u];
		}
	}
}

int main() {
	int n;
	cin>>n;
	adj.resize(n+1);
	for(int i=1; i<=n; i++){
		cin>>val[i];
	}
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);

	ans=dp[1];
	dfs2(1, 0);
	cout<<ans<<endl;
	return 0;
}