/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], s[N], p[N], v0;
bool vis[N];
vector <int> adj[N];
set <int> st;
bool u = false;

void dfs(int x) {
	vis[x] = true;
	int ans = a[x];
	for (auto y : adj[x]) {
		if (vis[y])
			continue;
		p[y] = x;
		dfs(y);
		ans ^= s[y];
	}
	s[x] = ans;
}

void dfs2(int x) {
	vis[x] = true;
	if (u) {
		st.insert(x);
	}
	if (x == v0)
		u = true;
	for (auto y : adj[x]) {
		if (vis[y])
			continue;
		dfs2(y);
	}
	if (x == v0)
		u = false;
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		vis[i] = false;
		s[i] = 0;
		adj[i].clear();
	}
	int xo = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		xo ^= a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	if (xo == 0) {
		cout << "YES ";
		return;
	} else {
		if (k == 2) {
			cout << "NO ";
			return;
		}
		vector <int> v, w;
		st.clear();
		for (int i = 1; i < n; i++) {
			if (s[i] == xo) {
				v.push_back(i);
				int x = i;
				while (x != 0) {
					if (st.count(x)) 
						break;
					st.insert(x);
					x = p[x];
				}
			} else if (s[i] == 0) {
				w.push_back(i);
			}
		}
		for (auto aa : w) {
			if (st.count(aa)) {
				cout << "YES ";
				return;
			}
		}
		if (!v.size()) {
			cout << "NO ";
			return;
		}
		st.clear();
		int x = v[0];
		while (x != 0) {
			st.insert(x);
			x = p[x];
		}
		v0 = v[0];
		bool f = false;
		for (auto x : v) {
			if (st.count(x) == 0) {
				f = true;
			}
		}
		cout << (f ? "YES " : "NO ");
		return;
	}
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