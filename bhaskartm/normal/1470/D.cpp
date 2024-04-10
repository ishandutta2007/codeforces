#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
vector<vector<int>>adj;
int cnt=0;
bool vis[300005];
bool pre[300005];
void dfs(int v){
	cnt++;
	vis[v]=1;
	for(auto u:adj[v]){
		if(vis[u]==0){
			dfs(u);
		}
	}
}

vector<int>ans;
void dfs2(int v){
	vis[v]=1;
	bool che=1;
	for(auto u:adj[v]){
		if(pre[u]){
			che=0;
			break;
		}
	}
	if(che){
		pre[v]=1;
		ans.pb(v);
	}
	for(auto u:adj[v]){
		if(vis[u]==0){
			dfs2(u);
		}
	}
	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		ans.clear();
		for(int i=1; i<=n; i++){
			vis[i]=0;
			pre[i]=0;
		}
		cnt=0;
		adj.clear();
		adj.resize(n+1);
		for(int i=0; i<m; i++){
			int u, v;
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1);
		if(cnt!=n){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i=1; i<=n; i++){
			vis[i]=0;
		}
		dfs2(1);
		cout<<ans.size()<<endl;
		for(auto u:ans){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	return 0;
}