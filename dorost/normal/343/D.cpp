/* 	* In the name of GOD  */

#pragma GCC optimize ("O3,unroll-loops")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 500012;
set <int> q0, q1[N];
vector <int> w0[N];
vector <int> g[N];
vector <int> q[N];
int ans[N];

void dfs (int v, int p = -1) {
	for (int i : w0[v])
		q0.insert(i);
	for (int u : g[v]) {
		if (u != p) {
			dfs(u, v);
			if (q1[u].size() > q1[v].size()) {
				swap(q1[u], q1[v]);
			}
			for (int i : q1[u])
				q1[v].insert(i);
		}
	}
	for (int i : q[v]) {
		auto a = q1[v].lower_bound(i);
		int x, y;
		if (a == q1[v].begin())
			x = -100;
		else {
			a--;
			x = *a;
		}
		auto b = q0.lower_bound(i);
		if (b == q0.begin())
			y = -1000;
		else {
			b--;
			y = *b;
		}
		if (y > x) {
			ans[i] = 1;
		} else {
			ans[i] = 0;
		}
	}
	for (int i : w0[v])
		q0.erase(i);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ans[i] = -1;
		int c, v;
		cin >> c >> v;
		if (c == 2) {
			q1[v].insert(i);
		} else if (c == 1) {
			w0[v].push_back(i);
		} else {
			q[v].push_back(i);
		}
	}
	dfs(1);
	for (int i = 1; i <= t; i++) {
		if (ans[i] != -1)
			cout << ans[i] << '\n';
	}
}