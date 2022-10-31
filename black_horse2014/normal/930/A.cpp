#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp[N], cnt[N];
int main() {
	int n; scanf("%d", &n);
	dp[1] = 1;
	cnt[1]++;
	for (int i = 2; i <= n; i++) {
		int x; scanf("%d", &x);
		dp[i] = dp[x] + 1;
		cnt[dp[i]]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += cnt[i] % 2;
	printf("%d\n", ans);
	return 0;
}