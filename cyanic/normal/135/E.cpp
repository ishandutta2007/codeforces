#include<cstdio>

const int maxn = 1000009, MOD = 1000000007;
int fac[maxn], rev[maxn], K, w, ans;

int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p&1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}

void init() {
	fac[0] = rev[0] = 1;
	for (int i=1; i<=K; i++) {
		fac[i] = 1LL * fac[i-1] * i % MOD;
		rev[i] = power(fac[i], MOD - 2);
	}
}

int A(int n, int m) {
	if (n < 0 || m < 0 || m > n) return 0;
	return 1LL * fac[n] * rev[n-m] % MOD;
}

int main() {
	scanf("%d%d", &K, &w); init(); 
	for (int L=1; L<=K; L++) {
		if (w - L >= 2)
			ans = (ans + 1LL * (1LL * A(K, L) * A(K, L) % MOD * K % MOD * K % MOD - 1LL * A(K, L + 1) * A(K, L + 1) % MOD + MOD) * power(K, w - L - 2)) % MOD;
		else if (w - L == 1)
			ans = (ans + 1LL * A(K, L) * A(K, L) % MOD * K % MOD - 1LL * A(K, L + 1) * A(K - 1, L) % MOD + MOD) % MOD;
		else
			ans = (ans + 1LL * A(K, L - w) * A(K - L + w, w) % MOD * A(K - L + w, w) % MOD - 1LL * A(K, L - w + 2) * A(K - L + w - 2, w - 1) % MOD * A(K - L + w - 2, w - 1) % MOD + MOD) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}