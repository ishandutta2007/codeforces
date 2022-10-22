#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;
const int LOG = 17 + 3;

int n, m, depth[MAXN], par[LOG][MAXN], cn[LOG][MAXN];
bool vis[MAXN];
vector<int>	adj[MAXN];
set<pair<int, int>>	st;

int dfs(int v, int p = -1, int de = 0){
	vis[v] = 1, depth[v] = de;
	int ret = de;
	for (int u:adj[v])
		if (u != p){
			if (vis[u])
				ret = min(ret, depth[u]);
			else{
				int z = dfs(u, v, de + 1);
				if (z > de)	st.insert({v, u});
				ret = min(ret, z);
			}
		}
	return	ret;
}

void plant(int v, int p = -1, int de = 0){
	vis[v] = 1;
	depth[v] = de;
	par[0][v] = p;
	if (st.count({p, v}) || st.count({v, p}))	cn[0][v] = 1;
	for (int u:adj[v])
		if (!vis[u])	plant(u, v, de + 1);
}

void init(){
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++)
			if (par[i - 1][j] == -1)
				par[i][j] = -1, cn[i][j] = cn[i - 1][j];
			else
				par[i][j] = par[i - 1][par[i - 1][j]], cn[i][j] = cn[i - 1][j] + cn[i - 1][par[i - 1][j]];
}

int lca(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v])	u = par[i][u];
	if (u == v)	return	u;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[i][u] != par[i][v])	u = par[i][u], v = par[i][v];
	return	par[0][u];
}

int get(int v, int d){
	int ret = 0;
	for (int i = LOG - 1; i >= 0; i--)
		if (d >= (1 << i)){
			d -= (1 << i);
			ret += cn[i][v];
			v = par[i][v];
		}
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;	while(m--){int a, b;	cin >> a >> b;	a--, b--;	adj[a].push_back(b);	adj[b].push_back(a);}
	dfs(0);
	memset(vis, 0, sizeof(vis));
	plant(0);
	init();

	int q;	cin >> q;
	while (q--){
		int u, v;	cin >> u >> v;	u--, v--;
		int p = lca(u, v);
		cout << get(u, depth[u] - depth[p]) + get(v, depth[v] - depth[p]) << "\n";
	}
	return	0;
}