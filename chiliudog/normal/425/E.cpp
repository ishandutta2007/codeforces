#include <cstdio>
using namespace std;

#define P 1000000007

int n, k, i, j, p, ans, dp[510][510], mi2[510000];

__attribute__((optimize("O2"))) int main() {
	scanf("%d%d", &n, &k);
	dp[0][0] = 1;
	for (mi2[0] = 1, i = 1; i <= n * n; i++)	mi2[i] = 2 * mi2[i - 1] % P;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= k; j++)
			for (p = 0; p < i; p++)
				dp[i][j] = (dp[i][j] + 1LL * dp[p][j - 1] * (mi2[i - p] - 1) % P * mi2[(i - p) * (n - i)] ) % P;

	for (i = 0; i <= n; i++)
		ans = (ans + dp[i][k]) % P;
	printf("%d\n", (ans + P) % P);
}