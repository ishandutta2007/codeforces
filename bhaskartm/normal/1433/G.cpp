#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


vector<vector<pair<int, int>>>adj;
int d[1005][1005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin>>n>>m>>k;
	vector<pair<pair<int, int>, int>>ed;
	adj.resize(n+1);
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
		ed.pb({{u, v}, w});
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			d[i][j]=1e9;
		}
		d[i][i]=0;
		set<pair<int, int>>se;
		se.insert({0, i});
		bool pre[n+1];
		for(int i=1; i<=n; i++){
			pre[i]=0;
		}
		while(!se.empty()){
			auto it=se.begin();
			int node=(*it).s;
			se.erase(it);
			if(pre[node]){
				continue;
			}
			pre[node]=1;
			for(auto u:adj[node]){
				if(d[i][node]+u.s<d[i][u.f]){
					d[i][u.f]=d[i][node]+u.s;
					se.insert({d[i][u.f], u.f});
				}
			}
		}
	}
	vector<pair<int, int>>qu;
	
	for(int i=0; i<k; i++){
		int u, v;
		cin>>u>>v;
		qu.pb({u, v});
	}
	int mini=1e18;
	for(int i=0; i<m; i++){
		int u=ed[i].f.f;
		int v=ed[i].f.s;
		int w=ed[i].s;
		int ans=0;
		for(auto uu:qu){
			int u1=uu.f;
			int u2=uu.s;
			int val=d[u1][u2];
			val=min(val, d[u][u1]+d[u2][v]);
			val=min(val, d[u][u2]+d[u1][v]);
			ans+=val;
		}
		mini=min(mini, ans);
	}
	cout<<mini;
	
	return 0;
}