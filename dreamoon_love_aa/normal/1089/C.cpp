#include <bits/stdc++.h>
using namespace std;
int d[520][520];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int k, x, y;
		scanf("%d%d", &k, &x);
		for (int j = 1; j < k; j++) {
			scanf("%d", &y);
			d[x][y] = d[y][x] = 1;
			x = y;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int tt = 0; tt < n; tt++) {
		set<int> s;
		for (int i = 1; i <= n; i++) {
			s.insert(i);
		}
		while (true) {
			int md = 1e9, mi = -1;
			for (int i: s) {
				int dd = 0;
				for (int j: s) {
					dd += d[i][j];
				}
				if (md > dd) {
					md = dd;
					mi = i;
				}
			}
			printf("%d\n", mi);
			fflush(stdout);
			char o[8];
			scanf("%s", o);
			if (*o == 'F') {
				break;
			} else {
				int x;
				scanf("%d", &x);
				s.erase(mi);
				set<int> del;
				for (int i: s) {
					if (d[mi][i] <= d[x][i]) {
						del.insert(i);
					}
				}
				for (int i: del) {
					s.erase(i);
				}
			}
		}
	}
}