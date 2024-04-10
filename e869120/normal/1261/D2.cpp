#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b & (1LL << i)) != 0) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

long long mod = 998244353;
long long fact[1 << 18], factinv[1 << 18];
long long N, K, A[1 << 18];

void init() {
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++) fact[i] = (1LL * i * fact[i - 1]) % mod;
	for (int i = 0; i <= 200000; i++) factinv[i] = Div(1, fact[i], mod);
}

long long ncr(long long n, long long r) {
	if (n < r || r < 0) return 0;
	return (fact[n] * factinv[r] % mod) * factinv[n - r] % mod;
}

long long solve(long long a, long long b) {
	if (a == 0) return 0;

	long long r = 0;
	for (int i = 0; i <= a; i++) {
		long long s1 = ncr(a, i);
		long long s2 = modpow(b - 2, a - i, mod);
		long long s3 = modpow(2, i, mod);
		if (i % 2 == 0) { s3 -= ncr(i, i / 2); s3 = (s3 + mod) % mod; }
		s3 = Div(s3, 2, mod);

		long long ss = (s1 * s2 % mod) * s3 % mod;
		r += ss; r %= mod;
	}
	return r;
}

int main() {
	init();

	scanf("%lld%lld", &N, &K);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

	long long cnt = 0;
	for (int i = 0; i < N; i++) { if (A[i] == A[(i + 1) % N]) cnt++; }

	long long v1 = solve(N - cnt, K);
	long long v2 = modpow(K, cnt, mod);
	cout << (v1 * v2) % mod << endl;
	return 0;
}