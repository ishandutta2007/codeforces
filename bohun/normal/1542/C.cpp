//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {

		ll n;
		cin >> n;

		const int P = 1e9 + 7;
		ll res = n % P;
		ll lcm = 1;

		for (ll i = 1;; i++) {
			lcm = lcm * (i / __gcd(lcm, i));
			if (n < lcm)
				break;
			res = (res + n / lcm) % P;
		}

		cout << res << '\n';
	}

	return 0;
}