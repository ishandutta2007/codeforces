/* In the name of God */

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
const int N = 101234, LG = 17;
vector <int> g[N];
int h[N], s[N];
int sp[N][LG], n;

void dfs(int x, int p = -1) {
	s[x] = 1;
	for (int y : g[x]) {
		if (y != p) {
			h[y] = h[x] + 1;
			sp[y][0] = x;
			dfs(y, x);
			s[x] += s[y];
		}
	}
}

inline void sparse() {
	for (int j = 1; j < LG; j++) {
		for (int i = 1; i <= n; i++) {
			sp[i][j] = sp[sp[i][j - 1]][j - 1];
		}
	}
}

inline int ans(int x, int y) {
	bool sameh = (h[x] == h[y]);
	if (h[x] < h[y])
		swap(x, y);
	int ox = x, oy = y;
	for (int i = LG - 1; i >= 0; i--) {
		if ((h[x] - h[y]) & (1 << i))
			x = sp[x][i];
	}
	int lca = x;
	if (x != y) {
		assert(h[x] == h[y]);
		for (int i = LG - 1; i >= 0; i--) {
			int nx = sp[x][i], ny = sp[y][i];
			if (nx != ny) 
				x = nx, y = ny;
		}
		lca = sp[x][0];
	}
	if (sameh) {
		return n - s[x] - s[y];
	}
	int dis = (h[ox] + h[oy] - h[lca] * 2) / 2;
	x = ox;
	y = ox;
	for (int i = LG - 1; i >= 0; i--) {
		if ((dis) & (1 << i))
			x = sp[x][i];
		if ((dis - 1) & (1 << i))
			y = sp[y][i];
	}
	return s[x] - s[y];
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	sp[1][0] = 1;
	h[1] = 0;
	dfs(1);
	sparse();
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b)
			cout << n << '\n';
		else if ((h[a] + h[b]) % 2) 
			cout << 0 << '\n';
		else
			cout << ans(a, b) << '\n';
	}
}