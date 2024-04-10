#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll days(ll X, ll i, ll m) {
	ll lo = 0;
	ll hi = m + 1;
	while (lo + 1 < hi) {
		ll D = (lo + hi) / 2;
		if (m >= X + (i + 1) * (D - 1)) {
			lo = D;
		} else {
			hi = D;
		}
	}
	return lo;
}

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	ll running = 0;
	ll total = 0;
	for (int i = 0; i < n; ++i) {
		running += a[i];
		ll D = days(running, i, x);
		total += D;
	}
	cout << total << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}