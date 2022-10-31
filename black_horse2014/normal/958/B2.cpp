#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;

int par[N], st[N], en[N], dp[N], id[N], ans[N], chk[N];
vector<int> adj[N];

pair<int, int> d[N];
int add[N];
int T;

void dfs(int u, int p) {
	dp[u] = dp[p] + 1;
	st[u] = ++T;
	id[T] = u;
	par[u] = p;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	en[u] = T;
}

void build(int u, int l, int r) {
	add[u] = 0;
	if (l == r) {
		d[u] = make_pair(dp[id[l]], id[l]);
		return;
	}
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
	d[u] = max(d[u + u], d[u + u + 1]);
}

void change(int u, int del) {
	add[u] += del;
	d[u].first += del;
}

void push_down(int u) {
	if (!add[u]) return;
	change(u + u, add[u]);
	change(u + u + 1, add[u]);
	add[u] = 0;
}

void update(int u, int l, int r, int ll, int rr, int del) {
	if (ll <= l && r <= rr) {
		change(u, del);
		return;
	}
	int mid = l + r >> 1;
	push_down(u);
	if (ll <= mid) update(u + u, l, mid, ll, rr, del);
	if (mid < rr) update(u + u + 1, mid + 1, r, ll, rr, del);
	d[u] = max(d[u + u], d[u + u + 1]);
}

pair<int, int> query(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) return d[u];
	int mid = l + r >> 1;
	pair<int, int> ret = make_pair(0, 0);
	push_down(u);
	if (ll <= mid) ret = max(ret, query(u + u, l, mid, ll, rr));
	if (mid < rr) ret = max(ret, query(u + u + 1, mid + 1, r, ll, rr));
	return ret;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (n == 1) return puts("1"), 0;
	T = 0, dfs(1, 0);
	int a = max_element(dp + 1, dp + n + 1) - dp;
	T = 0, dfs(a, 0);
	ans[1] = 1;
	build(1, 1, n);
	update(1, 1, n, st[a], en[a], -1);
	chk[a] = 1;
	for (int i = 2; i <= n; i++) {
		pair<int, int> ret = query(1, 1, n, 1, n);
		ans[i] = ans[i-1] + ret.first;
		if (ans[i] == n) {
			for (i++; i <= n; i++) ans[i] = n;
			break;
		}
		int a = ret.second;
		while (!chk[a]) {
			chk[a] = 1;
			update(1, 1, n, st[a], en[a], -1);
			a = par[a];
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}