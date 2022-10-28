#include <bits/stdc++.h>
using namespace std;
int n;
int y;
vector<vector<int>>adj;
vector<pair<int, int>>vec;
vector<pair<int, pair<int, int>>>q;
int val[5005][5005];
bool boolum;
bool dfs(int u, int v, int p, int w){
	
	if(u==v){
		return true;
	}
	for(auto node: adj[u]){
		
		if(node!=p){
			
			if(dfs(node, v, u, w)){
				
				if(val[node][u]==0 || val[node][u]==w){
					
					boolum=true;
				}
				if(val[node][u]==0){
					
					val[node][u]=w;
					val[u][node]=w;
				}
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin>>n;
	adj.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		vec.push_back({u, v});
	}
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		q.push_back({w, {u, v}});
	}
	sort(q.begin(), q.end());
	reverse(q.begin(), q.end());
	for(int i=0; i<m; i++){
		int u=q[i].second.first;
		int v=q[i].second.second;
		int w=q[i].first;
		bool booly;
		boolum=false;
		
		booly=dfs(u, v, u, w);
		
		if(boolum==false){
			
			cout<<-1;
			return 0;
		}
	}
	for(int i=0;i<n-1; i++){
		int x=val[vec[i].first][vec[i].second];
		if(x==0){
			x=pow(10, 6);
		}
		cout<<x<<" ";
	}
	
	return 0;
}