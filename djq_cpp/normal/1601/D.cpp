#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m, d, s[500005], a[500005];
pair<PII, int> val[500005];
int dp[500005];

int main()
{
	scanf("%d%d", &n, &d);
	rep(i, n) {
		scanf("%d%d", &s[i], &a[i]);
		if(s[i] < d) continue;
		if(s[i] < a[i]) val[m ++] = MP(MP(a[i], s[i]), 0);
		else val[m ++] = MP(MP(s[i], a[i]), 1);
	}
	sort(val, val + m);
	int mx = 0, cnt = 0;
	rep(i, m) {
		mx = max(mx, val[i].first.second);
		dp[i] = i == 0 ? 0 : dp[i - 1];
		if(val[i].second == 0) {
			if(mx <= val[i].first.second) dp[i] = max(dp[i], dp[upper_bound(val, val + m, MP(MP(val[i].first.second, INF), INF)) - val - 1] + 1);
		} else cnt ++;
	}
	printf("%d\n", dp[m - 1] + cnt);
	return 0;
}