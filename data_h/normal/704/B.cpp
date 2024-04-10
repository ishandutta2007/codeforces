#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 5e3 + 7;
const long long INF = (1LL << 60);

int n, x[N], a[N], b[N], c[N], d[N];
long long f[2][N];
int s, t;

int get_back(int i, int j) {
	if (s > i && t <= i) return j + 1;
	if (s <= i && t > i) return j - 1;
	return j;
}

inline void update(long long &x, long long y) {
	if (y < x) {
		x = y;
	}
}

int main() {
	scanf("%d %d %d", &n, &s, &t);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	x[0] = x[1];
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);

	fill(f[0], f[0] + n + 1, INF);
	f[0][0] = 0;
	int cur = 0, nxt = 1;
	for (int i = 0; i < n; i++) {
		fill(f[nxt], f[nxt] + n + 1, INF);
		for (int j = 0; j <= i && j <= n - i; j++) {
			int to = j, back = get_back(i, j);
			long long delta = 1LL * (x[i + 1] - x[i]) * (to + back);

			if (i > 0 && to + back == 0 || f[cur][j] == INF) {
				continue;
			}

			if (i + 1 == s) {
				if (back > 0) {
					update(f[nxt][j], f[cur][j] + delta + c[i + 1]);
				}
				update(f[nxt][j + 1], f[cur][j] + delta + d[i + 1]);
			} else if (i + 1 == t) {
				if (j > 0) {
					update(f[nxt][j - 1], f[cur][j] + delta + a[i + 1]);
				}
				update(f[nxt][j], f[cur][j] + delta + b[i + 1]);
			} else {

				// 1
				if (back > 0) {
					update(f[nxt][j], f[cur][j] + delta + b[i + 1] + c[i + 1]);
				}

				// 2
				if (j > 0) {
					update(f[nxt][j], f[cur][j] + delta + d[i + 1] + a[i + 1]);
				}

				// 3
				update(f[nxt][j + 1], f[cur][j] + delta + b[i + 1] + d[i + 1]);

				// 4
				if (back > 0 && j > 0) {
					update(f[nxt][j - 1], f[cur][j] + delta + a[i + 1] + c[i + 1]);
				}
			}
		}
		swap(cur, nxt);
	}

	cout << f[cur][0] << endl;
	return 0;
}