#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>

const int MAXN = 5010;
int n;
char A[MAXN], B[MAXN];
int li[4][MAXN], bak[4];

int main() {
	scanf("%d", &n);
	scanf("%s%s", A + 1, B + 1);
	for (int i = 1; i <= n; ++i) {
		const int state = (A[i] & 1) | (B[i] & 1) << 1;
		li[state][++bak[state]] = i;
	}
	for (int i = 0; i <= bak[1]; ++i)
		for (int j = 0; j <= bak[2]; ++j) {
			int hv1 = - bak[2] + j + i;
			if ((hv1 + bak[3]) % 2 != 0) continue;
			int li11 = (bak[3] - hv1) / 2;
			if (li11 < 0 || li11 > bak[3]) continue;
			int rest = n / 2 - li11 - i - j;
			if (rest < 0 || rest > bak[0]) continue;
			for (int k = 1; k <= rest; ++k) printf("%d ", li[0][k]);
			for (int k = 1; k <= i; ++k) printf("%d ", li[1][k]);
			for (int k = 1; k <= j; ++k) printf("%d ", li[2][k]);
			for (int k = 1; k <= li11; ++k) printf("%d ", li[3][k]);
			putchar(10);
			return 0;
		}
	puts("-1");
	return 0;
}