#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 100;
const int M = 20;

vector<int> adj[N];
int fa[N];

int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

struct node {
	int u, v, w;
	node (int u = 0, int v = 0, int w = 0)
		:u(u), v(v), w(w) {}
	bool operator < (const node &rhs) const {
		return w < rhs.w;
	}	
	void in() {
		cin >> u >> v >> w;
	}
}edge[N];

int n, dep[N], par[N][20], upd[N][20];

void dfs(int u, int p, int depth) {
	dep[u] = depth; fa[u] = p;
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, depth + 1);
	}
}

void lca_init() {
	for (int i = 1; i <= n; i++) par[i][0] = fa[i];
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= n; j++) if (par[j][i-1] != -1){
			par[j][i] = par[par[j][i-1]][i-1];
		}
	}
}

int lca(int u, int v) {
	while (dep[u] > dep[v]) {
		for (int i = M - 1; i >= 0; i--) if ((1 << i) + dep[v] <= dep[u]) u = par[u][i];
	}
	while (dep[v] > dep[u]) {
		for (int i = M - 1; i >= 0; i--) if ((1 << i) + dep[u] <= dep[v]) v = par[v][i];
	}
	assert (dep[u] == dep[v]);
	for (int i = M - 1; i >= 0; i--) if ((1 << i) <= dep[u]) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	if (u != v) {
		assert (dep[u] > 0);
		u = par[u][0];
		v = par[v][0];
		assert (u == v);
	}
	return u;
}

const int inf = 0x3f3f3f3f;

inline void chkmin(int &a, int b) {
	if (a > b) a = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	int K, m; cin >> n >> K >> m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 0; i < K; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		u = find(u), v = find(v);
		fa[u] = v;
	}
	for (int i = 0; i < m; i++) edge[i].in();
	sort (edge, edge + m);
	long long subsum = 0;
	for (int i = 0; i < m; i++) {
		int u = find(edge[i].u), v = find(edge[i].v);
		if (u != v) {
			subsum += edge[i].w;
			fa[u] = v;
			adj[edge[i].u].push_back(edge[i].v);
			adj[edge[i].v].push_back(edge[i].u);
		}
	}
	dfs(1, -1, 0);
	lca_init();
	memset (upd, 0x3f, sizeof upd);
	for (int i = 0; i < m; i++) {
		int f = lca(edge[i].u, edge[i].v);
		int d, cur;
		d = dep[edge[i].u] - dep[f];
		cur = edge[i].u;
		for (int j = 0; j < M; j++) if ((1 << j) & d) {
			chkmin(upd[cur][j], edge[i].w);
			cur = par[cur][j];
		}
		assert (cur == f);
		
		d = dep[edge[i].v] - dep[f];
		cur = edge[i].v;
		for (int j = 0; j < M; j++) if ((1 << j) & d) {
			chkmin(upd[cur][j], edge[i].w);
			cur = par[cur][j];
		}
		assert (cur == f);
	}
	for (int i = M - 1; i > 0; i--) {
		for (int j = 1; j <= n; j++) {
			chkmin(upd[j][i-1], upd[j][i]);
			if (par[j][i-1] != -1) {
				chkmin(upd[par[j][i-1]][i-1], upd[j][i]);
			}
		}
	}
	long long sum = 0;
	for (int i = 2; i <= n; i++) {
		if (upd[i][0] == inf) {
			cout << -1 << endl;
			return 0;
		}
		sum += upd[i][0];
	}
	cout << sum - subsum << endl;
	return 0;
}