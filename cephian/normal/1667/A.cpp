#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll best_ops = 1LL << 60;
	for (int zero_idx = 0; zero_idx < n; ++zero_idx) {
		ll ops = 0;
		ll last_val = 0;
		for (int i = zero_idx - 1; i >= 0; --i) {
			ll ops_now = (last_val + a[i]) / a[i];
			ops += ops_now;
			last_val = ops_now * a[i];
		}
		last_val = 0;
		for (int i = zero_idx + 1; i < n; ++i) {
			ll ops_now = (last_val + a[i]) / a[i];
			ops += ops_now;
			last_val = ops_now * a[i];
		}
		best_ops = min(best_ops, ops);
	}
	cout << best_ops << '\n';
}