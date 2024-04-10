#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> d(n);
	for (int &x : d) {
		std::cin >> x;
	}
	std::sort(d.begin(), d.end());
	long long ans = d.back();
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		ans += sum - 1ll * i * d[i];
		sum += d[i];
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}