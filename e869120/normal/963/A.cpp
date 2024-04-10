#include <iostream>
#include <map>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

map<long long, long long>Map;
const long long mod = 1000000009;

long long sum_of_power(long long B, long long K) {
	if (K == 1) return 1;
	if (Map[B] >= 1) return Map[B] - 1;

	long long ret = 0;
	if (K % 2 == 0) {
		long long E1 = sum_of_power(B, K / 2);
		E1 *= (1LL + modpow(B, K / 2, mod));
		E1 %= mod;
		ret = E1;
	}
	else {
		long long E1 = sum_of_power(B, K / 2);
		E1 *= (1LL + modpow(B, (K + 1) / 2, mod));
		E1 += modpow(B, K / 2, mod);
		E1 %= mod;
		ret = E1;
	}
	Map[B] = ret + 1;
	return ret;
}

int main() {
	long long N, A, B, K, ret = 0; string S;
	cin >> N >> A >> B >> K >> S;

	long long F = modpow(Div(B, A, mod), K, mod);
	long long G = sum_of_power(F, (N + 1) / K);

	for (int i = 0; i < S.size(); i++) {
		long long V1 = modpow(A, N - i, mod);
		long long V2 = modpow(B, i, mod);
		if (S[i] == '+') ret += V1 * V2;
		if (S[i] == '-') ret -= V1 * V2;
		ret += mod * mod; ret %= mod;
	}
	cout << (ret*G) % mod << endl;
	return 0;
}