#include <bits/stdc++.h>

const int N = 100005, INF = 0x3f3f3f3f;

int n;
int a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		a[i] ^= a[i - 1];
	}
	if (n > 80) {
		std::cout << 1 << "\n";
		return 0;
	}

	int ans = INF;
	for (int l = 0; l <= n; ++l) {
		for (int m = l + 1; m <= n; ++m) {
			for (int r = m + 1; r <= n; ++r) {
				if ((a[r] ^ a[m]) < (a[l] ^ a[m])) {
					ans = std::min(ans, r - l - 2);
				}
			}
		}
	}
	if (ans == INF) {
		std::cout << -1 << "\n";
	} else {
		std::cout << ans << "\n";
	}
}