#include <bits/stdc++.h>

#define MAXN (100010)

int n, U;
int e[MAXN];

int main() {
	scanf("%d%d", &n, &U);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", e + i);
	}
	bool flag = false;
	double ans = 0;
	for (int i = 0, k = i + 2; i < n && k < n; ++ i) {
		while (k + 1 < n && e[k + 1] - e[i] <= U) {
			++ k;
		}
		if (i + 1 < k && e[k] - e[i] <= U) {
			flag = true;
			ans = std::max(ans, 1 - 1.0 * (e[i + 1] - e[i]) / (e[k] - e[i]));
		}
	}
	if (flag) {
		printf("%.10lf\n", ans);
	}
	else {
		printf("-1\n");
	}
	return 0;
}