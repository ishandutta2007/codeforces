#include <bits/stdc++.h>

const int N = 500005;

int n, k;
long long a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k;
	++k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + 1 + n, std::greater<int>());
	long long now = 0;
	for (int i = 1; i <= n; ++i) {
		now += a[i - 1];
		a[i] += a[i - 1];
	}
	long long ans = now;
	for (int i = n; i; --i) {
		if ((n - i) % k) {
			now -= a[i];
		}
		ans = std::max(ans, now);
	}
	std::cout << ans << "\n";
}