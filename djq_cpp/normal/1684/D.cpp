#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, k, a[200005];
LL sum, ans;

void solve()
{
	scanf("%d%d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	sum = 0;
	rep(i, n) sum += a[i];
	ans = sum;
	rep(i, n) a[i] -= n - i - 1;
	sort(a, a + n);
	reverse(a, a + n);
	rep(i, k) {
		sum -= a[i] + i;
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}