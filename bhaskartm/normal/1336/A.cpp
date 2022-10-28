#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=2e5+5;

int n, k;
vector<vector<int>>adj;
int d[N];
int sz[N];

void dfs(int v, int p, int h){
	d[v]=h;
	sz[v]=1;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v, h+1);
		
		sz[v]+=sz[u];
	}
}


 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	adj.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0, 1);
	int ans=0;
	vector<int>vec;
	for(int i=1; i<=n; i++){
		vec.pb(d[i]-sz[i]);
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	for(int i=0; i<k; i++){
		ans+=vec[i];
	}
	cout<<ans;
	return 0;
}