/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
vector <int> g[N], v, g2[N];
bool vis[N], a[N], ok[N];

void dfs(int x) {
	vis[x] = true;
	v.push_back(x);
	a[x] = !a[x];
	for (auto y : g[x]) {
		if (!vis[y]) {
			dfs(y);
			v.push_back(x);
			a[x] = !a[x];
			if (a[y]) {
				v.push_back(y);
				a[y] = !a[y];
				v.push_back(x);
				a[x] = !a[x];
			}
		}
	}
}

bool dfs2(int x) {
	vis[x] = true;
	bool f = false;
	if (a[x])
		f = true;
	for (auto y : g[x]) {
		if (!vis[y]) {
			bool k = dfs2(y);
			f |= k;
		}
	}
	ok[x] = f;
	return f;
}

int32_t main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int in = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i])
			continue;
		bool k = dfs2(i);
		cnt += k;
		if (k)
			in = i;
	}
	if (cnt > 1) {
		cout << -1;
	} else {
		for (int i = 0; i < N; i++)
			vis[i] = false;
		dfs(in);
		if (a[in])
			v.pop_back();
		cout << v.size() << '\n';
		for (auto x : v)
			cout << x + 1 << ' ';
	}
}