#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
int a[200005];
vector<vector<vector<int>>>dp;
vector<vector<int>>adj;
int n;
void dfs(int v, int p){
	if(v!=1 && adj[v].size()==1){
		
		dp[v][0][0]=0;
		dp[v][0][1]=a[v];
	}
	else{
	int pointer=1;
	dp[v][0][1]=-pow(10, 18);
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v);
		
		dp[v][pointer][0]=max(dp[v][pointer-1][0]+dp[u][dp[u].size()-1][0], dp[v][pointer-1][1]+dp[u][dp[u].size()-1][1]);
		dp[v][pointer][1]=max(dp[v][pointer-1][1]+dp[u][dp[u].size()-1][0], dp[v][pointer-1][0]+dp[u][dp[u].size()-1][1]);
		pointer++;
	}
	
	dp[v][dp[v].size()-1][1]=max(dp[v][dp[v].size()-1][1], a[v]+dp[v][dp[v].size()-1][0]);
	}
}
main() {
	cin>>n;
	adj.resize(n+1);
	for(int i=1; i<=n; i++){
		int p, val;
		cin>>p>>val;
		if(p!=-1){
			adj[i].pb(p);
			adj[p].pb(i);
		}
		a[i]=val;
	}
	dp.resize(n+1);
	for(int i=1; i<=n; i++){
		if(i==1){
			dp[1].resize(adj[1].size()+1);
		}
		else{
			dp[i].resize(adj[i].size());
		}
		for(int j=0; j<dp[i].size(); j++){
			dp[i][j].resize(2);
		}
	}
	dfs(1, 0);
	
	cout<<max(dp[1][dp[1].size()-1][0], dp[1][dp[1].size()-1][1])<<endl;
	return 0;
}