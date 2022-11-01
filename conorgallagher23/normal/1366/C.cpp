#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9'){ if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 35;

int n, m, a[N][N], fa[N * N], sz[2][N * N];
vector<pair<int, int> > vec[N << 1];

int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}
void merge(int u, int v) {
	if (find(u) != find(v)) fa[fa[u]] = fa[v];
}
int id(int i, int j) {
	return (i - 1) * m + j;
}

int main() {
	int T = read();
	while (T--) {
		n = read(); m = read();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) a[i][j] = read();
		for (int i = 1; i <= n + m; i++) vec[i].clear();
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				vec[i + j].push_back(make_pair(i, j));
				fa[id(i, j)] = id(i, j);
			}
		for (int i = 1; i <= n + m; i++) {
			int tmp = n + m - i + 2;
			if (vec[i].empty() || vec[tmp].empty()) continue;
			for (auto it1 : vec[i]) {
				int x = it1.first, y = it1.second;
				for (auto it2 : vec[tmp]) {
					int xx = it2.first, yy = it2.second;
					if ((x <= xx && y <= yy) || (x >= xx && y >= yy)) {
						merge(id(x, y), id(xx, yy));
					}
				}
			}
		}
		for (int k = 0; k < 2; k++)
			for (int i = 1; i <= n * m; i++) sz[k][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) ++sz[a[i][j]][find(id(i, j))];
		int ans = 0;
		for (int i = 1; i <= n * m; i++) ans += min(sz[0][i], sz[1][i]);
		printf("%d\n", ans);
	}
	return 0;
}