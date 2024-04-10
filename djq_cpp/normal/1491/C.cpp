#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
LL a[5005], tmp[5005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%lld", &a[i]);
	LL ans = 0;
	rep(i, n) tmp[i] = 0;
	rep(i, n) {
		LL nec = max(a[i] - 1, tmp[i]);
		ans += nec - tmp[i];
		
		for(int j = min(i + a[i], n - 1LL); j >= i + 2; j --) tmp[j] ++;
		tmp[i + 1] += nec - (a[i] - 1);
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