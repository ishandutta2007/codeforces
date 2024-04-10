//started coding on 3.11 pm.
#include <bits/stdc++.h>
using namespace std;

const int N = 110;

vector<pair<int, int> > adj[N];
int vis[N], q[N], qn, deg[N], dp[N][N][26][3];
void dfs(int u) {
	vis[u] = 1;
	q[qn++] = u;
	for (auto e : adj[u]) if (!(--deg[e.first]) && !vis[e.first]) dfs(e.first);
}		
int a[N][N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	memset(a, -1, sizeof a);
	for (int i = 1; i <= m; i++) {
		int u, v;
		char ch[3];
		cin >> u >> v >> ch;
		a[u][v] = *ch - 'a';
		adj[u].push_back(make_pair(v, *ch - 'a'));
		deg[v]++;
	}
	for (int i = 1; i <= n; i++) if (!deg[i] && !vis[i]) dfs(i);
	for (int i = qn - 1; i >= 0; i--)
		for (int j = qn - 1; j >= 0; j--) 
			for (int k = 0; k < 26; k++)
				for (int l = 1; l <= 2; l++) {
					int u = q[i], v = q[j];
					dp[u][v][k][l] = 3 - l;
					if (l == 1) {
						for (int w = 1; w <= n; w++) if (a[u][w] >= k) dp[u][v][k][l] = min(dp[u][v][k][l], dp[w][v][a[u][w]][3 - l]);
					} else {
						for (int w = 1; w <= n; w++) if (a[v][w] >= k) dp[u][v][k][l] = max(dp[u][v][k][l], dp[u][w][a[v][w]][3 - l]);
					}
				}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%c", "AB"[dp[i][j][0][1] == 2]);
		puts("");
	}
	return 0;
}
//ended coding on 3.19 pm
//reversed on 3.33 pm