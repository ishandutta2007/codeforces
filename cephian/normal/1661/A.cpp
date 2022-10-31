#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll val(ll a, ll b, ll c, ll d) { return abs(a - b) + abs(c - d); }

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += min(val(a[i], a[i - 1], b[i], b[i - 1]),
			   val(a[i], b[i - 1], b[i], a[i - 1]));
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}