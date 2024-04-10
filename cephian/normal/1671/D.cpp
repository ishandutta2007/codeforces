#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, x;
	cin >> n >> x;
	vector<int> a(n);
	int mn = 1 << 30;
	int mx = -(1 << 30);
	ll score = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		if (i) {
			score += abs(a[i] - a[i - 1]);
		}
	}
	ll mxdiff = max(0LL, x - mx);
	ll mndiff = max(0LL, mn - 1LL);
	score += min(2 * mxdiff, min(abs(x - a[0]), abs(x - a.back())));
	score += min(2 * mndiff, min(abs(1LL - a[0]), abs(1LL - a.back())));
	cout << score << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}