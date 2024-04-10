#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int n, k;
vector<vector<int>>adj;
int cnt;
int num=0;

int l;


int timer;
vector<int> tin, tout;
vector<vector<int>> up;
int dep[100005];

void dfs(int v, int p, int h)
{
	dep[v]=h;
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
    dfs(root, root, 0);
}



set<pair<int, int>>se;

int d(int v, int u){
	int node=lca(u, v);
	return (dep[u]+dep[v]-2*dep[node]);
}


void ins(int v){
	
	if(se.size()==0){
		se.insert({tin[v], v});
		num++;
		return;
	}
	auto it=se.lower_bound({tin[v], v});
	if(it==se.end() || it==se.begin()){
		
		auto it1=se.begin();
		auto it2=se.end();
		it2--;
		int node1=(*it1).s;
		int node2=(*it2).s;
		
		num+=((d(v, node1)+d(v, node2)-d(node1, node2))/2);
		
		
		se.insert({tin[v], v});
		return;
	}
	
	int node2=(*it).s;
	it--;
	int node1=(*it).s;
	num+=((d(v, node1)+d(v, node2)-d(node1, node2))/2);
	se.insert({tin[v], v});
	
	return;
}

void del(int v){
	if(se.size()==1){
		num=0;
		se.erase({tin[v], v});
		return;
	}
	se.erase({tin[v], v});
	auto it=se.lower_bound({tin[v], v});
	if(it==se.end() || it==se.begin()){
		
		auto it1=se.begin();
		auto it2=se.end();
		it2--;
		int node1=(*it1).s;
		int node2=(*it2).s;
		num-=((d(v, node1)+d(v, node2)-d(node1, node2))/2);

		return;
	}
	
	int node2=(*it).s;
	it--;
	int node1=(*it).s;
	
	num-=((d(v, node1)+d(v, node2)-d(node1, node2))/2);

	return;
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	adj.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int maxi=0;
	
	int pt=1;
	preprocess(1);
	ins(1);
	
	for(int i=1; i<=n; i++){
		if(i!=1){
			del(i-1);
		}
		while(pt<n){
			ins(pt+1);
			
			if(num<=k){
				pt++;
				continue;
			}
			else{
				
				
				
				del(pt+1);
				
				break;
			}
		}
		
		maxi=max(maxi, pt-i+1);
	}
	cout<<maxi;
	return 0;
}