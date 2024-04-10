#include <bits/stdc++.h>

const int P = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> c[i];
	}
	std::vector<int> b(n);
	for (int i = 0; i < n - 1; ++i) {
		int v;
		std::cin >> v;
		b[i + 1] = b[i] + v;
	}

	auto DP = [&](int x) -> int {
		std::vector<int> f(std::accumulate(c.begin(), c.end(), 0) + 1, 0);
		int sum = 0, now = 0;
		f[0] = 1;
		for (int i = 0; i < n; ++i) {
			sum += c[i], now += b[i];
			int s = 0;
			for (int k = 0; k <= c[i]; ++k) {
				s = (s + f[sum - k]) % P;
			}
			for (int j = sum; j >= 0; --j) {
				int t = j < (i + 1) * x + now ? 0 : s;
				s = (s + P - f[j]) % P;
				if (j > c[i]) {
					s = (s + f[j - c[i] - 1]) % P;
				}
				f[j] = t;
			}
		}
		return std::accumulate(f.begin(), f.end(), 0ll) % P;
	};

	int q;
	std::cin >> q;
	while (q--) {
		int x;
		std::cin >> x;
		std::cout << DP(x) << "\n";
	}
}