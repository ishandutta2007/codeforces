#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0);
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, M = 1e6 + 10;

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

int get_root(int u);
bool merge(int u, int v);

int main()
{
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].id = i;
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
		} else {
			non_tree_edges.push_back(e[i]);
		}
	}
	for (auto &e : non_tree_edges) {
		e.w = e.id;
	}
	sort(non_tree_edges.begin(), non_tree_edges.end());
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
		cout << tree_edges[hi[i] + 1].w << '\n';
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