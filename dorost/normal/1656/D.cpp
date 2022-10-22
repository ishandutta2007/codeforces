/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const ll INF = 2000LL * 1000LL * 1000LL;
const int N = 45730;
bool p[N];
vector <int> v;

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return (x > 1);
}

void solve() {
	ll n, on;
	cin >> n;
	on = n;
	if (n % 2) {
		cout << 2 << '\n';
	} else {
		if (n <= 4) {
			cout << -1 << '\n';
		} else {
			ll ans = 2;
			while (n % 2 == 0) {
				n /= 2;
				ans *= 2;
			}
			if (ans < INF && ans * (ans + 1) / 2 <= on) {
				cout << ans << '\n';
			} else {
				if (n == 1) {
					cout << -1 << '\n';
					return;
				}
				ll mn = n;
				for (auto x : v) {
					if (n % x == 0) {
						mn = x;
						break;
					}
				}
				if (mn < INF && mn * (mn + 1) / 2 <= on) {
					cout << mn << '\n';
				} else {
					cout << -1 << '\n';
				}
			}
		}
	}
}

int32_t main() {
	for (int i = 0; i < N; i++) {
		p[i] = is_prime(i);
		if (p[i])
			v.push_back(i);
	}
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}