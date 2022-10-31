#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int f(char c) {
	return c == '#';
}

bool chk[N][N], vis[N];
char s[N][N];
vector<int> R, C, adj[N * 2];
int q[N * 2];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (s[i][j] == '#') {
			adj[i].push_back(j + n);
			adj[j + n].push_back(i);
		}
	for (int i = 1; i <= n + m; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		int hd = 0, tl = 0;
		q[tl++] = i;
		while (hd < tl) {
			int u = q[hd++];
			for (int j = 0; j < adj[u].size(); j++) {
				int v = adj[u][j];
				if (vis[v]) continue;
				vis[v] = true;
				q[tl++] = v;
			}
		}
		R.clear();
		C.clear();
		for (int j = 0; j < tl; j++) {
			if (q[j] <= n) R.push_back(q[j]);
			else C.push_back(q[j] - n);
		}
		for (int j = 0; j < R.size(); j++)
			for (int k = 0; k < C.size(); k++) chk[R[j]][C[k]] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (f(s[i][j]) != chk[i][j]) return puts("No"), 0;
	return puts("Yes"), 0;
	
}