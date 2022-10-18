#include<bits/stdc++.h>

using namespace std;

const int maxn=200006;

int n; 
vector<int> adj[maxn];
int sze[maxn];
long long dp[maxn],dp2[maxn];
long long ans=0;
void dfs1(int u){
	sze[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!sze[v]){
			dfs1(v);
			sze[u]+=sze[v];
			dp[u]+=dp[v];
		} 
	}
	dp[u]+=sze[u];
}

void dfs2(int u){
	ans=max(ans,dp2[u]);
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!dp2[v]){
			dp2[v]=dp2[u]+(n-sze[v])-sze[v];
			dfs2(v);
		} 
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u); 
	}
	dfs1(1);
	dp2[1]=dp[1];
	dfs2(1);
	cout<<ans;
	return 0;
}