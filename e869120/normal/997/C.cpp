#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 1000009;
const long long mod = 998244353;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long N, fact[MAX_N], factinv[MAX_N];

void init() {
	fact[0] = 1;
	for (int i = 1; i <= 1000000; i++) fact[i] = (1LL * fact[i - 1] * i) % mod;
	for (int i = 0; i <= 1000000; i++) factinv[i] = modpow(fact[i], mod - 2, mod);
}

long long ncr(long long n, long long r) {
	if (r < 0 || n < r) return 0;
	return (fact[n] * factinv[r] % mod) * factinv[n - r] % mod;
}

int main() {
	cin >> N; init();
	long long V1 = modpow(modpow(3, N, mod), N, mod) - modpow((modpow(3, N, mod) - 3LL + mod), N, mod);
	V1 += mod; V1 *= 2LL; V1 %= mod;

	long long V2 = 0;
	for (int i = 1; i <= N; i++) {
		long long E1 = ncr(N, i);
		long long E2 = modpow(3, N - i, mod);
		long long E3 = (E2 + mod - 1) % mod;
		E2 = modpow(E2, N, mod);
		E3 = modpow(E3, N, mod);
		if (i % 2 == 1) V2 += E1 * (E2 - E3 + mod);
		if (i % 2 == 0) V2 -= E1 * (E2 - E3 + mod);
		while (V2 < 0) V2 += mod * mod;
		V2 %= mod;
	}
	V2 *= 3LL; V2 %= mod;

	cout << (V1 - V2 + mod) % mod << endl;
	return 0;
}