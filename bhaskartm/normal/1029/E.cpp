#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int depth[200005];
int parent[200005];
void dfs(int v, int p, int d){
	depth[v]=d;
	parent[v]=p;
	for(auto u:adj[v]){
		if(u!=p){
			dfs(u, v, d+1);
		}
	}
}

int main() {
	set<pair<int, int>>s;
	int n;
	cin>>n;
	adj.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, 0);
	for(int i=1; i<=n; i++){
		if(depth[i]>2){
			s.insert({-depth[i], i});
		}
	}
	
	int ans=0;
	while(!s.empty()){
		auto it=s.begin();
		int node=(*it).second;
		int par=parent[node];
		ans++;
		if(!s.empty() && s.find({-depth[par], par})!=s.end()){
			s.erase({-depth[par], par});
		}
		for(auto u: adj[par]){
			if(!s.empty() && s.find({-depth[u], u})!=s.end()){
				s.erase({-depth[u], u});
			}
		}
	}
	cout<<ans;
	return 0;
}