#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 20;
const int LOG = 17 + 3;

int n, depth[MAXN], par[LOG][MAXN], tt[LOG][MAXN], ss[LOG][MAXN], dn[MAXN], upp[MAXN], size[MAXN], ord[MAXN], rmq[LOG][MAXN], nxt[LOG][MAXN];
vector<int>	adj[MAXN];

int dfs(int v, int p = -1, int de = 0, int oo = 0){
	ord[v] = oo;
	depth[v] = de;
	par[0][v] = p;
	dn[v] = 0;

	int cn = 0;
	for (int u:adj[v])
		if (u != p){
			dn[v] = max(dn[v], dfs(u, v, de + 1, cn++) + 1);
			rmq[0][u] = dn[u] + 1;
		}
	size[v] = cn;
	
	int maxi = 0;
	for (int u:adj[v])
		if (u != p){
			ss[0][u] = maxi + 1;
			maxi = max(maxi, dn[u] + 1);
		}

	maxi = 0;
	int xx = -1;
	for (int i = adj[v].size() - 1; i >= 0; i--){
		int u = adj[v][i];
		if (u != p){
			ss[0][u] = max(ss[0][u], maxi + 1);
			tt[0][u] = ss[0][u] - 1;
			maxi = max(maxi, dn[u] + 1);
			nxt[0][u] = xx;
			xx = u;
		}
	}
	return	dn[v];
}

void dup(int v, int p = -1, int de = 0){
	upp[v] = ss[0][v];
	if (p != -1)
		upp[v] = max(upp[v], upp[p] + 1);

	for (int u:adj[v])
		if (u != p)	dup(u, v, de + 1);
}

void init(){
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++)
			if (par[i - 1][j] == -1)
				par[i][j] = -1, ss[i][j] = ss[i - 1][j], tt[i][j] = tt[i - 1][j];
			else{
				par[i][j] = par[i - 1][par[i - 1][j]], ss[i][j] = max(ss[i - 1][j], ss[i - 1][par[i - 1][j]] + (1 << (i - 1)));
				if (par[i][j] != -1)
					tt[i][j] = max(tt[i - 1][j] + (1 << (i - 1)), tt[i - 1][par[i - 1][j]]);
				else
					tt[i][j] = max(tt[i - 1][j] + depth[par[i - 1][j]], tt[i - 1][par[i - 1][j]]); 
			}

	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++){
			if (nxt[i - 1][j] == -1)
				nxt[i][j] = -1, rmq[i][j] = rmq[i - 1][j];
			else
				nxt[i][j] = nxt[i - 1][nxt[i - 1][j]], rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][nxt[i - 1][j]]);
		}
}

int lca(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v])	u = par[i][u];
	if (u == v)	return	u;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[i][u] != par[i][v])	
			u = par[i][u], v = par[i][v];
	return	par[0][v];
}	

int get(int v, int d){
	int tv = v;
	int ret = 0;
	for (int i = LOG - 1; i >= 0; i--)
		if (d - (1 << i) >= 0){
			ret = max(ret, ss[i][v] + depth[tv] - depth[v]);
			v = par[i][v];
			d -= (1 << i);
		}
	return	ret;
}

int get_par(int v, int d){
	for (int i = LOG - 1; i >= 0; i--)
		if (d >= (1 << i)){
			v = par[i][v];
			d -= (1 << i);
		}
	return	v;
}

int get2(int v, int d){
	int ret = 0;
	for (int i = LOG - 1; i >= 0; i--)
		if (d >= (1 << i)){
			d -= (1 << i);
			ret = max(ret, tt[i][v] + d);
			v = par[i][v];
		}
	return	ret + 1;
}

int mx(int p, int u, int v = -1){
	int sz = (int)adj[p].size() - bool(p != 0);
	int a = u, b = v;
	if (b != -1 && ord[a] > ord[b])	swap(a, b);

	int ret = 0, d = ord[a], ind;
	if (adj[p][0] == par[0][p])	
		ind = adj[p][1];
	else
		ind = adj[p][0];

	for (int i = LOG - 1; i >= 0; i--)
		if (d >= (1 << i)){
			ret = max(ret, rmq[i][ind]);
			ind = nxt[i][ind];
			d -= (1 << i);	
		}
	
	ind = nxt[0][a];
	if (b != -1)
		d = ord[b] - ord[a] - 1;
	else
		d = sz - ord[a] - 1;

	for (int i = LOG - 1; i >= 0; i--)
		if (d >= (1 << i)){
			ret = max(ret, rmq[i][ind]);
			ind = nxt[i][ind];
			d -= (1 << i);
		}

	if (b == -1)	return	ret;

	ind = nxt[0][b], d = sz - ord[b] - 1;
	for (int i = LOG - 1; i >= 0; i--)
		if (d >= (1 << i)){
			ret = max(ret, rmq[i][ind]);
			ind = nxt[i][ind];
			d -= (1 << i);
		}
	return	ret;
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
	dfs(0);
	dup(0);
	init();

	int q;	cin >> q;
	while (q--){
		int u, v;	cin >> u >> v;	u--, v--;
		if (depth[u] > depth[v])	swap(u, v);
		int p = lca(u, v);
		
		int ans = upp[p] + depth[u] - depth[p];
		ans = max(ans, dn[v]);
		if (u != p)	ans = max(ans, dn[u]);

		int z = depth[v] - depth[p] - 1;
		int d = z + 1 + depth[u] - depth[p];
		int y = min(z, d/2);
		ans = max(ans, get(v, y));
		if (y < z)	ans = max(ans, depth[u] - depth[p] + max(z - y, get2(get_par(v, y), z - y)));

		z = depth[u] - depth[p] - 1;
		ans = max(ans, get(u, z));

		if (u == p)
			ans = max(ans, mx(p, get_par(v, depth[v] - depth[p] - 1)));
		else
			ans = max(ans, mx(p, get_par(u, depth[u] - depth[p] - 1), get_par(v, depth[v] - depth[p] - 1)) + depth[u] - depth[p]);
		cout << ans << "\n";
	}	
	return	0;
}