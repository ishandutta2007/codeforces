#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

long long ans[N], sum[N];
int par[N], chk[N], sz[N], a[N], b[N], cnt[1<<20], ccnt[1<<20];

vector<int> adj[N], V[N], all;
char s[N];

void dfs(int u, int p) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v != p && !chk[v]) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}

int get_center(int u) {
	int s = sz[u];
	while (1) {
		int r = 0;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (chk[v]) continue;
			if (sz[v] > sz[r]) r = v;
		}
		if (sz[r] <= s / 2) return u;
		sz[u] = s - sz[r], u = r;
	}
}

void go(int u, int p, int r) {
	a[u] = a[p] ^ b[u];
	V[r].push_back(u);
	all.push_back(u);
	for (auto v : adj[u]) {
		if (v != p && !chk[v]) {
			go(v, u, r);
		}
	}
}

void calc(int u, int p) {
	for (auto v : adj[u]) {
		if (chk[v] || v == p) continue;
		calc(v, u);
		sum[u] += sum[v];
	}
}

void process(int u) {
	all.clear();
	all.push_back(u);
	a[u] = b[u];
	for (int v : adj[u]) {
		if (chk[v]) continue;
		V[v].clear();
		go(v, u, v);
	}
	for (int i : all) cnt[a[i]]++;
	sum[u] = 0;
	for (int v : adj[u]) {
		if (chk[v]) continue;
		for (int x : V[v]) ccnt[a[x]]++, sum[x] = 0;
		for (int x : V[v]) {
			for (int j = 0; j < 20; j++) {
				int y = a[x]^b[u]^(1<<j);
				int temp = cnt[y] - ccnt[y];
				sum[x] += temp;
				sum[u] += temp - (y==b[u]);
			}
			int y = a[x]^b[u];
			int temp = cnt[y] - ccnt[y];
			sum[x] += temp;
			sum[u] += temp - (y==b[u]);
		}
		for (int x : V[v]) ccnt[a[x]] = 0;
	}
	sum[u] /= 2;
	for (int j = 0; j < 20; j++) sum[u] += cnt[1<<j];
	sum[u] += cnt[0];
	ans[u] += sum[u];
	for (int i : all) cnt[a[i]] = 0;
	for (int v : adj[u]) {
		if (chk[v]) continue;
		calc(v, u);
		for (int x : V[v]) ans[x] += sum[x];
	}
}

void solve(int u) {
	dfs(u, 0);
	u = get_center(u);
//	cerr << u << endl;
	process(u), chk[u] = 1;
	for (int v : adj[u]) if (!chk[v]) solve(v);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) b[i] = 1<<s[i]-'a';
//	DFS(1, 0);
//	for (int i = 2; i <= n; i++) adj[i].erase(find(adj[i].begin(), adj[i].end(), par[i]));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j < adj[i].size(); j++) if (sz[adj[i][j]] > sz[adj[i][0]]) swap(adj[i][0], adj[i][j]);
//		reverse(adj[i].begin(), adj[i].end());
//	}
	solve(1);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}