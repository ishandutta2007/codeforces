#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const ll MX = 1e15;
int N;
ll K;
char a[105];
ll dp[105][105], res[105];

int main() {
	scanf("%d%lld", &N, &K);
	scanf("%s", a + 1);
	dp[0][0] = 1;
	repi(i, N) repi(j, i) {
		for (int k = i - 1; ~k; --k) {
			dp[i][j] += dp[k][j - 1];
			if (dp[i][j] > MX) dp[i][j] = MX;
			if (a[i] == a[k]) break;
		}
	}
	rep(i, N + 1) rep(j, i + 1) {
		res[j] += dp[i][j];
		if (res[j] > MX) res[j] = MX;
	}
	ll ans = 0;
	for (int i = N; ~i; --i) {
		ll sel = min(K, res[i]);
		K -= sel;
		ans += sel * (N - i);
		if (!K) break;
	}
	if (K) return puts("-1"), 0;
	printf("%lld\n", ans);
	return 0;
}