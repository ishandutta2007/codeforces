/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501234;
int par[N];
pair <int, int> up[N];
int vis[N];
int d[N];
int n, m;
int h[N];
bool del[N];
vector <int> g[N];
vector <int> k[N];
vector <int> ma;
int w[N];

void print (vector <int> v) {
	if ((int)v.size() >= n - 1 || (int)v.size() == 0) {
		cout << "No\n";
		return;
	}
	for (int i : v)
		del[i] = true;
	cout << "Yes\n";
	cout << n - (int)v.size() << '\n';
	for (int i = 1; i <= n; i++)
		if (!del[i])
			cout << i << ' ';
	cout << '\n';
}

void dfs(int v, int root) {
	vis[v] = root;
	for (int u : g[v]) {
		if (d[u] != 2)
			continue;
		if (vis[u] == 0) {
			h[u] = h[v] + 1;
			par[u] = v;
			dfs(u, root);
		} else {
			if (abs(h[u] - h[v]) != 1 && h[v] >= h[u]) {
				up[v] = max(up[v], make_pair(h[u], u));
			}
		}
	}
}

void masir(int x, int y) {
	if (x == y)
		ma.push_back(x);
	else if (h[x] > h[y]) {
		ma.push_back(x);
		masir (par[x], y);
	} else {
		masir (x, par[y]);
		ma.push_back(y);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n + 5; i++) {
		par[i] = -1;
		up[i] = {INT_MIN, 0};
		vis[i] = 0;
		d[i] = 0;
		h[i] = 0;
		g[i].clear();
		del[i] = false;
		k[i].clear();
		w[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		d[u]++;
		d[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ma.clear();
	for (int i = 1; i <= n; i++) {
		d[i] %= 3;
		if (d[i] == 0) {
			print({i});
			return;
		} else if (d[i] == 1) {
			for (int j : g[i]) {
				if (j < i && d[j] == 1) {
					print({i, j});
					return;
				}
			}
		}
	}
	int comp = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && d[i] == 2) {
			par[i] = i;
			h[i] = 0;
			comp++;
			dfs(i, i);
		}
	}
	int mn = INT_MAX, in = -1;
	for (int i = 1; i <= n; i++) {
		if (up[i].F != INT_MIN) {
			if (h[i] < mn) {
				mn = h[i];
				in = i;
			}
		}
	}
	if (in != -1) {
		int u = in, v = up[in].S;
		masir(u, v);
		print(ma);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] == 1) {
			for (int j : g[i])
				k[vis[j]].push_back(i);
		}
	}
	int u = -1, v = -1;
	in = -1;
	for (int i = 1; i <= n; i++) {
		if (!k[i].empty()) {
			for (int j = 0; j < (int)k[i].size() - 1; j++) {
				if (k[i][j] != k[i][j + 1]) {
					u = k[i][j], v = k[i][j + 1];
					in = i;
				}
			}
		}
	}
	if (u != -1) {
		int ou = u, ov = v;
		for (int x : g[u]) {
			if (vis[x] == in) {
				u = x;
				break;
			}
		}
		for (int i = 0; i < n + 5; i++) {
			par[i] = -1;
			vis[i] = 0;
			h[i] = 0;
		}
		dfs(u, in);
		int mnn = INT_MAX, inn = -1;
		for (int x : g[ov]) {
			if (vis[x] == in) {
				if (h[x] < mnn) {
					mnn = h[x];
					inn = x;
				}
			}
		}
		v = inn;
		masir(u, v);
		for (int i = 0; i < (int)ma.size(); i++) {
			w[ma[i]] = i + 1;
		}
		int mxxx = INT_MIN, innn = -1;
		for (int x : g[ou]) {
			if (w[x] != 0) {
				if (w[x] > mxxx) {
					mxxx = w[x];
					innn = x;
				}
			}
		}
		ma.clear();
		masir(innn, v);
		ma.push_back(ou);
		ma.push_back(ov);
		print(ma);
		return;
	}
	int cnt = 0, lst = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 1) {
			cnt++;
			lst = i;
		}
	}
	assert(cnt == 1);
	if (comp == 1) {
		print({});
	}
	for (int i = 0; i < n + 5; i++) {
		k[i].clear();
	}
	for (int i : g[lst]) {
		k[vis[i]].push_back(i);
	}
	cnt = 0;
	int f = -1, l = -1;
	for (int i = 1; i <= n; i++) {
		if (k[i].empty())
			continue;
		assert((int)k[i].size() >= 2);
		if (cnt == 0) {
			f = k[i][0];
		} else if (cnt == 1) {
			l = k[i][0];
		} else {
			continue;
		}
		cnt++;
	}
	if (l != -1) {
		in = vis[f];
		int in2 = vis[l];
		for (int i = 0; i < n + 5; i++) {
			par[i] = -1;
			vis[i] = 0;
			h[i] = 0;
		}
		dfs(f, in);
		dfs(l, in2);
		int mnn = INT_MAX, inn = -1;
		int mnn2 = INT_MAX, inn2 = -1;
		for (int x : g[lst]) {
			if (vis[x] == in && x != f) {
				if (h[x] < mnn) {
					mnn = h[x];
					inn = x;
				}
			}
			if (vis[x] == in2 && x != l) {
				if (h[x] < mnn2) {
					mnn2 = h[x];
					inn2 = x;
				}
			}
		}
		masir(f, inn);
		masir(l, inn2);
		ma.push_back(lst);
		print(ma);
		return;
	}
	print({});
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}