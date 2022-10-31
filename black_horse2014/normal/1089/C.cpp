#include <bits/stdc++.h>
using namespace std;

const int N = 550;

vector<int> adj[N];
int chk[N], dis[N][N], q[N];

int main() {
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		int last = 0;
		while (k--) {
			int u; cin >> u;
			if (last) {
				adj[last].push_back(u);
				adj[u].push_back(last);
			}
			last = u;
		}
	}
	const int inf = 1024;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dis[i][j] = inf;
		int qn = 0; q[qn++] = i; dis[i][i] = 0;
		for (int j = 0; j < qn; j++) {
			int u = q[j];
			for (int v : adj[u]) {
				if (dis[i][v] == inf) {
					dis[i][v] = dis[i][u] + 1;
					q[qn++] = v;
				}
			}
		}
	}
	for (int times = 0; times < n; times++) {
		for (int i = 1; i <= n; i++) chk[i] = 1;
		while (1) {
			int min_max_sons = n + 1, ans = 0;
			for (int u = 1; u <= n; u++) {
				if (!chk[u]) continue;
				int max_sons = 0;
				for (int v : adj[u]) {
					int sons = 0;
					for (int w = 1; w <= n; w++) {
						if (!chk[w]) continue;
						if (dis[u][w] > dis[v][w]) sons++;
					}
					max_sons = max(max_sons, sons);
				}
				if (min_max_sons > max_sons) {
					min_max_sons = max_sons;
					ans = u;
				}
			}
			cout << ans << endl;
			cout.flush();
			string str; cin >> str;
			if (str[0] == 'F') break;
			int ret; cin >> ret;
			for (int i = 1; i <= n; i++) chk[i] &= (dis[ans][i] == dis[ret][i] + 1);
		}
	}
	return 0;
}