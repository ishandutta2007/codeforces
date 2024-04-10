#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[1 << 18], dp[1 << 18][2], mod = 998244353;
vector<pair<int, int>> K1, K2;

void init() {
	dp[0][0] = 1;
	for (int i = 0; i < 220000; i++) {
		dp[i + 1][0] += dp[i][1]; dp[i + 1][0] %= mod;
		dp[i + 1][1] += dp[i][0] * (K - 1); dp[i + 1][1] %= mod;
		dp[i + 1][1] += dp[i][1] * (K - 2); dp[i + 1][1] %= mod;
	}
}

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 31; i++) {
		if ((b / (1 << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a*modpow(b, m - 2, m)) % m;
}

long long solve(int len, vector<pair<int, int>>vec) {
	if (vec.size() == 0) {
		long long t = K;
		for (int i = 0; i < len - 1; i++) { t *= (K - 1); t %= mod; }
		return t;
	}

	long long p1 = dp[vec[0].second - 1][0] + dp[vec[0].second - 1][1];
	long long p2 = dp[len - vec[vec.size() - 1].second][0] + dp[len - vec[vec.size() - 1].second][1];
	long long p3 = 1;
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i].first == vec[i + 1].first) p3 *= dp[vec[i + 1].second - vec[i].second][0];
		else p3 *= Div(dp[vec[i + 1].second - vec[i].second][1], K - 1, mod);
		p3 %= mod;
	}
	return (p1*p2%mod)*p3%mod;
}

int main() {
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		if (A[i] != -1) {
			if (i % 2 == 1) K1.push_back(make_pair(A[i], (i + 1) / 2));
			else K2.push_back(make_pair(A[i], i / 2));
		}
	}

	init();

	long long V1 = solve((N + 1) / 2, K1);
	long long V2 = solve(N / 2, K2);
	cout << (V1*V2) % mod << endl;
	return 0;
}