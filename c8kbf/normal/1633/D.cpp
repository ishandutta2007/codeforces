

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E3+8;
constant maxm = 12E3+8;

_ tc, n, m, dp[maxm], c[maxn], a[maxn], b[maxn];

int main() {

	memset(c, 4, sizeof c);
	c[1] = 0;
	for(_ i = 1; i <= 999; ++i) for(_ j = 1; j <= i; ++j) if(i+i/j <= 1000) c[i+i/j] = min(c[i+i/j], c[i]+1);
	scanf("%lld", &tc);
	for(; tc--; ) {
		memset(dp, -4, sizeof dp);
		scanf("%lld%lld", &n, &m);
		for(_ i = 1; i <= n; ++i) {
			_ x;
			scanf("%lld", &x);
			a[i] = c[x];
		}
		for(_ i = 1; i <= n; ++i) scanf("%lld", &b[i]);
		dp[0] = 0;
		m = min(m, n*12);
		for(_ i = 1; i <= n; ++i) for(_ j = m; j >= a[i]; --j) dp[j] = max(dp[j], dp[j-a[i]]+b[i]);
		printf("%lld\n", *max_element(dp, dp+1+m));
	}

	return 0;
}