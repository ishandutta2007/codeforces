#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0);
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, LOG = log2(N) + 10, M = 1e6 + 10, inf = 1e9;

struct edge {
	int u, v, w, id;
	bool operator<(const edge &o) const {
		return w < o.w;
	}
};

edge e[M];
int sz[N], par[N];
int lo[M], hi[M];
vector<int> check[M];
vector<edge> g[N];

int depth[N], up_id[N];
int up[N][LOG], mn[N][LOG];
int ans[M];

int get_root(int u);
bool merge(int u, int v);
void dfs(int u, int p);
int get_lca(int u, int v);
void update(int u, int d, int w);
void dfs2(int u, int p);

int main()
{
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].id = i + 1;
	}
	for (int i = 1; i <= n; ++i) {
		sz[i] = 1;
		par[i] = i;
	}
	sort(e, e + m);
	vector<edge> tree_edges, non_tree_edges;
	for (int i = 0; i < m; ++i) {
		if (merge(e[i].u, e[i].v)) {
			tree_edges.push_back(e[i]);
			g[e[i].u].push_back(e[i]);
			swap(e[i].u, e[i].v);
			g[e[i].u].push_back(e[i]);
			// cout << e[i].u << ' ' << e[i].v << endl;
		} else {
			non_tree_edges.push_back(e[i]);
		}
	}
	int k = non_tree_edges.size();
	for (int i = 0; i < k; ++i) {
		lo[i] = 0; hi[i] = n - 2;
	}
	while (true) {
		bool left = false;
		for (int i = 0; i < k; ++i) {
			if (lo[i] <= hi[i]) {
				check[(lo[i] + hi[i]) / 2].push_back(i);
				left = true;
			}
		}
		if (!left) {
			break;
		}
		for (int i = 1; i <= n; ++i) {
			par[i] = i;
			sz[i] = 1;
		}
		for (int i = 0; i < n - 1; ++i) {
			merge(tree_edges[i].u, tree_edges[i].v);
			for (auto &j : check[i]) {
				int u = non_tree_edges[j].u;
				int v = non_tree_edges[j].v;
				if (get_root(u) == get_root(v)) {
					hi[j] = i - 1;
				} else {
					lo[j] = i + 1;
				}
			}
			check[i].clear();
		}
	}
	for (int i = 0; i < k; ++i) {
		// cout << tree_edges[hi[i] + 1].w << '\n';
		ans[non_tree_edges[i].id] = tree_edges[hi[i] + 1].w;
	}
	dfs(1, 0);
	for (auto &e : non_tree_edges) {
		int l = get_lca(e.u, e.v);
		update(e.u, depth[e.u] - depth[l], e.w);
		update(e.v, depth[e.v] - depth[l], e.w);
	}
	dfs2(1, 0);
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << '\n';
	}
}

int get_root(int u) {
	if (par[u] == u) {
		return u;
	} else {
		par[u] = get_root(par[u]);
		return par[u];
	}
}

bool merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return false;
	} else if (sz[u] < sz[v]) {
		swap(u, v);
	}
	sz[u] += sz[v];
	par[v] = u;
	return true;
}

void dfs(int u, int p) {
	up[u][0] = p;
	mn[u][0] = inf;
	for (int j = 1; j < LOG; ++j) {
		up[u][j] = up[up[u][j - 1]][j - 1];
		mn[u][j] = inf;
	}
	for (auto &e : g[u]) {
		if (e.v != p) {
			depth[e.v] = depth[u] + 1;
			// cout << u << ' ' << e.v << ' ' << e.id << endl;
			up_id[e.v] = e.id;
			dfs(e.v, u);
		}
	}
}

int get_lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	for (int j = LOG - 1; j >= 0; --j) {
		if (depth[up[u][j]] >= depth[v]) {
			u = up[u][j];
		}
	}
	if (u == v) {
		return u;
	}
	for (int j = LOG - 1; j >= 0; --j) {
		if (up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
		}
	}
	return up[u][0];
}

void update(int u, int d, int w) {
	// cout << u << ' ' << d << ' ' << w << endl;
	for (int j = LOG - 1; j >= 0; --j) {
		if ((1 << j) <= d) {
			mn[u][j] = min(mn[u][j], w);
			d -= (1 << j);
			u = up[u][j];
		}
	}
}

void dfs2(int u, int p) {
	for (auto &e : g[u]) {
		// cout << "edge " << u << ' ' << p << ' ' << e.v << endl;
		if (e.v != p) {
			dfs2(e.v, u);
		}
	}
	for (int j = LOG - 1; j >= 1; --j) {
		int v = up[u][j - 1];
		// if (u == 2 and j <= 5) {
		// 	cout << j << ' ' << v << ' ' << mn[u][j] << ' ' << mn[v][j - 1] << endl;
		// }
		mn[u][j - 1] = min(mn[u][j - 1], mn[u][j]);
		mn[v][j - 1] = min(mn[v][j - 1], mn[u][j]);
	}
	// cout << u << ' ' << up_id[u] << endl;
	ans[up_id[u]] = mn[u][0];
}