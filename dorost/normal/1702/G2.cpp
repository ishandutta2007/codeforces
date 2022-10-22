/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200012, LG = 18;
int par[N][LG], h[N];
vector <int> g[N];

void dfs(int v, int p = -1) {
	for (auto u : g[v]) {
		if (u != p) {
			h[u] = h[v] + 1;
			par[u][0] = v;
			dfs(u, v);
		}
	}
}

int lca(int x, int y) {
	if (h[x] < h[y])
		swap(x, y);
	int l = (h[x] - h[y]);
	for (int i = LG - 1; i >= 0; i--) {
		if (l & (1 << i))
			x = par[x][i];
	}
	if (x == y)
		return x;
	for (int i = LG - 1; i >= 0; i--) {
		int nx = par[x][i], ny = par[y][i];
		if (nx == ny)
			continue;
		x = nx;
		y = ny;
	}
	return par[x][0];
}

int dis(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	par[1][0] = 1;
	dfs(1);
	for (int i = 1; i < LG; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		vector <int> v;
		for (int i = 0; i < k; i++) {
			int p;
			cin >> p;
			v.push_back(p);
		}
		int mx = -1, in = 0;
		vector <pair <int, int>> w;
		for (int i = 0; i < (int)v.size(); i++) {
			int l = dis(v[0], v[i]);
			if (l > mx) {
				mx = l;
				in = i;
			}
		}
		for (int i = 0; i < k; i++) {
			w.push_back(make_pair(dis(v[in], v[i]), v[i]));
		}
		sort(w.begin(), w.end());
		bool f = true;
		for (int i = 1; i < k - 1; i++) {
			int x = w[i - 1].S;
			int y = w[i].S;
			int z = w[i + 1].S;
			f &= (dis(x, y) + dis(y, z) == dis(x, z));
		}
		cout << (f ? "YES" : "NO") << '\n';
	}
}