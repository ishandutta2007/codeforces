#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
// c0 3f
using ll = long long;
using ld = long double;
using namespace std;

const int N = 3100;

int n, k, a, sz[N];
vector <ll> g[N];
ll ans, sum[N];

void add(vector <ll> &dp, int id) {
	per(i, sz[id], k)
		dp[i] = max(dp[i], dp[i - sz[id]] + sum[id]);
}

void solve(int l, int r, vector <ll> dp) {
	if (l == r) {
		ll s = 0;
		rep(i, 0, sz[l] - 1) {
			s += g[l][i];
			ans = max(ans, s + dp[k - i - 1]);
		}
		return;
	}
	int m = l + r >> 1;
	auto cur = dp;
	rep(i, l, m)
		add(cur, i);
	solve(m + 1, r, cur);
	cur = dp;
	rep(i, m + 1, r)
		add(cur, i);
	solve(l, m, cur);
}		

int main() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, n) {
		scanf ("%d", sz + i);
		rep(j, 1, sz[i]) {
			scanf ("%d", &a);
			g[i].pb(a);
		}
		sz[i] = min(sz[i], k);
		g[i].resize(k);
		sum[i] = accumulate(all(g[i]), 0LL);
	}
	vector <ll> dp(k + 1, 0);
	solve(1, n, dp);
	printf ("%lld\n", ans);
	return 0;
}