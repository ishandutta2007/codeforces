#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int m = *std::max_element(a.begin(), a.end()) + 1;
	std::vector<int> c(m), s(m);
	for (int i = 0; i < n; ++i) {
		s[a[i]] += i & 1;
		++c[a[i]];
	}
	std::vector<int> p(m);
	for (int i = 0; i < m - 1; ++i) {
		p[i + 1] = p[i] + c[i];
	}
	for (int i = 0; i < n; ++i) {
		s[a[i]] -= p[a[i]] & 1;
		++p[a[i]];
	}
	for (int i = 0; i < m; ++i) {
		if (s[i]) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
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