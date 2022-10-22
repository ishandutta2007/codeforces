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

const int N = 2e5 + 5;
const int MOD = 998244353;

int cas, n, k, a[N], b[N], c[N], l[N], r[N];

void solve() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, n) scanf ("%d", a + i), c[i] = 0;
	rep(i, 1, k) scanf ("%d", b + i), c[b[i]] = 1;
	a[n + 1] = 0;
	rep(i, 1, n) l[a[i]] = a[i - 1], r[a[i]] = a[i + 1];
	int res = 1;
	rep(i, 1, k) {
		int w = 0;
		w += l[b[i]] != 0 && !c[l[b[i]]];
		w += r[b[i]] != 0 && !c[r[b[i]]];
		res = res * w % MOD;
		r[l[b[i]]] = r[b[i]];
		l[r[b[i]]] = l[b[i]];
	}
	printf ("%d\n", res);	
}

int main() {
	scanf ("%d", &cas);
	while (cas--)
		solve();
	return 0;
}