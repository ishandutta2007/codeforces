#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 20;
const int MAXM = 100010;
typedef long long LL;
int n, m;
LL A[1 << MAXN], B[1 << MAXN];
char buf[MAXN][MAXM];
void FWT(LL * A) {
	const int lim = 1 << n;
	for (int mid = 1; mid != lim; mid <<= 1)
		for (int k = 0; k != lim; k += mid << 1)
			for (int l = 0; l != mid; ++l) {
				const LL X = A[l + k], Y = A[l + k + mid];
				A[l + k] = X + Y;
				A[l + k + mid] = X - Y;
			}
}
int main() {
	scanf("%d%d", &n, &m);
	const int lim = 1 << n;
	for (int i = 0; i != n; ++i) scanf("%s", buf[i]);
	for (int i = 0; i != m; ++i) {
		int vec = 0;
		for (int j = 0; j != n; ++j)
			vec |= buf[j][i] - '0' << j;
		++A[vec];
	}
	for (int i = 0; i != lim; ++i) {
		const int ppc = __builtin_popcount(i);
		B[i] = std::min(ppc, n - ppc);
	}
	FWT(A); FWT(B);
	for (int i = 0; i != lim; ++i) A[i] *= B[i];
	FWT(A);
	LL ans = 0x3f3f3f3f3f3f3f3fLL;
	for (int i = 0; i != lim; ++i)
		ans = std::min(ans, A[i] >> n);
	printf("%lld\n", ans);
	return 0;
}