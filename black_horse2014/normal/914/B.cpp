#include <bits/stdc++.h>
using namespace std;

int a[110000];
int dp[110000];
int chk[110000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int j = lower_bound(a, a + n, a[i]) - a + 1;
		chk[j] = 1;
	}
	bool seen = !chk[n];
	for (int i = n-1; i >= 0; i--) {
		if (i == n-1) {
			dp[i] = 1;
		}
		else {
			if (!dp[i+1]) {
				dp[i] = 1;
			} else if (!seen) {
				dp[i] = 1;
			}
		}
		if (chk[i]) seen &= dp[i];
	}
	puts(dp[0] ? "Conan" : "Agasa");
	return 0;
}