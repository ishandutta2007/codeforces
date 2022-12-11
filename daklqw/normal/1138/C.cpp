#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1010;
int cli[MAXN][MAXN], cbak[MAXN];
int dli[MAXN][MAXN], dbak[MAXN];
int map[MAXN][MAXN], n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &map[i][j]);
			cli[i][j] = map[i][j];
			dli[j][i] = map[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		cbak[i] = m;
		std::sort(cli[i] + 1, cli[i] + 1 + cbak[i]);
		cbak[i] = std::unique(cli[i] + 1, cli[i] + 1 + cbak[i]) - cli[i] - 1;
	}
	for (int i = 1; i <= m; ++i) {
		dbak[i] = n;
		std::sort(dli[i] + 1, dli[i] + 1 + dbak[i]);
		dbak[i] = std::unique(dli[i] + 1, dli[i] + 1 + dbak[i]) - dli[i] - 1;
	}
	for (int i = 1; i <= n; ++i, putchar(10))
		for (int j = 1; j <= m; ++j) {
			int cma = cbak[i], dma = dbak[j];
			int cv =  std::lower_bound(cli[i] + 1, cli[i] + 1 + cbak[i], map[i][j]) - cli[i];
			int dv =  std::lower_bound(dli[j] + 1, dli[j] + 1 + dbak[j], map[i][j]) - dli[j];
			printf("%d ", 1 + std::max(cma - cv, dma - dv) + std::max(cv - 1, dv - 1));
		}
	return 0;
}