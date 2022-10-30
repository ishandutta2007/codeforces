#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define F first
#define S second

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 22;
const double eps = 1e-8;
int n, m, k, a[maxn], w[maxn][maxn]={{}};
long long dp[1 << 20][22];
long long f(int b, int cur, int cnt) {
	if(cnt == m) return a[cur];
	long long &ret = dp[b][cur];
	if(ret >= 0) return ret;
	ret = 0;

	rep(i, n) if(~b & (1 << i)) {
		ret = max(ret, f(b | (1 << i), i, cnt + 1) + w[cur][i]);
	}

	ret += a[cur];

	return ret;
}
int main() {
	riii(n, m, k);
	rep(i, n) ri(a[i]);
	rep(i, k) {
		int x, y, z;
		riii(x, y, z);
		w[x - 1][y - 1] = z;
	}
	memset(dp, -1, sizeof dp);
	long long ans = 0;
	rep(i, n) ans = max(ans, f(1 << i, i, 1));
	cout << ans << endl;
	
	return 0;
}