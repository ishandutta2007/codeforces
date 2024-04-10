#include <bits/stdc++.h>
using namespace std;

long long a[220000];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	long long sum = 0;
	int ans = n + 1;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if (sum >= m) {
			int lo = 0, hi = i;
			while (hi - lo > 1) {
				int mid = lo + hi >> 1;
				long long x = i % mid;
				long long y = mid - x;
				long long q = i / mid;
				if (sum - y * q * (q - 1) / 2 - x * q * (q + 1) / 2 >= m) hi = mid;
				else lo = mid;
			}
			ans = min(ans, hi);
		}
	}
	if (ans > n) ans = -1;
	cout << ans << endl;
	return 0;
}