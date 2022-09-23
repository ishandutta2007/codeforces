#include <stdio.h>

long long MAX(long long a, long long b) {
	return a > b ? a : b;
}

long long dp[3][100005];
long long num[100005], p, q, r;

int main() {
	int N; scanf("%d", &N);
	scanf("%lld %lld %lld", &p, &q, &r);
	for(int i = 0; i < N; i++) {
		scanf("%lld", &num[i]);
	}

	dp[0][0] = p * num[0]; dp[1][0] = (p + q) * num[0]; dp[2][0] = (p + q + r) * num[0];
	for(int i = 1; i < N; i++) {
		dp[0][i] = MAX(dp[0][i - 1], p * num[i]);
	}
	for(int i = 1; i < N; i++) {
		dp[1][i] = MAX(dp[1][i - 1], q * num[i] + dp[0][i]);
	}
	for(int i = 1; i < N; i++) {
		dp[2][i] = MAX(dp[2][i - 1], r * num[i] + dp[1][i]);
	}

	printf("%lld", dp[2][N - 1]);
	return 0;
}