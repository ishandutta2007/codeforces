#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
const int N=1000000007;
vector<vector<pair<int, int>>>adj;
vector<vector<int>>v;
int ha[200005];
int hac[10][10];
int ans;
int n, m, k;
int has;
int dfs(int index, int val){
	if(index==k+1 && val==has){
		return 1;
	}
	if(index==k+1){
		return 0;
	}
	int vals=0;
	for(int i=1; i<=index; i++){
		vals+=dfs(index+1, (val*hac[index][i])%N);
	}
	return vals;
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	adj.resize(n+1);
	mt19937 rnd(time(NULL));
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb({w, v});
	}
	v.resize(k+1);
	for(int i=1; i<=n; i++){
		sort(adj[i].begin(), adj[i].end());
	}
	for(int i=1; i<=n; i++){
		v[adj[i].size()].pb(i);
	}
	for(int i=1; i<=200000; i++){
		ha[i]=rnd();
	}
	for(int i=1; i<=k; i++){
		for(int j=1; j<=i; j++){
			hac[i][j]=1;
			for(auto u:v[i]){
				int node=adj[u][j-1].s;
				hac[i][j]=(ha[node]*hac[i][j])%N;
			}
		}
	}
	has=1;
	for(int i=1; i<=n; i++){
		has=(has*ha[i])%N;
	}

	cout<<dfs(1, 1);
	return 0;
}