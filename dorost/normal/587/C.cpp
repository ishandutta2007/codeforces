/* In the name of God */

#include <bits/stdc++.h>

using namespace std;

const int N = 100012, LG = 17, M = 10;
int sp[N][LG][M], st[N][LG], h[N], n;
vector <int> g[N];
int a[N][M], cnt[N];
int me[M];

inline void merge(int x[M], int y[M]) {
	int in1 = 0, in2 = 0;
	for (int i = 0; i < M; i++) {
		if (x[in1] < y[in2]) {
			me[i] = x[in1];
			in1++;
		} else {
			me[i] = y[in2];
			in2++;
		}
	}
}

void dfs(int x, int p = -1) {
	for (int y : g[x]) {
		if (y != p) {
			st[y][0] = x;
			h[y] = h[x] + 1;
			for (int i = 0; i < M; i++)
				sp[y][0][i] = a[y][i];
			dfs(y, x);
		}
	}
}

inline void sparse() {
	for (int j = 1; j < LG; j++) {
		for (int i = 1; i <= n; i++) {
			st[i][j] = st[st[i][j - 1]][j - 1];
			merge(sp[i][j - 1], sp[st[i][j - 1]][j - 1]);
			for (int k = 0; k < M; k++) {
				sp[i][j][k] = me[k];
			}
		}
	}
}

inline int lca(int x, int y) {
	if (h[x] < h[y])
		swap(x, y);
	for (int i = LG - 1; i >= 0; i--) {
		if ((h[x] - h[y]) & (1 << i)) {
			x = st[x][i];
		}
	}
	if (x == y)
		return x;
	for (int i = LG - 1; i >= 0; i--) {
		int ny = st[y][i], nx = st[x][i];
		if (ny != nx)
			y = ny, x = nx;
	}
	return st[y][0];
}

int main() {
	int m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= m; i++) {
		int c;
		cin >> c;
		if (cnt[c] == M)
			continue;
		a[c][cnt[c]] = i;
		cnt[c]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = cnt[i]; j < M; j++) {
			a[i][j] = N;
		}
	}
	h[1] = 0;
	st[1][0] = 1;
	for (int i = 0; i < M; i++)
		sp[1][0][i] = a[1][i];
	dfs(1);
	sparse();
	while (q--) {
		int u, v, a;
		cin >> u >> v >> a;
		if (u == v) {
			vector <int> aa;
			for (int i = 0; i < a; i++) {
				if (sp[u][0][i] == N)
					break;
				aa.push_back(sp[u][0][i]);
			}
			cout << aa.size() << ' ';
			for (int x : aa)
				cout << x << ' ';
			cout << '\n';
			continue;
		}
		int l = lca(u, v);
		int ans[M];
		for (int i = 0; i < M; i++)
			ans[i] = N;
		int f1 = h[u] - h[l] + 1, h2 = h[v] - h[l] + 1;
		if (f1 >= h2) {
			f1--;
		} else {
			h2--;
		}
		for (int i = LG - 1; i >= 0; i--) {
			if (f1 & (1 << i)) {
				merge(ans, sp[u][i]);
				for (int j = 0; j < M; j++)
					ans[j] = me[j];
				u = st[u][i];
			}
			if (h2 & (1 << i)) {
				merge(ans, sp[v][i]);
				for (int j = 0; j < M; j++)
					ans[j] = me[j];
				v = st[v][i];
			}
		}
		vector <int> aa;
		for (int i = 0; i < a; i++) {
			if (ans[i] == N)
				break;
			aa.push_back(ans[i]);
		}
		cout << aa.size() << ' ';
		for (int x : aa)
			cout << x << ' ';
		cout << '\n';
	}
}