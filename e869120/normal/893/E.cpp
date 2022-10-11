#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 1000000;
long long Q, X, Y, c[1000009], power[1000009], mod = 1000000007;
int dp[22][1000009];
vector<pair<int, int>> G[MAX_N + 9];

void init() {
	power[0] = 1; for (int i = 1; i <= MAX_N; i++) power[i] = (2LL * power[i - 1] % mod);
	for (int i = 0; i <= 21; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			if (i == 0 || j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	for (int i = 1; i <= MAX_N; i++) c[i] = i;
	for (int i = 2; i <= MAX_N; i++) {
		for (int j = i; j <= MAX_N; j += i) {
			int cnt = 0;
			while (c[j] % i == 0) { c[j] /= i; cnt++; }
			if (cnt >= 1) G[j].push_back(make_pair(i, cnt));
		}
	}
}

long long ncr(long long n, long long r) {
	return dp[r][n - r];
}

int main() {
	init();
	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &X, &Y);
		long long ans = 1;
		for (int j = 0; j < G[X].size(); j++) {
			long long E = ncr(Y + G[X][j].second - 1, G[X][j].second);
			ans *= E; ans %= mod;
		}
		ans *= power[Y - 1]; ans %= mod;
		printf("%lld\n", ans);
	}
	return 0;
}