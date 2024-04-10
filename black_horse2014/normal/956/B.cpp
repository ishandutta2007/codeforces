#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int e[N];

int main() {
	int n, U; scanf("%d%d", &n, &U);
	for (int i = 1; i <= n; i++) scanf("%d", e + i);
	double ans = 0;
	bool flg = false;
	for (int i = 1; i <= n; i++) {
		int lo = i + 2, hi = n, mid;
		if (lo > hi) continue;
		if (e[lo] - e[i] > U) continue;
		while (lo < hi) {
			mid = (lo + hi + 1) >> 1;
			if (e[mid] - e[i] <= U) lo = mid;
			else hi = mid - 1;
		}
		flg = true;
		ans = max(ans, 1.0 * (e[lo] - e[i + 1]) / (e[lo] - e[i]));
	}
	if (!flg) return puts("-1"), 0;
	printf("%.20lf\n", ans);
	return 0;
}