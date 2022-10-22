#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 998244353;
int dp[MN], num[MN];
bool comp[MN];
int main () {
	int n; scanf ("%d",&n);
	for (int i = 2; i <= n; i++) num[i] = 1;
	for (int i = 2; i <= n; i++) if (!comp[i]) {
		int ex = 0;
		for (long long pw = i; pw <= n; pw *= i) {
			++ex;
			for (long long j = pw; j <= n; j += pw) if (j % (pw * i) != 0) {
				num[j] = (long long)num[j] * (ex+1) % MOD;
				comp[j] = 1;
			}
		}
	}
	int sum = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = sum + num[i];
		if (dp[i] >= MOD) dp[i] -= MOD;
		sum += dp[i];
		if (sum >= MOD) sum -= MOD;
	}
	printf ("%d\n",dp[n]);
	return 0;
}