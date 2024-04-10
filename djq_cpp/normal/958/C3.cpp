#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, a[500005], k, p;
int psum[500005];
int nxtp[500005][105];
int dp[105][105][105];
int cur[105], cnt;

int main()
{
	scanf("%d%d%d", &n, &k, &p);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) psum[i + 1] = (psum[i] + a[i]) % p;
	for(int i = 0; i <= p; i ++) nxtp[n][i] = INF;
	for(int i = n; i >= 1; i --) {
		for(int j = 0; j <= p; j ++) nxtp[i - 1][j] = nxtp[i][j];
		nxtp[i - 1][psum[i]] = i;
	}
	memset(dp, INF, sizeof(dp));
	dp[0][0][0] = 0;
	rep(i, k) for(int j = 0; j <= i; j ++) {
		rep1(d0, p) dp[i][j][d0] = min(dp[i][j][d0], dp[i][j][d0 - 1]);
		for(int d1 = 0; d1 <= p; d1 ++) {
			if(dp[i][j][d1] != INF) dp[i + 1][j][d1] = min(dp[i + 1][j][d1], nxtp[dp[i][j][d1]][d1]);
			if(dp[i][j][p] != INF) dp[i + 1][j + 1][d1] = min(dp[i + 1][j + 1][d1], nxtp[dp[i][j][p]][d1]);
		}
	}
	int ans = INF;
	rep(i, k) for(int j = 0; j <= p; j ++) if(dp[k - 1][i][j] < n) ans = min(ans, i + (j > psum[n]));
	printf("%d\n", ans * p + psum[n]);
	return 0;
}