#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[100005], cnt, tcnt;
PII dp[1005], tmp[1005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	
	int ans = 0;
	cnt = 1; dp[0] = MP(100000, 1);
	for(int i = n - 1; i >= 0; i --) {
		int ca = 0, lx = 100000, pos = cnt - 1, pre = 0;
		tcnt = 0;
		for(int j = 1; j * j <= a[i]; j ++) {
			lx = (a[i] - 1) / j;
			pre = 0;
			while(pos >= 0 && dp[pos].first > lx) {
				pre += dp[pos].second; pre -= pre >= MOD ? MOD : 0; pos --;
			}
			ca = (ca + 1ULL * (j - 1) * pre) % MOD;
			tmp[tcnt ++] = MP(a[i] / j, pre);
		}
		for(int j = lx; j >= 1; j --) {
			pre = 0;
			while(pos >= 0 && dp[pos].first >= j) {
				pre += dp[pos].second; pre -= pre >= MOD ? MOD : 0; pos --;
			}
			ca = (ca + 1ULL * ((a[i] - 1) / j) * pre) % MOD;
			tmp[tcnt ++] = MP(j - (a[i] % j != 0), pre);
		}
		ans = (ans + 1ULL * (i + 1) * ca) % MOD;
		cnt = 0;
		for(int j = tcnt - 1; j >= 0; j --) dp[cnt ++] = tmp[j];
		dp[cnt ++] = MP(100000, 1);
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}