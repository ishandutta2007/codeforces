#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

#define all(x) (x).begin(), (x).end()

int n, L, R;
int a, b;

int lo = -1, hi = 1e9 + 1;

const int MAXN = 111111;
const int INF = 1e9;

vector<PII> adj[MAXN];

int sz[MAXN], chk[MAXN];
int q[MAXN], f[MAXN], g[MAXN], d[MAXN], h[MAXN];

void dfs(int u, int p) {
	sz[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (v != p) {
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
			int v = adj[u][i].first;
			if (chk[v]) continue;
			if (sz[v] > sz[r]) r = v;
		}
		if (sz[r] <= s / 2) return u;
		sz[u] = s - sz[r], u = r;
	}
}

bool cmp(PII a, PII b) {
	return sz[a.first] < sz[b.first];
}

void go(int u, int p, int mid, int s) {
	f[u] = s, d[u] = d[p] + 1;
	if (d[u] > R) return;
	if (f[h[d[u]]] < s) h[d[u]] = u;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (v == p || chk[v]) continue;
		go(v, u, mid, s + (adj[u][i].second >= mid ? 1 : -1));
	}
}

bool check(int u, int mid, int &x, int &y) {
	f[u] = d[u] = 0, f[0] = -INF, g[0] = u;
	for (int j = 1; j <= R && j <= sz[u]; j++) g[j] = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (chk[v]) continue;
		for (int j = 1; j <= R && j <= sz[v]; j++) h[j] = 0;
		go(v, u, mid, (adj[u][i].second >= mid ? 1 : -1));
		int head = 0, tail = 0;
		for (int j = 1, k = min(sz[v], R-1); j <= min(R, sz[v]); j++) {
			if (h[j] == 0) break;
			for (; k >= max(0, L-j); k--) {
				if (g[k] == 0) continue;
				while (head < tail && f[g[q[tail - 1]]] <= f[g[k]]) tail--;
				q[tail++] = k;
			}
			while (head < tail && q[head] > R-j) head++;
			if (head < tail && f[g[q[head]]] + f[h[j]] >= 0) {
				x = g[q[head]], y = h[j];
				return 1;
			}
		}
		for (int j = 1; j <= min(R, sz[v]); j++) if (f[g[j]] < f[h[j]]) g[j] = h[j];
	}
	return 0;
}

void process(int u) {
	sort(all(adj[u]), cmp);
	hi = 1e9 + 1;
	int x = 0, y = 0;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (check(u, mid, x, y)) a = x, b = y, lo = mid;
		else hi = mid;
	}
}

void solve(int u) {
	u = get_center(u);
	process(u), chk[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (!chk[v]) solve(v);
	}
}

int main() {
	cin >> n >> L >> R;
	for (int i = 1; i < n; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	dfs(1, 0);
	solve(1);
	printf("%d %d\n", a, b);
	return 0;
}