#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int modExp(int a, int n) {
	int ret = 1;
	for (a %= MOD; n; n >>= 1, a = 1LL * a * a % MOD) if (n & 1) ret = 1LL * ret * a % MOD;
	return ret;
}

int solve(int A1, int B1, int C1, int A2, int C2, int D, int E, int F) {
	if (F == 0) return 0;
	if (E >= F) return 1LL * modExp((MOD + 1) / 2, C2 * (E / F)) * solve(A1, (B1 + 1LL * C1 * (E / F)) % MOD, C1, A2, C2, D, E % F, F) % MOD;
	if (D >= F) return solve((A1 + 1LL * C1 * (D / F)) % MOD, B1, C1, A2 + C2 * (D / F), C2, D % F, E, F);
	int u = modExp(2, A2);
	int v = modExp(1 - u + MOD, MOD - 2);
	if (D == 0) return (1LL * v * v % MOD * u % MOD * A1 + 1LL * (MOD - v) * u % MOD * B1) % MOD;
	int w = (1 + MOD - modExp(2, MOD - 1 - C2)) % MOD;
	int x = 1LL * v * w % MOD;
	int ret = 1LL * (v - 1) * (MOD - B1 + 1LL * A1 * v % MOD) % MOD;
	A1 = 1LL * x * A1 % MOD, C1 = 1LL * v * C1 % MOD, B1 = (1LL * x * B1 + 1LL * A1 * (1 + MOD - v) + 1LL * (w - 1) * C1) % MOD;
	ret = (ret + solve(1LL * C1 * w % MOD, B1, A1, C2, A2, F, F - E - 1, D)) % MOD;
	return ret;
}

int calc(int n, int k) {
	int g = __gcd(n, k); n /= g, k /= g;
	int r = n % k;
	return ((3LL * (n + r) - k) * (n - r) / k + solve(MOD - k, 2 * r, r, 0, 1, k, 0, r) + MOD - 2 * r) % MOD * modExp(n, MOD - 2) % MOD;
}

int main() {
	int ncase, n, k; cin >> ncase;
	while (ncase--) {
		cin >> n >> k;
		cout << (1 + 1LL * calc(n, k) * (MOD + 1) / 2) % MOD << endl;
	}
	return 0;
}