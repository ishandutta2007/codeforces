#include<bits/stdc++.h>
using namespace std;
vector<set<int>>adj;
int deg[100005];
int isbig[100005];
int tbig[100005];
bool vis[100005];
vector<vector<int>>adj2;
int comp=0;

void dfs(int i){
	vis[i]=true;
	for(int v:adj2[i]){
		if(vis[v]){
			continue;
		}
		dfs(v);
	}
}

int main() {
	int n, m;
	cin>>n>>m;
	
	adj.resize(n+1);
	adj2.resize(n+1);
	for(int i=1; i<=n; i++){
		deg[i]=n-1;
	}
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
		deg[u]--;
		deg[v]--;
	}
	set<int>big;
	set<int>small;
	vector<int>vec;
	for(int i=1; i<=n; i++){
		if(deg[i]>(n/2)){
			big.insert(i);
			isbig[i]=1;
		}
		else{
			small.insert(i);
			vec.push_back(i);
		}
	}
	if(small.size()==0){
		cout<<0;
		return 0;
	}
	
	for(auto j:vec){
		
		for(int i=1; i<=n; i++){
			if(isbig[i]==1 && tbig[j]==0 && adj[j].find(i)==adj[j].end()){
				tbig[j]=1;
				adj2[0].push_back(j);
				adj2[j].push_back(0);
				continue;
			}
			if(isbig[i]==1){
				continue;
			}
			if(adj[i].find(j)==adj[i].end()){
				adj2[i].push_back(j);
				adj2[j].push_back(i);
			}
		}
	}
	
	for(int i=0; i<=n; i++){
		if(i==0 && big.size()==0){
			continue;
		}
		if(isbig[i]==1){
			continue;
		}
		if(!vis[i]){
			comp++;
			dfs(i);
		}
	}
	cout<<comp-1;
	return 0;
}