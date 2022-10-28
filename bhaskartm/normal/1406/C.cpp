#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
vector<vector<int>>adj;
int n;
int sz[100005];
int maxi[100005];

void dfs(int v, int p){
	sz[v]=1;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v);
		sz[v]+=sz[u];
	}
}

void dfs2(int v, int p){
	int s1=0;
	maxi[v]=0;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		s1+=sz[u];
		maxi[v]=max(maxi[v], sz[u]);
	}
	maxi[v]=max(maxi[v], n-s1-1);
	for(auto u:adj[v]){
		if(u!=p){
			dfs2(u, v);
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
		vector<pair<int, int>>ed;
		for(int i=0; i<n-1; i++){
			int u, v;
			cin>>u>>v;
			ed.pb({u, v});
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1, 1);
		dfs2(1, 1);
		vector<int>ind;
		int mini=1e18;
		for(int i=1; i<=n; i++){
			mini=min(mini, maxi[i]);
		}
		for(int i=1; i<=n; i++){
			if(maxi[i]==mini){
				ind.pb(i);
			}
		}
		if(ind.size()==1){
			cout<<ed[0].f<<" "<<ed[0].s<<endl;
			cout<<ed[0].f<<" "<<ed[0].s<<endl;
			continue;
		}
		int ver;
		for(auto u:adj[ind[1]]){
			if(u!=ind[0]){
				ver=u;
				break;
			}
		}
		cout<<ind[1]<<" "<<ver<<endl;
		cout<<ind[0]<<" "<<ver<<endl;
	}
	return 0;
}