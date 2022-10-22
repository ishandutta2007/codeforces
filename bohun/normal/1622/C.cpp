#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		ll k;
		cin >> n >> k;
		vector<ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a.begin(), a.end());
		reverse(a.begin() + 1, a.end());
		for (int i = 1; i < n; i++)
			a[i] += a[i - 1];

		if (a[n - 1] <= k) {
			cout << 0 << '\n';
			continue;
		}

		ll res = 1e18;
		for (int i = 0; i < n; i++) {
			res = min(res, max(0ll, (a[n - 1] - a[i] + a[0] * (i + 1) - k + i) / (i + 1)) + i);
		}
		cout << res << '\n';
	}

	return 0;
}