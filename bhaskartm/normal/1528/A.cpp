#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;

int n;
int dp[N][2];
vector<vector<int>>adj;
int l[N];
int r[N];

void dfs(int v, int p){
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v);
	}
	dp[v][0]=0;
	dp[v][1]=0;
	for(auto u:adj[v]){
		if(u!=p){
			dp[v][0]+=max(dp[u][0]+abs(l[v]-l[u]), dp[u][1]+abs(l[v]-r[u]));
			dp[v][1]+=max(dp[u][0]+abs(r[v]-l[u]), dp[u][1]+abs(r[v]-r[u]));
		}
	}
}

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		adj.clear();
		adj.resize(n+1);
		for(int i=1; i<=n; i++){
			cin>>l[i]>>r[i];
		}
		for(int i=1; i<=n-1; i++){
			int u, v;
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1, 0);
		cout<<max(dp[1][0], dp[1][1])<<endl;
	}
	return 0;
}