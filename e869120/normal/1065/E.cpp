#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

const long long mod = 998244353;
long long N, M, A, B[200009];

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 31; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

int main() {
	scanf("%lld%lld%lld", &N, &M, &A);
	for (int i = 1; i <= M; i++) scanf("%lld", &B[i]);

	long long ret = 1;
	for (int i = 1; i <= M; i++) {
		long long E = B[i] - B[i - 1];
		long long F1 = modpow(A, 2 * E, mod);
		long long F2 = modpow(A, E, mod);
		long long F3 = F1 + F2; if (F3 % 2 == 1) F3 += mod; F3 /= 2;
		ret *= F3;
		ret %= mod;
	}
	ret *= modpow(A, N - 2LL * B[M], mod);
	ret %= mod;
	cout << ret << endl;
	return 0;
}