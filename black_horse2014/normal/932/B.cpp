#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int g(int x) {
	int ret = 1;
	while(x) {
		if (x % 10) ret *= (x % 10);
		x /= 10;
	}
	return ret;
}

int dp[N][10];

int main() {
	for (int i = 1; i < N; i++) {
		int x = i;
		while (x >= 10) x = g(x);
		for (int j = 1; j <= 9; j++)  dp[i][j] = dp[i - 1][j];
		dp[i][x]++;
	}
	int Q; scanf("%d", &Q);
	while (Q--) {
		int l, r, x; scanf("%d%d%d", &l, &r, &x);
		printf("%d\n", dp[r][x] - dp[l - 1][x]);
	}
	return 0;
}