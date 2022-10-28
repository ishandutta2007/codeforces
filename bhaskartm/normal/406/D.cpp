#include <bits/stdc++.h>
using namespace std;
#define int long long int



int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
	
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
	
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
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
    
    dfs(root, root);
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	int x[n+1];
	int y[n+1];
	adj.resize(n+1);
	for(int i=1; i<=n; i++){
		cin>>x[i]>>y[i];
	}
	int p[n+1];
	p[n]=n;
	int Dx[n+1];
	int Dy[n+1];
	for(int i=n-1; i>=1; i--){
		int dx=x[i+1]-x[i];
		int dy=y[i+1]-y[i];
		int node=i+1;
		while(1){
			
			if(node==n){
				break;
			}
			int dx2=Dx[node];
			int dy2=Dy[node];
			
			if(dy*dx2>=dy2*dx){
				break;
			}
			node=p[node];
			dx=x[node]-x[i];
			dy=y[node]-y[i];
		}
		p[i]=node;
		Dx[i]=x[p[i]]-x[i];
		Dy[i]=y[p[i]]-y[i];
	}
	for(int i=1; i<n; i++){
		adj[i].push_back(p[i]);
		adj[p[i]].push_back(i);
	}
	preprocess(n);
	
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		int u ,v;
		cin>>u>>v;
		cout<<lca(u, v)<<endl;
	}
	
	return 0;
}