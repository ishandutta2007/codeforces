#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>vec;
bool booly;
vector<int>path;
vector<int>ans;
vector<int>temp;
bool dfs(int u, int v, int p){
	if(u==v){
		return true;
	}
	for(auto node:adj[u]){
		if(node==p){
			continue;
		}
		if(dfs(node, v, u)){
			temp.push_back(node);
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin>>n;
	adj.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int k=0;
	int x;
	while(cin>>x){
		k++;
		vec.push_back(x);
	}
	ans.push_back(1);
	booly=dfs(1, vec[0], 0);
	reverse(temp.begin(), temp.end());
	for(auto u:temp){
		ans.push_back(u);
	}
	temp.clear();
	for(int i=0; i<vec.size()-1; i++){
	
		booly=dfs(vec[i], vec[i+1], 0);
		reverse(temp.begin(), temp.end());
	for(auto u:temp){
		ans.push_back(u);
	}
	temp.clear();
	}
	
	booly=dfs(vec[vec.size()-1], 1, 0);
	reverse(temp.begin(), temp.end());
	for(auto u:temp){
		ans.push_back(u);
	}
	temp.clear();
	
	if(ans.size()!=2*n-1){
		cout<<-1;
		return 0;
	}
	for(auto u:ans){
		cout<<u<<" ";
	}
	return 0;
}