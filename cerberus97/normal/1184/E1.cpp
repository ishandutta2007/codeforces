#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0);
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, M = 1e6 + 10;

struct edge {
	int u, v, w;
	bool operator<(const edge &o) const {
		return w < o.w;
	}
};

edge e[M];
int sz[N], par[N];

int get_root(int u);
bool merge(int u, int v);

int main()
{
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= n; ++i) {
		sz[i] = 1;
		par[i] = i;
	}
	sort(e + 1, e + m);
	for (int i = 1; i < m; ++i) {
		merge(e[i].u, e[i].v);
		if (get_root(e[0].u) == get_root(e[0].v)) {
			cout << e[i].w << endl;
			return 0;
		}
	}
	cout << int(1e9) << endl;
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