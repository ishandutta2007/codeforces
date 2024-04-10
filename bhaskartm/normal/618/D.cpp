#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
vector<vector<int>>adj;
int deg[200005];
bool pos[200005];
int ans=0;

void dfs(int v, int p){
	
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v);
	}
	int cnt=0;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		if(pos[u]){
			cnt++;
		}
	}

	if(cnt<2){
		ans+=cnt;
		pos[v]=1;
	}
	else{
		ans+=2;
		pos[v]=0;
	}
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x, y;
	cin>>n>>x>>y;
	adj.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int maxi=0;
	for(int i=1; i<=n; i++){
		maxi=max(maxi, deg[i]);
	}
	if(x>=y && maxi!=(n-1)){
		cout<<y*(n-1);
		return 0;
	}
	if(x>=y){
		cout<<x+(n-2)*y;
		return 0;
	}
	dfs(1, 1);
	
	cout<<ans*x+(n-1-ans)*y;
	return 0;
}