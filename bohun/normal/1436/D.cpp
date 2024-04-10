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
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 2e5 + 50;

int n, p;
vector <int> G[N];
ll a[N], mx[N], cnt[N], sum[N];

void dfs(int v) {
	bool leaf = true;
	for (auto u : G[v]) {
		leaf = false;
		dfs(u);
		mx[v] = max(mx[v], mx[u]);
		cnt[v] += cnt[u];
		sum[v] += sum[u];
	}
	if (leaf) cnt[v]++;
	ll r = cnt[v] * mx[v] - sum[v];
	if (a[v] <= r) sum[v] += a[v];
	if (a[v] > r) {
		sum[v] += a[v];
		mx[v] = (sum[v] + cnt[v] - 1) / cnt[v];
	}
}

int main() {
	scanf ("%d", &n);
	rep(i, 2, n) {
		scanf ("%d", &p);
		G[p].pb(i);
	}
	rep(i, 1, n) scanf ("%lld", a + i);
	dfs(1);
	printf ("%lld\n", mx[1]);
	return 0;
}