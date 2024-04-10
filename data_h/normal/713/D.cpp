#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

const int N = 1000, LOG = 10;

int rmq[LOG + 1][LOG + 1][N][N], a[N][N];
int n, m, Log[N + 1];

int query(int b, int l, int u, int r) {
	int row = Log[u - b + 1];
	int col = Log[r - l + 1];
	return std::max(
		std::max(rmq[row][col][b][l], rmq[row][col][u - (1 << row) + 1][l]),
		std::max(rmq[row][col][b][r - (1 << col) + 1], rmq[row][col][u - (1 << row) + 1][r - (1 << col) + 1])
	);
}

int main() {
	Log[1] = 0;
	for (int i = 2; i <= N; i++) {
		Log[i] = Log[i >> 1] + 1;
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (a[i][j] == 0) {
				rmq[0][0][i][j] = 0;
			} else {
				rmq[0][0][i][j] =
					std::min(std::min(rmq[0][0][i + 1][j], rmq[0][0][i][j + 1]),
						rmq[0][0][i + 1][j + 1]) + 1;
			}
		}
	}
	for (int i = 0; i <= LOG; i++) {
		for (int j = 0; j <= LOG; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			for (int k = 0; k < n; k++) {
				if (k + (1 << i) > n) {
					continue;
				}
				for (int l = 0; l < m; l++) {
					if (l + (1 << j) > m) {
						continue;
					}
					int &ref = rmq[i][j][k][l];
					ref = 0;
					if (i > 0) {
						ref = std::max(ref, rmq[i - 1][j][k][l]);
						ref = std::max(ref, rmq[i - 1][j][k + (1 << i - 1)][l]);
					} else if (j > 0) {
						ref = std::max(ref, rmq[i][j - 1][k][l]);
						ref = std::max(ref, rmq[i][j - 1][k][l + (1 << j - 1)]);
					}
				}
			}
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int b, l, u, r;
		scanf("%d %d %d %d", &b, &l, &u, &r);
		b--, l--, u--, r--;
		int lower = 0, upper = std::min(u - b + 1, r - l + 1);
		while (lower < upper) {
			int mid = lower + upper + 1 >> 1;
			if (query(b, l, u - mid + 1, r - mid + 1) >= mid) {
				lower = mid;
			} else {
				upper = mid - 1;
			}
		}
		printf("%d\n", lower);
	}
	return 0;
}