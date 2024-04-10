/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
bool ok[N], d[N], okr[N];
vector <int> g[N], v[N];
set <int> st;
int pe[N], h[N], dp[N];

void dfs2(int x, int p) {
	pe[x] = p;
	h[x] = (p == -1 ? 0 : h[p] + 1); 
	for (auto y : g[x]) {
		if (y != p) {
			dfs2(y, x);
		}
	}
}

bool dfs(int x) {
	if (!okr[x]) {
		d[x] = true;
		return false;
	}
	bool f = false;
	int c = 0;
	for (auto y : g[x]) {
		if (y != pe[x]) {
			f |= dfs(y);
			c++;
		}
	}
	if (c == 0)
		return true;
	return f;
}

void solve() {
	int n, k;
	cin >> n >> k;
	st.clear();
	for (int i = 0; i < n; i++)
		ok[i] = true, g[i].clear(), d[i] = false, pe[i] = 0, v[i].clear(), h[i] = 0, okr[i] = true;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		x--;
		st.insert(x);
		ok[x] = false;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool f = false;
	dfs2(0, -1);
	for (int i = 0; i < n; i++) {
		v[h[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (v[i].empty())
			continue;
		for (auto a : v[i]) {
			okr[a] = ok[a];
		}
		set <int> st2;
		for (auto a : st) {
			if (pe[a] != -1 && ok[pe[a]]) {
				st2.insert(pe[a]);
				ok[pe[a]] = false;
			}
		}
		st = st2;
	}
	f = dfs(0);
	if (f) {
		cout << "YES ";
	} else {
		cout << "NO ";
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