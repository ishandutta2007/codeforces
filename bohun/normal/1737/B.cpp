#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

ll f(ll n) {
	if (n == 0) return 0;
	ll sq = sqrtl(n);
	ll res = 3 * (sq - 1);
	rep(i, 0, 2)
		if (sq * (sq + i) <= n) {
			res++;
		}
	return res;
}

void solve() {
	ll a, b;
	cin >> a >> b;
	cout << f(b) - f(a - 1) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

	return 0;
}