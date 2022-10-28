#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
vector<vector<int>>adj;
int color[200005];
bool b;
vector<int>order;

void dfs(int v){
	color[v]=1;
	for(auto u:adj[v]){
		if(color[u]==1){
			b=false;
		}
		if(color[u]==0){
			dfs(u);
		}
	}
	order.pb(v);
	color[v]=2;
}

 main() {
	int n, m;
	b=true;
	cin>>n>>m;
	adj.resize(2*n*m+5);
	int ext=m+1;
	for(int j=0; j<n; j++){
		pair<int, int> arr[m];
		bool booly=false;
		for(int i=0; i<m; i++){
			int x;
			cin>>x;
			if(x!=-1){
				booly=true;
			}
			arr[i]={x, i+1};
		}
		if(booly==false){
			continue;
		}
		sort(arr, arr+m);
		map<int, int>ma;
		set<int>se;
		for(int i=0; i<m; i++){
			if(arr[i].f!=-1){
				se.insert(arr[i].f);
			}
		}
		int pointer=0;
		for(auto it=se.begin(); it!=se.end(); it++){
			ma[(*it)]=pointer;
			pointer++;
		}
		for(int i=0; i<m; i++){
			if(arr[i].f!=-1){
				arr[i].f=ma[arr[i].f];
			}
		}
		int maxi=0;
		for(int i=0; i<m; i++){
			maxi=max(maxi, arr[i].f);
		}
		vector<vector<int>>pos;
		pos.resize(maxi+1);
		for(int i=0; i<m; i++){
			if(arr[i].f!=-1){
				pos[arr[i].f].pb(arr[i].s);
			}
		}
		int ext2=ext;
		for(int i=0; i<maxi; i++){
			for(auto u:pos[i]){
				
				adj[u].pb(ext2);
			}
			ext2++;
		}
		for(int i=1; i<=maxi; i++){
			for(auto u:pos[i]){
				
				adj[ext].pb(u);
			}
			ext++;
		}
	}
	for(int i=1; i<=m; i++){
		if(color[i]==0){
			dfs(i);
		}
	}
	if(b==false){
		cout<<-1;
		return 0;
	}
	reverse(order.begin(), order.end());
	
	for(auto u: order){
		if(u>=1 && u<=m){
			cout<<u<<" ";
		}
	}
	return 0;
}