#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
vector<vector<int>>adj;
bool booly;
int s[100005];
vector<int>path;
int ans;
void dfs(int v, int p){
	if(s[v]==-1){
		s[v]=pow(10, 10);
		if(adj[v].size()==1){
			s[v]=s[p];
		}
		for(auto u:adj[v]){
			if(u!=p){
				s[v]=min(s[v], s[u]);
			}
		}
	}
	for(auto u:adj[v]){
		if(u!=p){
		dfs(u, v);
		}
	}
}

void dfs2(int v, int p){
	ans+=(s[v]-path[path.size()-1]);
	if(s[v]<path[path.size()-1]){
		booly=false;
	}
	path.pb(s[v]);
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs2(u, v);
	}
	path.pop_back();
}

 main() {
	int n;
	booly=true;
	cin>>n;
	adj.resize(n+1);
	for(int i=2; i<=n; i++){
		int v;
		cin>>v;
		adj[v].pb(i);
		adj[i].pb(v);
	}
	for(int i=1; i<=n; i++){
		cin>>s[i];
	}

	dfs(1, -1);
	
	path.pb(0);
	dfs2(1, -1);
	if(booly==false){
		cout<<-1;
	}
	else{
		cout<<ans;
	}
	return 0;
}