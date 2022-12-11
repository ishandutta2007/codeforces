#include <bits/stdc++.h>
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	using ll = long long;
	
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		
		ll ans = 0;
		auto solve = [&](auto self, int l, int r) {
			if (l + 1 == r) {
				ans += 1;
				return;
			}
			
			int mid = (l + r) / 2;
			self(self, l, mid);
			self(self, mid, r);
			
			std::vector<std::pair<int, int>> L, R;
			for (int i = mid - 1, a = 0, b = 0; i >= l; i--) {
				if (s[i] == ')') {
					a += 1;
				} else {
					a ? a -= 1 : b += 1;
				}
				L.emplace_back(a, b);
			}
			
			for (int i = mid, c = 0, d = 0; i < r; i++) {
				if (s[i] == '(') {
					d += 1;
				} else {
					d ? d -= 1 : c += 1;
				}
				R.emplace_back(c, d);
			}
			
			std::vector<std::pair<int, int>> T1;
			for (auto [a, b] : L) {
				T1.emplace_back(b, 0);
			}
			
			for (auto [c, d] : R) {
				T1.emplace_back(c, 1);
			}

			std::array<ll, 2> cnt = { 0, 0 }, sum = { 0, 0 }, tot = { mid - l, r - mid };
			std::sort(T1.begin(), T1.end());
			for (auto [v, z] : T1) {
				ans -= v * (tot[z ^ 1] - cnt[z ^ 1]);
				cnt[z] += 1;
				sum[z] += v;
			}
			
			for (auto [a, b] : L) {
				for (auto [c, d] : R) {
					// ans += std::max(a + c, b + d);
					// ans -= std::min(b, c);
				}
			}
			
			std::vector<std::tuple<int, int, int, int>> T2;
			cnt.fill(0), sum.fill(0);
			
			for (auto [a, b] : L) {
				T2.emplace_back(a - b, a, b, 0);
			}
			
			for (auto [c, d] : R) {
				T2.emplace_back(d - c, c, d, 1);
			}
			
			std::sort(T2.begin(), T2.end());
			for (auto [_, x, y, z] : T2) {
				if (z == 0) {
					ans += x * cnt[1] + sum[1];
					cnt[0] += 1;
					sum[0] += y;
				} else {
					ans += y * cnt[0] + sum[0];
					cnt[1] += 1;
					sum[1] += x;
				}
			}
		};
		
		solve(solve, 0, n);
		std::cout << ans << "\n";
	}
	return 0;
}