#include <bits/stdc++.h>

int n, m, q;
int w[20];
char s[20];
int cnt[4096], val[4096];
int ans[4096][200];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = n - 1; i >= 0; --i) {
		scanf("%d", w + i);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%s", s);
		int num = 0;
		for (int j = 0; j < n; ++j) {
			num = num * 2 + s[j] - '0';
		}
		++ cnt[num];
	}
	for (int i = 1; i < (1 << n); ++i) {
		int j;
		for (j = 0; ((i >> j) & 1) == 0; ++j);
		val[i] = val[i ^ (1 << j)] + w[j];
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			if (cnt[j] == 0) continue;
			int k = i ^ j;
			k = (~k) & ((1 << n) - 1);
			k = val[k];
			if (k > 100) continue;
			ans[i][k] += cnt[j];
		}
		for (int j = 1; j <= 100; ++ j) ans[i][j] += ans[i][j - 1];
	}
	while (q --) {
		scanf("%s", s);
		int num = 0;
		for (int j = 0; j < n; ++j) num = num * 2 + s[j] - '0';
		int k;
		scanf("%d", &k);
		printf("%d\n", ans[num][k]);
	}
	return 0;
}