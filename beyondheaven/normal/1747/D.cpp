#include <bits/stdc++.h>
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, q;
	std::cin >> n >> q;
	
	std::vector<int> a(n);
	for (int &x : a) {
		std::cin >> x;
	}
	
	std::vector<int> ps(n + 1), cnt(n + 1);
	for (int i = 0; i < n; i++) {
		ps[i + 1] = (ps[i] ^ a[i]);
		cnt[i + 1] = cnt[i] + (a[i] == 0);
	}
	
	std::map<int, std::vector<int>> occ[2];
	for (int i = 1; i <= n; i++) {
		occ[i % 2][ps[i]].push_back(i);
	}
	
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		l--;
		
		if (ps[l] != ps[r]) {
			std::cout << -1 << "\n";
		} else if (cnt[r] - cnt[l] == r - l) {
			std::cout << 0 << "\n";
		} else if ((r - l) % 2 == 1) {
			std::cout << 1 << "\n";
		} else if (a[l] == 0 || a[r - 1] == 0) {
			std::cout << 1 << "\n";	
		} else {
			auto &vec = occ[1 - l % 2][ps[l]];
			auto it = std::upper_bound(vec.begin(), vec.end(), l);
			if (it == vec.end() || *it > r) {
				std::cout << -1 << "\n";
			} else {
				std::cout << 2 << "\n";
			}
		}
	}
	return 0;
}