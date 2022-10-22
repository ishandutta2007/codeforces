#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;
const int INF = 1e9;

int n, dn[MAXN], up[MAXN];
vector<int> adj[MAXN];

void dfsDown(int v, int p = -1){
	if (~p)
		adj[v].erase(find(adj[v].begin(), adj[v].end(), p));
	for (int u:adj[v])
		up[u] = max(up[u], dn[v] + 1);
	for (int u:adj[v])
		dfsDown(u, v), dn[v] = max(dn[v], dn[u] + 1);
	
	int mx = -INF;
	for (int u:adj[v])
		up[u] = max(up[u], mx + 2), mx = max(mx, dn[u]);
	reverse(adj[v].begin(), adj[v].end());
	mx = -INF;
	for (int u:adj[v])
		up[u] = max(up[u], mx + 2), mx = max(mx, dn[u]);
}

void dfsUp(int v, int p = -1){
	if (~p) up[v] = max(up[v], up[p] + 1);
	for (int u:adj[v]) dfsUp(u, v);
}

int main(){
	int k, lim;
	scanf("%d %d %d", &n, &k, &lim);
	fill(dn, dn + n, -INF);
	fill(up, up + n, -INF);
	while (k--){
		int v; scanf("%d", &v), v--;
		dn[v] = 0;
	}
	for (int i = 0; i < n-1; i++){
		int u, v; scanf("%d %d", &u, &v), u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfsDown(0);
	dfsUp(0);
	int cnt = 0;
	for (int v = 0; v < n; v++)
		if (max(dn[v], up[v]) <= lim) cnt++;
	printf("%d\n", cnt);
	return 0;
}