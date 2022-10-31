#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	while (n--){
		long long k, x; scanf("%lld%lld", &k, &x);
		printf("%lld\n", 9 * (k - 1) + x);
	}
	return 0;
}

/*
int dp[105];

int S(int k) {
	if (dp[k]) return dp[k];
	if (k < 10) return dp[k] = k;
	int p = k, sum = 0;
	while (p > 0) {
		sum += p % 10;
		p /= 10;
	}
	return dp[k] = S(sum);
}

int main() {
	for (int i = 1; i <= 100; i++)
		S(i), printf("S(%d): %d\n", i, dp[i]);
	return 0;
}
*/