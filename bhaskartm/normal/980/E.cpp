#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int p[1000005][21];
int d[1000005];
int marked[1000005];
int cnt;
void dfs(int v, int pa, int h){
	p[v][0]=pa;
	d[v]=h;
	for(auto u:adj[v]){
		if(u!=pa){
			dfs(u, v, h+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	adj.resize(n+1);
	
	for(int i=0; i<n-1; i++){
		int u ,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(n, n, 0);
	for(int i=1; i<=20; i++){
		for(int j=1; j<=n; j++){
			p[j][i]=p[p[j][i-1]][i-1];
		}
	}
	marked[n]=1;
	cnt++;
	for(int i=n-1; i>0; i--){
		if(marked[i]){
			continue;
		}
		
		int node=i;
		for(int j=20; j>=0; j--){
			if(marked[p[node][j]]){
				continue;
			}
			node=p[node][j];
		}
		
		if(d[i]-d[node]+1+cnt>n-k){
			continue;
		}
		
		int node2=i;
		marked[i]=1;
		cnt++;
		while(node2!=node){
			node2=p[node2][0];
			marked[node2]=1;
			cnt++;
		}
		
	}
	vector<int>ans;
	for(int i=1; i<=n; i++){
		if(marked[i]==0){
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	for(auto u:ans){
		cout<<u<<" ";
	}
	return 0;
}