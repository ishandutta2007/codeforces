#include <bits/stdc++.h>
#define mp make_pair
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 2E5+8;
constant mod = 998244353;

_ n, m, a[maxn], dp[2][maxn];
v_ b, c;

_ vl(v_ g);
int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= n; i += 2) b.push_back(a[i]);
	for(_ i = 2; i <= n; i += 2) c.push_back(a[i]);
	printf("%lld\n", vl(b)*vl(c)%mod);

	return 0;
}

_ vl(v_ g) {
	_ rv = 1, sz = (_)g.size();
	for(_ i = 1; i < sz; ++i) if(~g[i] && g[i] == g[i-1]) return 0;
	v_ d;
	for(_ i = 0; i < sz; ++i) if(~g[i]) d.push_back(i);
	if(d.empty()) {
		rv = m;
		for(_ i = 1; i < sz; ++i) rv = rv*(m-1)%mod;
		return rv;
	}
	if(d[0] != 0) for(_ i = 1; i <= d[0]; ++i) rv = rv*(m-1)%mod;
	if(d.back() != sz-1) for(_ i = d.back()+1; i < sz; ++i) rv = rv*(m-1)%mod;
	for(_ i = 0; i < (_)d.size()-1; ++i) {
		_ px = d[i], py = d[i+1];
		if(py == px+1) continue;
		dp[0][px+1] = g[px] == g[py] ? m-1 : m-2;
		dp[1][px+1] = g[px] == g[py] ? 0 : 1;
		for(_ j = px+2; j <= py-1; ++j) {
			dp[0][j] = (dp[1][j-1]*(m-1)+dp[0][j-1]*(m-2))%mod;
			dp[1][j] = dp[0][j-1];
		}
		rv = rv*dp[0][py-1]%mod;
	}
	return rv;
}