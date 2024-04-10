#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 20;
const int LOG = 20;

int n, q;
vector<int>	adj[MAXN];
int depth[MAXN], s_t[MAXN], f_t[MAXN], cn, sz[MAXN];
int par[MAXN][LOG];


void build(int v, int p = -1, int de = 0){
	par[v][0] = p;
	s_t[v] = cn++;
	depth[v] = de;
	sz[v] = 1;

	for (int u:adj[v])
		if (u != p){
			build(u, v, de + 1);
			sz[v] += sz[u];
		}
	f_t[v] = cn;
}

void init(){
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++)
			if (par[j][i - 1] == -1)
				par[j][i] = -1;
			else
				par[j][i] = par[par[j][i - 1]][i - 1];
}

int move_up(int v, int x){
	for (int i = LOG - 1; i >= 0; i--)
		if ((1 << i) <= x)
			v = par[v][i], x -= 1 << i;
	return	v;
}

int lca(int u, int v){
	if (depth[u] < depth[v])
		swap(u, v);
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v])
			u = par[u][i];
	if (u == v)
		return	u;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return	par[u][0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(0);
	init();

	cin >> q;
	while (q--){
		int u, v;	cin >> u >> v;	u--, v--;
		if (u == v){
			cout << n << "\n";
			continue;
		}

		if (depth[u] > depth[v])	
			swap(u, v);
		int p = lca(u, v);
		int dis = depth[u] - depth[p] + depth[v] - depth[p];
		if (dis % 2){
			cout << 0 << "\n";
			continue;
		}

		if (depth[u] == depth[v]){
			v = move_up(v, dis/2 - 1);
			u = move_up(u, dis/2 - 1);
			cout << n - sz[v] - sz[u] << "\n";
		}
		else{
			v = move_up(v, dis/2 - 1);
			cout << sz[par[v][0]] - sz[v] << "\n";
		}
	}
	return 0;
}