#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
bool booly;
int color[5005];

void dfs(int v){
	
	color[v]=2;
	for(auto u:adj[v]){
		if(color[u]==1){
			continue;
		}
		if(color[u]==2){
			booly=true;
			continue;
		}
		dfs(u);
	}
	color[v]=1;
}

int main() {
	int n, m;
	booly=false;
	cin>>n>>m;
	adj.resize(n+1);
	vector<pair<int, int>>vec;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		vec.push_back({u, v});
		adj[u].push_back(v);
		
	}
	for(int i=1; i<=n; i++){
		if(color[i]==0){
			dfs(i);
		}
	}
	if(booly==false){
		cout<<1<<endl;
		for(int i=0; i<m; i++){
			cout<<1<<" ";
		}
		return 0;
	}
	cout<<2<<endl;
	for(int i=0; i<m; i++){
		if(vec[i].first>vec[i].second){
			cout<<1<<" ";
		}
		else{
			cout<<2<<" ";
		}
	}
	return 0;
}