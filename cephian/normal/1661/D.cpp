#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<ll> worker_end(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	ll workers = 0;
	ll moving_sum = 0;
	ll ans = 0;
	for (int i = n; i >= 1; --i) {
		// cascade down
		moving_sum -= workers;
		workers -= worker_end[i];
		// add new
		int seg_start = max(1, i - k + 1);
		ll seg_up = 1 + (i - seg_start);
		ll num_apply = max((b[i] - moving_sum + seg_up - 1) / seg_up, 0LL);
		ans += num_apply;
		worker_end[seg_start-1] += num_apply;
		workers += num_apply;
		moving_sum += seg_up * num_apply;
	}
	cout << ans << '\n';
}