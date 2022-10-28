#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define pb push_back
#define f first
#define s second
#define int long long int
vector<vector<pair<int, int>>>adj;
int le[100005];
multiset<pair<int, pair<int, int>>>se;
int tot;

void dfs(int v, int p){
	if(adj[v].size()==1 && v!=1){
		le[v]=1;
		return;
	}
	for(auto u:adj[v]){
		if(u.f==p){
			continue;
		}
		dfs(u.f, v);
		le[v]+=le[u.f];
		int w=u.s;
		int ne=(u.s)/2;
		int dec=le[u.f]*(w-ne);
		se.insert({dec, {w, le[u.f]}});
		tot+=(le[u.f]*(u.s));
	}
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, S;
		cin>>n>>S;
		se.clear();
		adj.clear();
		adj.resize(n+1);
		tot=0;
		for(int i=0; i<=n; i++){
			le[i]=0;
		}
		for(int i=0; i<n-1; i++){
			int u, v, w;
			cin>>u>>v>>w;
			adj[u].pb({v, w});
			adj[v].pb({u, w});
		}
		dfs(1, 1);
		
		int ste=0;
		while(tot>S){
			auto it=se.end();
			it--;
			int dec=(*it).f;
			int w=(*it).s.f;
			int num=(*it).s.s;
			ste++;
			tot-=dec;
			se.erase(se.find((*it)));
			w=(w/2);
			int ne=(w/2);
			se.insert({(w-ne)*num, {w, num}});
		}
		cout<<ste<<endl;
	}
	return 0;
}