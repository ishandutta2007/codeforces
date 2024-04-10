#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=2e5+5;

int n;
vector<vector<int>>g, gr;
vector<bool>used;
vector<int>order, component, scc;
vector<vector<int>>comp;

void dfs1(int v){
	used[v]=1;
	for(auto u:g[v]){
		if(!used[u]){
			dfs1(u);
		}
	}
	order.pb(v);
}

void dfs2(int v){
	used[v]=1;
	component.pb(v);
	for(auto u:gr[v]){
		if(!used[u]){
			dfs2(u);
		}
	}
}

void scc_calc(){
	used.assign(n, false);
	for(int i=0; i<n; i++){
		if(!used[i]){
			dfs1(i);
		}
	}
	used.assign(n, false);
	scc.resize(n);
	for(int i=0, cnt=0; i<n; i++){
		int v=order[n-1-i];
		if(!used[v]){
			dfs2(v);
			for(auto u:component){
				scc[u]=cnt;
			}
			comp.pb(component);
			cnt++;
			component.clear();
		}
	}
}

vector<pair<pair<int, int>, int>>ed;
vector<vector<pair<int, int>>>adj;

bool vis[N];
int dis[N];
int cyc[N];
vector<int>cy;
vector<int>path;


void dfs(int v, int d){
	dis[v]=d;
	path.pb(v);
	vis[v]=1;
	for(auto u:adj[v]){
		if(vis[u.f]){
			cy.pb(abs(dis[v]-dis[u.f]+u.s));
		}
		else{
			dfs(u.f, d+u.s);
		}
	}
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin>>n>>m;
	g.resize(n);
	gr.resize(n);
	
	for(int i=0; i<m; i++){
		int u, v, l;
		cin>>u>>v>>l;
		u--;
		v--;
		g[u].pb(v);
		gr[v].pb(u);
		ed.pb({{u, v}, l});
	}
	
	scc_calc();
	adj.resize(n);
	
	for(auto u:ed){
		if(scc[u.f.f]==scc[u.f.s]){
			adj[u.f.f].pb({u.f.s, u.s});
		
		}
	}
	
	for(int i=0; i<n; i++){
		if(!vis[i]){
			dfs(i, 0);
			int gc=0;
			for(auto u:cy){
				gc=__gcd(gc, u);
			}
			for(auto u:path){
				cyc[u]=gc;
			}
			
			cy.clear();
			path.clear();
		}
	}

	int q;
	cin>>q;
	while(q--){
		int v, d1, d2;
		cin>>v>>d1>>d2;
		v--;
		int toinc=(d2-d1);
		int gc=__gcd(d2, cyc[v]);
		if(toinc%gc==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}