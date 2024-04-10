#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p & 1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}

int f(int n) {
	if (n <= 1) return 4 * n;
	if (n & 1) return (11LL * power(3, n / 2) + MOD - 7) % MOD;
	return (19LL * power(3, n / 2 - 1) + MOD - 7) % MOD;
}

int g(int s) {
	return 1LL * (f(s) + f((s+1) / 2)) * (MOD + 1) / 2 % MOD;
}

int main() {
	int L, R; scanf("%d%d", &L, &R);
	printf("%d\n", (g(R) - g(L-1) + MOD) % MOD);
	return 0;
}