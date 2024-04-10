#include <stdio.h>
double dp[2050][2050];
int main() {
	int N, T, i, j;
	double P2;
	scanf("%d %lf %d", &N, &P2, &T);
	dp[0][0] = 1;
	for(i = 1; i <= T; i++) {
		dp[i][0] = (1-P2) * dp[i-1][0];
		dp[i][i] = P2 * dp[i-1][i-1];
		for(j = 1; j < i; j++) dp[i][j] = (1-P2)*dp[i-1][j] + P2 * dp[i-1][j-1];
	}
	double ANS = 0;
	for(i = 0; i <= N; i++) ANS += i * dp[T][i];
	for(i = N+1; i <= T; i++) ANS += N * dp[T][i];
	printf("%lf", ANS);
	return 0;
}