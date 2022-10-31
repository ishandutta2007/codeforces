#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int cnt[N][5];
int b[5], c[5];

vector<pair<int, int> > con[N][N], adj[N][N];
int deg[N][N];
int a[11000];
pair<int, int> q[N * N];
int chk[N][N], ans[N][N];

int extract(int *b) {
	int s = 0;
	for (int i = 1; i <= 4; i++) s = s * 9 + b[i];
	return s;
}

int main() {
	int n = 0;
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8 - i; j++) {
			for (int k = 0; k <= 8 - i - j; k++) {
				for (int l = 0; l <= 8 - i - j - k; l++) {
					cnt[n][0] = 8 - i - j - k - l;
					cnt[n][1] = i;
					cnt[n][2] = j;
					cnt[n][3] = k;
					cnt[n][4] = l;
					a[extract(cnt[n])] = n++;
				}
			}
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 1; k <= 4; k++) if (cnt[i][k]) {
				for (int l = 1; l <= 4; l++) if (cnt[j][l]) {
					memcpy(b, cnt[i], sizeof(int)*5);
					b[k]--, b[(k+l)%5]++;
					int u = a[extract(b)];
					adj[i][j].push_back(make_pair(j, u));
					con[j][u].push_back(make_pair(i, j));
					deg[i][j]++;
//					if (i == 165 && j == 46) {
//						if (k == 1 && l == 4) {
//							cerr << "ok " << u << endl;
//						}
//					}
				}
			}
		}
	}
	int qn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!deg[i][j]) q[qn++] = make_pair(i, j), chk[i][j] = 1;
		}
	}
	for (int it = 0; it < qn; it++) {
		auto s = q[it];
		int d = ans[s.first][s.second];
		for (auto t : con[s.first][s.second]) {
			if (chk[t.first][t.second]) continue;
			if (--deg[t.first][t.second] == 0) {
				q[qn++] = t;
				chk[t.first][t.second] = 1;
				if (!d) ans[t.first][t.second] = 1;
			} else if (!d) {
				ans[t.first][t.second] = 1;
				chk[t.first][t.second] = 1;
				q[qn++] = t;
			}
		}
	}
//	cerr << qn << endl;
//	for (int i = 0; i < qn; i++) chk[q[i].first][q[i].second] = 1;
//	for (int i = 0; i < qn; i++) {
//		auto s = q[i];
//		for (auto t : adj[s.first][s.second]) {
//			if (!ans[t.first][t.second]) {
//				ans[s.first][s.second] = 1;
//				break;
//			}
//		}
//	}
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		int f; scanf("%d", &f);
		int u[2] = {0};
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 5; i++) c[i] = 0;
			for (int i = 0; i < 8; i++) {
				int x; scanf("%d", &x);
				c[x]++;
			}
			u[j] = a[extract(c)];
		}
//		cerr << u[0] << ' ' << u[1] << endl;
		if (f) swap(u[0], u[1]);
		if (!chk[u[0]][u[1]]) {
			puts("Deal");
		} else {
			int ret = ans[u[0]][u[1]] ^ f;
			puts(ret ? "Alice" : "Bob");
		}
	}
	return 0;
}