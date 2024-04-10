#include <iostream>
using namespace std;

long long N, M, A, B, fact[1000009], inv[1000009], power[1000009], mod = 1000000007;

long long modpow(int a, int b, int m) {
	int p = 1, q = a;
	for (int i = 0; i < 31; i++) {
		if ((b&(1 << i)) != 0) { p = (1LL * p * q) % m; }
		q = (1LL * q * q) % m;
	}
	return p;
}

void init() {
	fact[0] = 1; for (int i = 1; i <= 1000000; i++) fact[i] = (fact[i - 1] * i) % mod;
	for (int i = 0; i <= 1000000; i++) inv[i] = modpow(fact[i], mod - 2, mod);
}

long long ncr(long long n, long long r) {
	if (r < 0 || n < r) return 0;
	return (fact[n] * inv[r] % mod) * inv[n - r] % mod;
}

int main() {
	init();
	cin >> N >> M >> A >> B;
	power[0] = 1; for (int i = 1; i <= N; i++) { power[i] = (1LL * power[i - 1] * M) % mod; }

	long long sum = 0;
	for (int i = 1; i <= N - 1; i++) {
		long long V1 = ncr(M - 1, i - 1);
		long long V2 = ncr(N - 2, i - 1) * fact[i - 1]; V2 %= mod;
		long long V3 = 1LL * (i + 1) * modpow(N, N - (i + 1) - 1, mod); if (i == N - 1) V3 = 1; V3 %= mod;
		long long V4 = power[N - (i + 1)];
		long long A = (V1 * V2 % mod) * (V3 * V4 % mod) % mod;
		sum += A; sum %= mod;
	}
	cout << sum << endl;
	return 0;
}