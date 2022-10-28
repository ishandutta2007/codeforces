#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
vector<vector<int>>adj;
vector<vector<int>>num;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	num.resize(n+1);
	vector<pair<int, int>>ed;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		ed.pb({u, v});
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int arr[n+1];
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		num[arr[i]].pb(i);
		
	}
	bool booly=true;
	for(auto u:ed){
		if(arr[u.f]==arr[u.s]){
			booly=false;
		}
	}
	for(int i=1; i<=n; i++){
		int val=arr[i];
		set<int>se;
		for(auto u:adj[i]){
			if(arr[u]<val){
				se.insert(arr[u]);
			}
		}
		if(se.size()!=val-1){
			booly=false;
		}
	}
	if(booly==false){
		cout<<-1;
		return 0;
	}
	for(auto u:num){
		for(auto v:u){
			cout<<v<<" ";
		}
	}
	return 0;
}