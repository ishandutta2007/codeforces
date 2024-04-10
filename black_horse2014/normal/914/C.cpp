#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
const int MOD = 1e9 + 7;

char s[N];
int dp[N], C[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%s", s);
	int k; scanf("%d", &k);
	int ans = 0;
	if (k == 0) {
		ans = 1;
	} else if (k == 1) {
		ans = strlen(s) - 1;
	}
	if (k < 2) {
		cout << ans << endl;
		return 0;
	}
	for (int i = 2; i <= 1000; i++) dp[i] = dp[__builtin_popcount(i)] + 1;
	int n = strlen(s);
	for (int i = 0; i < 1000; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			for (int j = 0; j <= n-i-1; j++) {
				if (cur + j > 1 && dp[cur + j] == k-1) {
					ans = (ans + C[n-i-1][j]) % MOD;
				}
			}
			cur++;
		}
	}
	if (dp[cur] == k-1) ans = (ans + 1) % MOD;
	cout << ans << endl;
	return 0;
}