#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, Q, dp[500009][23];

long long query(long long x, long long y) {
	long long s = 0;
	for (int i = 22; i >= 0; i--) {
		if (dp[x][i] < y) { s += (1 << i); x = dp[x][i]; }
	}
	if (s >= (1 << 22)) return -1;
	return s + 1;
}

int main() {
	scanf("%lld%lld", &N, &Q);
	for (int i = 0; i < N; i++) {
		long long a1, a2; scanf("%lld%lld", &a1, &a2);
		dp[a1][0] = max(dp[a1][0], a2);
	}
	for (int i = 0; i <= 500000; i++) dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j <= 500000; j++) dp[j][i + 1] = dp[dp[j][i]][i];
	}

	long long X, Y;
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &X, &Y);
		printf("%lld\n", query(X, Y));
	}
	return 0;
}