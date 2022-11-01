#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll a, b;
	cin >> n >> a >> b;
	vector<ll> x(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	// cost to move to n-1
	ll cost = 0;
	for (int i = 1; i <= n; ++i) {
		cost += b * (x[i] - x[i - 1]);
		if (i != n) {
			cost += a * (x[i] - x[i - 1]);
		}
	}
	ll min_cost = cost;
	ll amt_sliding = 1;
	for (int i = n - 2; i >= 0; --i) {
		// sub cost from moving base past i
		cost -= a * (x[i + 1] - x[i]);
		cost += amt_sliding * b * (x[i + 1] - x[i]);
		min_cost = min(min_cost, cost);
		++amt_sliding;
	}
	cout << min_cost << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}