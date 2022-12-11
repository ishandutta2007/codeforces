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
		
		int cnt[2] = { 0, 0 }, cur = 0, last = -1, mx = 0;
		while (n--) {
			char c;
			std::cin >> c;
			int x = c - '0';
			cnt[x] += 1;
			if (x == last) {
				cur += 1;
			} else {
				last = x;
				cur = 1;
			}
			mx = std::max(mx, cur);
		}
		
		std::cout << std::max(ll(cnt[0]) * cnt[1], ll(mx) * mx) << "\n";
	}
	return 0;
}