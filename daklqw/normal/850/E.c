#include <stdio.h>
#include <string.h>

const int mod = 1000000007;
typedef long long LL;
void reduce(int * x) { *x += *x >> 31 & mod; }

int n, A[1 << 20];
void FWT() {
	for (int mid = 1; mid != (1 << n); mid <<= 1)
		for (int k = 0; k != (1 << n); k += mid << 1)
			for (int l = 0; l != mid; ++l) {
				const int Y = A[l + k + mid];
				A[l + k + mid] = A[l + k] - Y;
				A[l + k] += Y - mod;
				reduce(A + l + k), reduce(A + l + k + mid);
			}
}

int main() {
	static char buf[1 << 20 | 10];
	scanf("%d%s", &n, buf);
	for (int i = 0; i != (1 << n); ++i) A[i] = buf[i] & 1;
	FWT();
	for (int i = 0; i != (1 << n); ++i) A[i] = (LL) A[i] * A[i] % mod;
	int inv2 = mod + 1 >> 1, liminv = 1;
	for (int i = 0; i != n; ++i) liminv = (LL) liminv * inv2 % mod;
	FWT();
	for (int i = 0; i != (1 << n); ++i) A[i] = (LL) A[i] * liminv % mod;
	int ans = 0;
	for (int i = 0; i != (1 << n); ++i)
		ans = (ans + ((LL) A[i] << (n - __builtin_popcount(i)))) % mod;
	ans = ans * 3ll % mod;
	printf("%d\n", ans);
	return 0;
}