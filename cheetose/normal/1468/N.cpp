#include<stdio.h>
int main() {
	int t, tc; scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		int A, B, C; scanf("%d%d%d", &A, &B, &C);
		int a, b, c, d, e; scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		A -= a; B -= b; C -= c;
		if (A < 0 || B < 0) {
			puts("NO");
			continue;
		}
		if (A > 0)d -= A;
		if (B > 0)e -= B;
		if (d > 0)C -= d;
		if (e > 0)C -= e;
		if (C < 0)puts("NO");
		else puts("YES");
	}
	return 0;
}