#include <stdio.h>

long long dp[35][35];
long long c[35];
long long INF = 1e18 + 5;

long long min_(long long a, long long b) { return a < b ? a : b; }

long long f(int L, int d, int n) {
	if(dp[d][n] != INF) return dp[d][n];
	if(d < 0) return 0;
	if((L & (1 << d)) == 0) return dp[d][n] = f(L, d - 1, n);
	int i;
	for(i = n - 1; i >= 0; i--) {
		if((1 << i) <= L) break;
		dp[d][n] = min_(dp[d][n], c[i]);
	}
	int k; for(k = 30; k >= 0; k--) if((1 << k) <= L) break;
	for(; i >= 0; i--) {
		dp[d][n] = min_(dp[d][n], c[i] * (1 << (k - i)) + f(L - (1 << k), d - 1, n));
	}
	return dp[d][n];
}

int main() {
	int n, L; scanf("%d %d", &n, &L);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &c[i]);
	}
	for(int i = 0; i < 35; i++) for(int j = 0; j < 35; j++) {
		dp[i][j] = INF;
	}

	printf("%lld", f(L, 30, n));

	return 0;
}