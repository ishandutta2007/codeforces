#include <bits/stdc++.h>
using namespace std;

const int N = 11000;

pair<int, int> a[N];
int dp[2][2][N];

int main() {
	int n, l, r; scanf("%d%d%d", &n, &l, &r);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].second);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].first), a[i].first ^= 1;
	sort(a + 1, a + n + 1);
	int ans = 0, now = 0;
	dp[0][1][0] = 1;
	int sum = 0, cur = 0;
	for (int i = 1; i <= n; i++) if (a[i].first == 0) cur += a[i].second;
	for (int i = n; i > 0; i--) {
		now ^= 1;
		int x = a[i].second;
		if (a[i].first == 0) {
			if (cur <= r - l) {
				for (int s = l; s <= r - cur; s++) {
					if (dp[!now][0][s]) {
						ans = max(ans, i + 1);
					}
					if (dp[!now][1][s]) {
						ans = max(ans, i);
					}
				}
			}
			cur -= a[i].second;
		}
		for (int j = 0; j <= sum + x; j++) {
			for (int k = 0; k < 2; k++) dp[now][k][j] = 0;
			if (a[i].first != 0) {
				for (int k = 0; k < 2; k++) dp[now][k][j] = dp[!now][k][j];
			} else {
				dp[now][0][j] = dp[!now][0][j] | dp[!now][1][j];
			}
		}
		for (int j = x; j <= sum + x; j++) for (int k = 0; k < 2; k++) dp[now][k][j] |= dp[!now][k][j - x];
		sum += x;
	}
	for (int s = l; s <= r; s++) {
		if (dp[now][0][s]) {
			ans = max(ans, 1);
		}
	}
	cout << ans << endl;
	return 0;
}