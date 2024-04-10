#include <bits/stdc++.h>
using namespace std;

int id[2200];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int ncase, casen = 0;
	for (cin >> ncase; ncase--; ) {
		int n, m; cin >> n >> m;
		bitset<2000> a[2200];
		for (int i = 0; i < n; i++) a[i].reset();
		bitset<2000> c;
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v; u--, v--;
			a[u][v] = a[v][u] = 1;
			c[u] = !c[u];
			c[v] = !c[v];
		}
		for (int i = 0; i < n; i++) if (c[i]) a[i][i] = 1;
		int j = 0;
		for (int i = 0; i < n; i++) {
			for (int k = j; k < n; k++) if (a[k][i]) {
				if (k != j) {
					swap(a[j], a[k]);
					bool x = c[j];
					c[j] = c[k];
					c[k] = x;
				}
				break;
			}
			if (!a[j][i]) continue;
			for (int k = 0; k < n; k++) {
				if (k == j || !a[k][i]) continue;
				a[k] ^= a[j];
				c[k] = c[k] ^ c[j];
			}
			id[j] = i;
			j++;
		}
		bitset<2000> ans;
		for (int k = 0; k < j; k++) ans[id[k]] = c[k];
		if (!ans.count()) {
			cout << 1 << endl;
			for (int i = 0; i < n; i++) cout << 1 << ' ';
			cout << endl;
		} else {
			cout << 2 << endl;
			for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
			cout << endl;
		}
	}
	return 0;
}