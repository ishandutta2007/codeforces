//vsp
#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 200200;

int n, m;
ll a[N];

ll f(ll a, ll b) {
	return max<ll>(0, b - a);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	FOR(i, n)
		cin >> a[i];
	sort(a, a + n);
	ll s = accumulate(a, a + n, 0ll);
	cin >> m;
	while (m--) {
		ll x, y;
		cin >> x >> y;
		ll res = 4e18;
		int p = lower_bound(a, a + n, x) - a;
		if (p < n)
			res = f(s - a[p], y);
		if (p > 0)
			res = min(res, x - a[p - 1] + f(s - a[p - 1], y));
		cout << res << '\n';
	}

	return 0;
}