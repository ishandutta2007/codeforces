#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, P;
	std::cin >> n >> P;
	std::vector<int> f(n + 1);
	for (int i = 1; i <= n; ++i) {
		if (i < n) {
			f[i + 1] = (f[i + 1] + f[i]) % P;
		}
		if (i == 1) {
			f[i] = 1;
		}
		if (i < n) {
			f[i + 1] = (f[i + 1] + f[i]) % P;
		}
		for (int x = 2; x * i <= n; ++x) {
			f[x * i] = (f[x * i] + f[i]) % P;
			if (x * i + x <= n) {
				f[x * i + x] = (f[x * i + x] + P - f[i]) % P;
			}
		}
	}
	std::cout << f[n] << "\n";
}