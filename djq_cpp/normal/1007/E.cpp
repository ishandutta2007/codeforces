#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int n, t, s;
LL a[205], b[205], c[205];
LL pa[205], pb[205];
LL dp[205][205], ldp[205][205], rdp[205][205], ans[205][205], tmp[205];

int main()
{
	scanf("%d%d%d", &n, &t, &s);
	rep(i, n) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	a[n] = c[n] = INF / 10; n ++;
	rep(i, n) pb[i + 1] = pb[i] + b[i];
	rep(i, n) pa[i + 1] = pa[i] + a[i];
	
	rep1(i, n) rep1(j, t) {
		rdp[i][j] = dp[i][j] = tmp[j] = INF;
		rep1(k, j) if(tmp[j - k] != INF) {
			LL cur = tmp[j - k] + dp[i - 1][k], rem0 = pb[i] * (j - k) - tmp[j - k] * s, rem1 = dp[i - 1][k] * s - pb[i] * k;
			LL cur0 = (max(rem0 + 1LL * b[i - 1] * k - c[i - 1], 0LL) + s - 1) / s;
			if(j == k ? (cur0 > 0) : (cur0 * s >= rem0)) continue;
			cur += cur0;
			rem0 -= rem1 + cur0 * s;
			if(rem0 > 0) {
				tmp[j] = min(tmp[j], cur);
				dp[i][j] = min(dp[i][j], cur + (rem0 + s - 1) / s);
			} else dp[i][j] = min(dp[i][j], cur);
			rdp[i][j] = min(rdp[i][j], tmp[j - k] + rdp[i - 1][k] + cur0);
		}
	}
	
	rep1(i, n) for(int j = 0; j <= t; j ++) {
		ans[i][j] = ldp[i][j] = tmp[j] = INF;
		if(a[i - 1] + b[i - 1] * j <= c[i - 1]) ans[i][j] = ans[i - 1][j];
		LL cur = ldp[i - 1][j], rem0 = a[i - 1], rem1 = ldp[i - 1][j] * s - pb[i] * j;
		LL cur0 = (max(rem0 + 1LL * b[i - 1] * j - c[i - 1], 0LL) + s - 1) / s;
		if(cur0 * s <= rem0) {
			cur += cur0;
			rem0 = pa[i] - rem1 - cur0 * s;
			if(rem0 > 0) {
				tmp[j] = cur; ldp[i][j] = cur + (rem0 + s - 1) / s;
			} else ldp[i][j] = cur;
		}
		rep1(k, j) if(tmp[j - k] != INF) {
			LL cur = tmp[j - k] + dp[i - 1][k], rem0 = pa[i] + pb[i] * (j - k) - tmp[j - k] * s, rem1 = dp[i - 1][k] * s - pb[i] * k;
			LL cur0 = (max(rem0 + 1LL * b[i - 1] * k - c[i - 1], 0LL) + s - 1) / s;
			if(cur0 * s >= rem0) continue;
			cur += cur0;
			rem0 -= rem1 + cur0 * s;
			if(rem0 > 0) {
				tmp[j] = min(tmp[j], cur);
				ldp[i][j] = min(ldp[i][j], cur + (rem0 + s - 1) / s);
			} else ldp[i][j] = min(ldp[i][j], cur);
			ans[i][j] = min(ans[i][j], tmp[j - k] + rdp[i - 1][k] + cur0);
		}
	}
	
	printf("%lld\n", ans[n][t]);
	return 0;
}