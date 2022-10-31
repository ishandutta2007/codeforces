#include <bits/stdc++.h>
using namespace std;

const int N = 310000;

char s[N];
vector<int> adj[N];
int deg[N], q[N], cnt[26][N];

int main() {
	int n, m; cin >> n >> m;
	scanf("%s", s + 1);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		deg[v]++;
	}
	int qn = 0;
	for (int i = 1; i <= n; i++) if (!deg[i]) q[qn++] = i;
	for (int i = 0; i < qn; i++) {
		int u = q[i];
		for (int v : adj[u]) {
			if (--deg[v] == 0) q[qn++] = v;
		}
	}
	if (qn != n) {
		puts("-1");
		return 0;
	}
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int u = q[i];
		for (int v : adj[u]) {
			for (int j = 0; j < 26; j++) cnt[j][u] = max(cnt[j][u], cnt[j][v]);
		}
		cnt[s[u]-'a'][u]++;
		for (int j = 0; j < 26; j++) ans = max(ans, cnt[j][u]);
	}
	cout << ans << endl;
	return 0;
}