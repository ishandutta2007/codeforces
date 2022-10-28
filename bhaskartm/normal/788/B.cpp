#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
bool visited[1000005];
bool booly[1000005];
long long int cnter1=0;
long long int cnter2=0;
int e=0;
void dfs(int v){
	visited[v]=true;
	for(auto u:adj[v]){
		if(!visited[u]){
			e++;
			dfs(u);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		if(u==v){
			booly[u]=true;
			cnter1++;
			continue;
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
		cnter2++;
	}
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(adj[i].size()==0 && booly[i]==false){
			continue;
		}
		if(!visited[i]){
			cnt++;
			dfs(i);
		}
	}
	if(cnt>1){
		cout<<0;
		return 0;
	}
	long long int ans=0;
	for(int i=1; i<=n; i++){
		long long int x=adj[i].size();
		ans=ans+((x*(x-1))/2);
	}
	ans+=((cnter1)*cnter2);
	ans+=((cnter1*(cnter1-1))/2);
	cout<<ans;
	return 0;
}