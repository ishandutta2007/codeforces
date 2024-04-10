#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
#define pb push_back
vector<vector<pair<int, pair<int, int>>>>adj;
vector<int>order;
bool booly;
int ans;
int vis[100005];
int ind[100005];
int n, m;
int color[100005];
void dfs(int v, int val){
	vis[v]=1;
	color[v]=1;
	for(auto u:adj[v]){
		if(u.s.f<=val){
			continue;
		}
		if(vis[u.f]==1){
			if(color[u.f]==1){
				
				booly=true;
			}
			continue;
		}
		
		dfs(u.f, val);
	}
	color[v]=2;
}



void dfs2(int v){
	vis[v]=1;
	for(auto u:adj[v]){
		
		if(vis[u.f]==1 || u.s.f<=ans){
			continue;
		}
		
		dfs2(u.f);
	}
	order.pb(v);
	ind[v]=(order.size());
}

main() {
	
	cin>>n>>m;
	adj.resize(n+1);
	vector<pair<pair<int, int>, pair<int, int>>>edge;
	for(int i=1; i<=m; i++){
		int u,v, w;
		cin>>u>>v>>w;
		adj[u].pb({{v}, {w, i}});
		edge.pb({{u, v}, {w, i}});
	}
	int lo=0;
	int hi=1000000000;
	
	while(lo<=hi){
		int mid=(lo+hi)/2;
		booly=false;
		for(int i=1; i<=n; i++){
			vis[i]=0;
			color[i]=0;
		}
		
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				dfs(i, mid);
			}
		}
		
		if(!booly){
			ans=mid;
			hi=mid-1;
		}
		else{
			
			lo=mid+1;
		}
	}
	for(int i=1; i<=n; i++){
		vis[i]=0;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			
			dfs2(i);
		}
	}
	vector<int>fin;
	
	for(auto u:edge){
		if(u.s.f>ans){
			continue;
		}
		
		if(ind[u.f.f]<ind[u.f.s]){
			fin.pb(u.s.s);
		}
	}
	cout<<ans<<" "<<fin.size()<<endl;
	for(auto u:fin){
		cout<<u<<" ";
	}
	return 0;
}