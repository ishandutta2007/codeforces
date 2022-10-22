/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, LG = 17;
int a[N], h[N], n;
int s[N], ans[N];
vector <pair <int, int>> g[N];
int sp[N][LG];

void dfs(int v, int p) {
	s[v] = a[v];
	for (auto [u, i] : g[v]) {
		if (u != p) {
			sp[u][0] = v;
			h[u] = h[v] + 1;
			dfs(u, v);
			s[v] += s[u];
			ans[i] = s[u];
		}
	}
}

void sparse() {
    for (int i = 1; i < LG; i++) {
        for (int j = 1; j <= n; j++) {
			if (sp[j][i - 1] == -1)
				sp[j][i] = -1;
			else
	            sp[j][i] = sp[sp[j][i - 1]][i - 1];
        }
    }
}

int lca(int x, int y) {
	if (h[x] < h[y])
		swap(x, y);
	int l = (h[x] - h[y]);
	for (int i = LG - 1; i >= 0; i--) {
		if (l & (1 << i))
			x = sp[x][i];
	}
	assert(h[x] == h[y]);
	if (x == y)
		return x;
	for (int i = LG - 1; i >= 0; i--) {
		int nx = sp[x][i], ny = sp[y][i];
		if (nx == ny)
			continue;
		x = nx;
		y = ny;
	}
	return sp[x][0];
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(make_pair(v, i));
		g[v].push_back(make_pair(u, i));
	}
	sp[1][0] = -1;
	h[1] = 0;
	dfs(1, -1);
	sparse();
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		a[x]++;
		a[y]++;
		int l = lca(x, y);
		a[l] -= 2;
	}
	dfs(1, -1);
	for (int i = 1; i < n; i++) {
		cout << ans[i] << ' ';
	}
}