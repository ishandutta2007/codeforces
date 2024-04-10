#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int size[100005];
int parent[100005];
int color[100005];
vector<vector<int>>adj;
vector<int>path;

bool dfs(int v, int p, int dest){
	if(v==dest){
		return 1;
	}
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		if(dfs(u, v, dest)){
			path.push_back(u);
			return 1;
		}
		
	}
	return 0;
}

void dfs2(int v, int p, int c){
	color[v]=c;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs2(u, v, 1-c);
	}
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin>>n>>m>>k;
	adj.resize(k+1);
	for(int i=1; i<=k; i++){
		make_set(i);
	}
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		if(u<=k && v<=k && (find_set(u)==find_set(v))){
			path.push_back(u);
			bool b=dfs(u, u,  v);
			cout<<2<<endl;
			cout<<path.size()<<endl;
			for(auto u:path){
				cout<<u<<" ";
			}
			return 0;
		}
		if(u<=k && v<=k){
			adj[u].pb(v);
			adj[v].pb(u);
			union_sets(u, v);
		}
	}
	
	for(int i=1; i<=k; i++){
		color[i]=2;
	}
	for(int i=1; i<=k; i++){
		if(color[i]==2){
			dfs2(i, i, 0);
		}
	}
	
	vector<int>zero;
	vector<int>one;
	for(int i=1; i<=k; i++){
		if(color[i]==1){
			one.pb(i);
		}
		else{
			zero.pb(i);
		}
	}
	if(one.size()>=zero.size()){
		cout<<1<<endl;
		for(int i=0; i<(k+1)/2; i++){
			cout<<one[i]<<" ";
		}
		return 0;
	}
	cout<<1<<endl;
	for(int i=0; i<(k+1)/2; i++){
			cout<<zero[i]<<" ";
	}
	return 0;
}