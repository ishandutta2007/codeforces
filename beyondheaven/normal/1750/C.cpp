#include <bits/stdc++.h>
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::valarray<int> a(n), b(n);
		for (auto v : { &a, &b }) {
			for (int &x : *v) {
				char c;
				std::cin >> c;
				x = c - '0';
			}
		}
		
		std::vector<std::pair<int, int>> ans;
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				a[i] ^= 1;
				b[i] ^= 1;
				cnt ^= 1;
				ans.emplace_back(i, i);
			}
		}
		
		b ^= cnt;
		if ((a ^ b).max() == 0) {
			std::cout << "YES" << "\n";
			std::cout << ans.size() << "\n";
			for (auto [l, r] : ans) {
				std::cout << l + 1 << " " << r + 1 << "\n";
			}
		} else if (n > 1 && (a ^ b ^ 1).max() == 0) {
			ans.emplace_back(0, 0);
			ans.emplace_back(1, 1);
			ans.emplace_back(0, 1);
			
			std::cout << "YES" << "\n";
			std::cout << ans.size() << "\n";
			for (auto [l, r] : ans) {
				std::cout << l + 1 << " " << r + 1 << "\n";
			}
		} else {
			std::cout << "NO" << "\n";
		}
	}
	return 0;
}