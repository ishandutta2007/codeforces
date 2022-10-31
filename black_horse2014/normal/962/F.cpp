#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int low[N], chk[N], vis[N], num[N], art[N];
int T, n, m, tot, bn, cn;
int x[N], y[N], b[N], c[N], cc[N], ok[N];

vector<int> adj[N];

void dfs(int u, int f) {
	low[u] = chk[u] = ++T;
	vis[u] = tot;
	for (int e : adj[u]) {
		if (e == f) continue;
		int v = x[e] ^ y[e] ^ u;
		if (!chk[v]) {
			b[bn++] = e;
			dfs(v, e);
			low[u] = min(low[u], low[v]);
			if (chk[u] <= low[v]) {
				cn++, art[u]++;
				int nume = 0, numv = 0;
				int to = bn, from;
				while (bn > 0) {
					int g = b[--bn];
					c[g] = cn;
					from = bn;
					nume++;
					if (cc[x[g]] != cn) numv++, cc[x[g]] = cn;
					if (cc[y[g]] != cn) numv++, cc[y[g]] = cn;
					if (g == e) break;
				}
				if (numv == nume) {
					for (; from != to; from++) ok[b[from]] = 1;
				}
			}
		} else {
			if (chk[v] < chk[u]) b[bn++] = e;
			low[u] = min(low[u], chk[v]);
		}
	}
	if (!f && art[u]) art[u]--;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		adj[x[i]].push_back(i);
		adj[y[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) tot++, dfs(i, 0);
	int sz = 0;
	for (int i = 1; i <= m; i++) sz += ok[i];
	cout << sz << endl;
	for (int i = 1; i <= m; i++) if (ok[i]) cout << i << " ";
	cout << endl;
	return 0;
}