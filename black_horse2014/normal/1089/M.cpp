#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int T, qn;
int q[N], vis[N];
vector<int> adj[N], radj[N], con[N];

void dfs(int u) {
	vis[u] = 1;
	for (int v : adj[u]) if (!vis[v]) dfs(v);
	q[++qn] = u;
}

void rdfs(int u) {
	vis[u] = T;
	for (int v : radj[u]) if (!vis[v]) rdfs(v);
}

char str[33][33][33];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			if (x) adj[i].push_back(j), radj[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
	memset(vis, 0, sizeof vis);
	for (int i = n; i > 0; i--) if (!vis[q[i]]) ++T, rdfs(q[i]);
	for (int i = 1; i <= n; i++) {
		for (int j : adj[i]) {
			if (vis[i] == vis[j]) continue;
			con[vis[i]].push_back(vis[j]);
		}
	}
	for (int i = 1; i <= T; i++) {
		sort(con[i].begin(), con[i].end());
		con[i].erase(unique(con[i].begin(), con[i].end()), con[i].end());
	}
	int H = T * 3 - 2;
	for (int i = 1; i <= H; i++) {
		if (i % 3 == 1) {
			for (int j = 0; j <= n*3; j++) {
				for (int k = 0; k <= n*3; k++) {
					str[i][j][k] = '.';
				}
			}
		} else {
			for (int j = 0; j <= n*3; j++) {
				for (int k = 0; k <= n*3; k++) {
					str[i][j][k] = '#';
				}
			}
		}
	}
	for (int i = 1; i <= H; i+=3) {
		for (int j = 1; j <= n*3; j++) {
			for (int k = 1; k <= n*3; k++) {
				str[i][j][k] = '#';
			}
		}
	}
	for (int i = 1; i <= H; i+=3) {
		int id = (i - 1) / 3 + 1;
		for (int j = 1; j <= n; j++) {
			if (vis[j] == id) str[i][0][j] = '0' + j;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j : con[i]) {
			int f = i * 3 - 2, t = j * 3 - 2;
			for (int k = f; k <= t; k++) {
				str[k][i+i+i-1][j+j+j-1] = '.';
			}
			for (int k = 1; k <= j*3; k++) {
				str[f][i+i+i][k] = str[f][i+i+i-1][k] = str[f][i+i+i-2][k] = '.';
				str[t][i+i+i][k] = str[t][i+i+i-1][k] = str[t][i+i+i-2][k] = '.';
			}
		}
	}
	cout << n+n+n+1 << ' ' << n+n+n+1 << ' ' << H << endl;
	for (int i = 1; i <= H; i++) {
		for (int j = 0; j <= n+n+n; j++) {
			for (int k = 0; k <= n+n+n; k++) {
				cout << str[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}