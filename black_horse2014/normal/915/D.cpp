#include <bits/stdc++.h>
using namespace std;

const int N = 550;
const int M = 110000;
int vis[N], x[M], y[M], pr[N], chk[M];
vector<int> cand, adj[N];
int found;
void dfs(int u, int p) {
	if (found) return;
	vis[u] = 1;
	for (int e : adj[u]) {
		int v = y[e];
		if (vis[v] == 1) {
			if (found) return;
			found = 1;
			cand.push_back(e);
			while (u != v) {
				cand.push_back(pr[u]);
				u = x[pr[u]];
			}
			return;
		} else if (vis[v] == 2) continue;
		else pr[v] = e, dfs(v, u);
	}
	vis[u] = 2;
}

bool dfs1(int u, int p) {
	vis[u] = 1;
	for (int e : adj[u]) {
		int v = y[e];
		if (chk[e]) continue;
		if (vis[v] == 1) {
			return false;
		} else {
			if (vis[v] == 2) continue;
			else {
				if (!dfs1(v, u)) return false;
			}
		}
	}
	vis[u] = 2;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		adj[x[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
	if (!found) return puts("YES"), 0;
	for (int e : cand) {
		chk[e] = 1;
		memset(vis, 0, sizeof(int) * (n + 1));
		bool ok = true;
		for (int i = 1; i <= n; i++) if (!vis[i]) ok &= dfs1(i, 0);
		if(ok) return puts("YES"), 0;
		chk[e] = 0;
	}
	return puts("NO"), 0;
}