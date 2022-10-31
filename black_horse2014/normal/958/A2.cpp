#include <bits/stdc++.h>
using namespace std;

const int N = 2200;
const int MOD = 1e9+9;

int dp[N], S[N], T[N];
char s[N][N], t[N][N];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= m; i++) scanf("%s", t[i] + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) dp[i] = (dp[i] * 26LL + s[i][j] - '0') % MOD;
	}
	int p = 1;
	for (int j = 1; j <= m; j++) p = p * 26LL % MOD;
	for (int i = 1; i <= n - m + 1; i++) {
		for (int j = i; j <= i + m - 1; j++) S[i] = (S[i] * 1LL * p + dp[j]) % MOD;
	}
	
	for (int j = 1; j <= n; j++) {
		dp[j] = 0;
			for (int i = 1; i <= m; i++) dp[j] = (dp[j] * 1LL * p + t[i][j] - '0') % MOD;
	}
	for (int j = 1; j <= n - m + 1; j++) {
		for (int i = j; i <= j + m - 1; i++) T[j] = (T[j] * 26LL + dp[i]) % MOD;
	}
	for (int i = 1; i <= n - m + 1; i++)
		for (int j = 1; j <= n - m + 1; j++) if (S[i] == T[j]) {
			printf("%d %d\n", i, j);
			return 0;
		}
}