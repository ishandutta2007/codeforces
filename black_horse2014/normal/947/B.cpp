#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
int v[N], t[N], dp[N];
long long s[N], ans[N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", v + i);
	for (int i = 1; i <= n; i++) scanf("%d", t + i), s[i] = s[i - 1] + t[i];
	
	for (int i = 1; i <= n; i++) {
		
		int p = upper_bound(s + i, s + n + 1, v[i] + s[i - 1]) - s - 1;
		dp[i]++;
		dp[p + 1]--;
		long long rem = v[i] - (s[p] - s[i - 1]);
		ans[p + 1] += rem;
	}
	for (int i = 1; i <= n; i++) {
		dp[i] += dp[i - 1];
		ans[i] += 1LL * t[i] * dp[i];
		printf("%lld%c", ans[i], " \n"[i == n]);
	}
	return 0;
}