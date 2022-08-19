#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n, a[5005];
LL solve(int p)
{
	LL ret = 0, c = 0;
	for(int i = p - 1; i >= 0; i --) {
		LL cur = c / a[i] + 1;
		ret += cur;
		c = cur * a[i];
	}
	c = 0;
	for(int i = p + 1; i < n; i ++) {
		LL cur = c / a[i] + 1;
		ret += cur;
		c = cur * a[i];
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	LL ans = INF;
	rep(i, n) ans = min(ans, solve(i));
	printf("%lld\n", ans);
	return 0;
}