#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1 << 23];
int a[1 << 22], vis[1 << 23], chk[1 << 22], cn;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	memset(chk, -1, sizeof chk);
	for (int i = 0; i < m; i++) cin >> a[i], chk[a[i]] = i;
	for (int i = 0; i < m; i++) if (!vis[i]) {
		cn++;
		vis[i] = cn;
		queue<int> Q;
		Q.push(i);
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			if (u < m) {
				int v = a[u] + m;
				if (!vis[v]) {
					vis[v] = cn;
					Q.push(v);
				}
			} else {
				u -= m;
				for (int i = 0; i < n; i++) if (!(u >> i & 1)) {
					int v = (1 << i | u) + m;
					if (!vis[v]) {
						vis[v] = cn;
						Q.push(v);
					}
				}
				int v = chk[(1 << n) - 1 - u];
				if (~v && !vis[v]) {
					vis[v] = cn;
					Q.push(v);
				}
			}
		}
	}
	cout << cn << endl;
	return 0;
}