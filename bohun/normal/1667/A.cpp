#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 5005;
int n; 
ll a[N], b[N];

ll f(ll s, ll x) {
	return (s + x - 1) / x;
}

void solve() {
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	ll res = 1e18;
	rep(mid, 1, n) {
		ll s = 0;
		b[mid] = 0;
		rep(i, mid + 1, n) {
			ll k = f(b[i - 1] + 1, a[i]);
			s += k;
			b[i] = a[i] * k;
		}
		per(i, 1, mid - 1) {
			ll k = f(b[i + 1] + 1, a[i]);
			s += k;
			b[i] = a[i] * k;
		}
		res = min(res, s);
	}
	cout << res << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	// cin >> T;
	while (T--) solve();

	return 0;
}