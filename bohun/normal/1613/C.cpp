#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int n;
ll a[105], h;

bool solve(ll k) {
	ll s = k;
	rep(i, 1, n - 1) {
		s += min(k, a[i + 1] - a[i]);
	}
	return s >= h;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> h;
		rep(i, 1, n)
			cin >> a[i];

		ll l = 1, r = h;
		while (l < r) {
			ll m = (l + r) / 2;

			if (solve(m)) {
				r = m;
			}
			else {
				l = m + 1;
			}
		}

		cout << l << "\n";
	}

	return 0;
}