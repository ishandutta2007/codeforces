#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;

vector<vector<int>>adj;
vector<set<int>>tree;
int pa[N];
int sz[N];

int dfs1(int v, int p){
	sz[v]=1;
	for(auto u:tree[v]){
		if(u!=p){
			sz[v]+=dfs1(u, v);
		}
	}
	return sz[v];
}

int dfs2(int v, int p, int n){
	for(auto u:tree[v]){
		if(u!=p && sz[u]>(n/2)){
			return dfs2(u, v, n);
		}
	}
	return v;
}

void build(int v, int p){
	int n=dfs1(v, p);
	int centroid=dfs2(v, p, n);
	if(p==-1){
		p=centroid;
	}
	pa[centroid]=p;
	vector<int>vec;
	for(auto u:tree[centroid]){
		vec.pb(u);
	}
	for(auto u:vec){
		tree[centroid].erase(u);
		tree[u].erase(centroid);
		build(u, centroid);
	}
}





int n, l;
int ans[N];
int d[N];
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p, int h){
	d[v]=h;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, h+1);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root, 0);
}


void f1(int v){
	int node=v;
	while(1){
	
		int lc=lca(node, v);
		
	
		int val=d[node]+d[v]-2*d[lc];
		ans[node]=min(ans[node], val);
		if(pa[node]==node){
			break;
		}
		node=pa[node];
	}
}

int f2(int v){
	int node=v;
	int mini=1e9;
	while(1){
		int lc=lca(node, v);
		int val=d[node]+d[v]-2*d[lc];
		mini=min(mini, ans[node]+val);
		if(pa[node]==node){
			break;
		}
		node=pa[node];
	}
	return mini;
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin>>n>>m;
	adj.resize(n+1);
	tree.resize(n+1);
	for(int i=1; i<=n; i++){
		ans[i]=1e9;
	}
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		tree[v].insert(u);
		tree[u].insert(v);
		
	}
	
	build(1, -1);
	preprocess(1);
	
	
	f1(1);

	while(m--){
		int ty;
		cin>>ty;
		if(ty==1){
			int v;
			cin>>v;
			f1(v);
		}
		else{
			int v;
			cin>>v;
			cout<<f2(v)<<endl;
		}
	}
	return 0;
}