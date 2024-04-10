#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define pb push_back
#define f first
#define s second
vector<vector<pair<int, pair<int, int>>>>adj;
int dis[300005];
int vis[300005];
int wt[300005];
pair<int, int> par[300005];
main() {
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	for(int i=1; i<=m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb({v, {w, i}});
		adj[v].pb({u, {w, i}});
		wt[i]=w;
	}
	int x;
	cin>>x;
	for(int i=1; i<=n; i++){
		dis[i]=pow(10, 18);
	}
	dis[x]=0;
	set<pair<int, int>>se;
	se.insert({dis[x], x});
	
	
	while(!se.empty()){
		auto it=se.begin();
		int node=(*it).s;
		se.erase((*it));
		if(vis[node]){
			continue;
		}
		vis[node]=true;
		for(auto u:adj[node]){
			if(vis[u.f]){
				continue;
			}
			if(dis[u.f]>dis[node]+u.s.f){
				dis[u.f]=dis[node]+u.s.f;
				se.insert({dis[u.f], u.f});
				par[u.f]={node, u.s.s};
				continue;
			}
			if(dis[u.f]==dis[node]+u.s.f && u.s.f<wt[par[u.f].s]){
				par[u.f]={node, u.s.s};
			}
		}
	}
	
	vector<int>ans;
	int tw=0;
	for(int i=1; i<=n; i++){
		if(i==x){
			continue;
		}
		tw+=wt[par[i].s];
		ans.pb(par[i].s);
	}
	cout<<tw<<endl;
	sort(ans.begin(), ans.end());
	for(auto g:ans){
		cout<<g<<" ";
	}
	return 0;
}