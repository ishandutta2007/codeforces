#include<stdio.h>
#include<algorithm>
using namespace std;
int x[12121212];
int main() {
	int t, tc; scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		int n, m, a, b; scanf("%d%d%d%d", &n, &m, &a, &b);
		int i, j;
		for (i = 0; i < m; i++)scanf("%d", &x[i]);
		sort(x, x + m);
		if (a > b) {
			a = n + 1 - a;
			b = n + 1 - b;
		}
		int s = 1, e = min(m, b - a - 1), ans = 0;;
		while (s <= e) {
			int m = (s + e) / 2;
			int flag = 1;
			for (i = 0, j = m; i < m; i++, j--) {
				if (x[i] + j > b - 1) {
					flag = 0;
				}
			}
			if (flag) {
				s = m + 1;
				ans = m;
			}
			else {
				e = m - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}