#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int color[505];
bool b;
int cnt;

void dfs(int v, int con){
	color[v]=1;
	for(auto u:adj[v]){
		if(u==con && color[u]==1){
			cnt++;
			
			continue;
		}
		if(color[u]==1){
			b=1;
		}
		if(color[u]==0){
			dfs(u, con);
		}
	}
	color[v]=2;
}

int main() {
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			color[j]=0;
		}
		cnt=0;
		b=0;
		
		dfs(i, i);
		for(int j=1; j<=n; j++){
			if(color[j]==0 && j!=i){
				dfs(j, i);
			}
		}
		if(b==0 && cnt<=1){
			
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}