#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define s second
#define f first
vector<vector<pair<pair<int, int>, pair<int, int>>>>adj;
main() {
	int n, m, k;
	cin>>n>>m>>k;
	adj.resize(n+1);
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb({{v, w}, {0, i}});
		adj[v].pb({{u, w}, {0, i}});
	}
	for(int i=m; i<m+k; i++){
		int s, w;
		cin>>s>>w;
		adj[1].pb({{s, w}, {1, i}});
		adj[s].pb({{1, w}, {1, i}});
	}
	set<pair<int, int>>se;
	int d[n+1];
	int pro[n+1];
	pair<int, int>p[n+1];
	for(int i=0; i<=n; i++){
		d[i]=1e18;
		pro[i]=0;
	}
	d[1]=0;
	se.insert({0, 1});
	while(!se.empty()){
		auto it=se.begin();
		int v=(*it).s;
		int dis=((*it)).f;
		if(pro[v]){
			se.erase((*it));
			continue;
		}
		pro[v]=1;
		se.erase((*it));
		for(auto u:adj[v]){
			if(d[u.f.f]>d[v]+u.f.s){
				d[u.f.f]=d[v]+u.f.s;
				se.insert({d[u.f.f], u.f.f});
				p[u.f.f]=u.s;
			}
			else if(d[u.f.f]==d[v]+u.f.s && u.s.f==0){
				p[u.f.f]=u.s;
			}
		}
	}
	int ans=0;
	
	for(int i=2; i<=n; i++){
		if(p[i].f==1){
			ans++;
		}
	}
	cout<<k-ans;
	return 0;
}