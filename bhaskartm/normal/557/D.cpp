#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
bool vis[300005];
int cnt;
int zero;
int one;
int col[300005];
vector<vector<int>>adj;
bool booly;
void dfs2(int v, int color){
	col[v]=color;
	if(color==0){
		zero++;
	}
	else{
		one++;
	}
	vis[v]=1;
	for(auto u:adj[v]){
		if(vis[u] && col[u]==col[v]){
			booly=1;
		}
		if(!vis[u]){
			dfs2(u, 1-color);
		}
	}
}
void dfs(int v){
	vis[v]=1;
	cnt++;
	for(auto u:adj[v]){
		if(vis[u]){
			continue;
		}
		dfs(u);
	}
}

 main() {
	set<pair<int, int>>se;
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=1; i<=n; i++){
		cnt=0;
		if(!vis[i]){
			dfs(i);
			se.insert({cnt, i});
		}
	}
	auto it=se.end();
	it--;
	if((*it).f==1){
		cout<<3<<" "<<(n*(n-1)*(n-2))/6;
		return 0;
	}
	if((*it).f==2){
		int sz1=0;
		int sz2=0;
		for(auto it=se.begin(); it!=se.end(); it++){
			if((*it).f==1){
				sz1++;
			}
			else{
				sz2++;
			}
		}
		cout<<2<<" "<<sz2*(n-2)<<endl;
		return 0;
	}
	
	for(int i=1; i<=n; i++){
		vis[i]=0;
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		if(vis[i]){
			continue;
		}
		zero=0;
		one=0;
		dfs2(i, 0);
		ans+=((zero*(zero-1))+(one*(one-1)))/2;
		
	}
	if(booly){
		cout<<0<<" "<<1;
		return 0;
	}
	else{
		cout<<1<<" "<<ans;
	}
	return 0;
}