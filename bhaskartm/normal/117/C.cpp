#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>path;
vector<int>cycle;
int color[5005];
bool booly;
void dfs(int v){
	
	color[v]=1;
	path.push_back(v);
	for(auto u:adj[v]){
		
		if(color[u]==0){
			dfs(u);
		}
		if(color[u]==2){
			continue;
		}
		if(color[u]==1 && booly==false){
			booly=true;
			
			int pointer=path.size();
			while(path[pointer-1]!=u){
				cycle.push_back(path[pointer-1]);
				pointer--;
			}
			cycle.push_back(path[pointer-1]);
		}
	}
	path.pop_back();
	color[v]=2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	adj.resize(n+1);
	booly=false;
	
	int arr[n+1][n+1];
	for(int i=1; i<=n; i++){
		string s;
		cin>>s;
		for(int j=1; j<=s.size(); j++){
			if(s[j-1]=='1'){
				adj[i].push_back(j);
				arr[i][j]=1;
			}
			else{
				arr[i][j]=0;
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(color[i]==0){
			dfs(i);
		}
	}
	
	
	if(booly==false){
		cout<<-1;
		return 0;
	}
	
	reverse(cycle.begin(), cycle.end());

	while(cycle.size()>3){
		if(arr[cycle[0]][cycle[cycle.size()-2]]==1){
			
			cout<<cycle[0]<<" "<<cycle[cycle.size()-2]<<" "<<cycle[cycle.size()-1];
			return 0;
		}
		else{
			cycle.pop_back();
		}
	}
	cout<<cycle[0]<<" "<<cycle[1]<<" "<<cycle[2];
	return 0;
}