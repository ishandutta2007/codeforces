#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		int n; std::cin >> n;
		if (n == 1) std::cout << -1 << std::endl;
		else if (n == 2) {
			std::cout << 23 << std::endl;
		} else if (n == 3) {
			std::cout << 239 << std::endl;
		} else {
			int sm = 0;
			for (int i = 1; i <= n - 3; ++i)
				std::cout << 7, sm += 7;
			if (sm % 3 == 0) {
				std::cout << 773;
			} else if (sm % 3 == 1) {
				std::cout << 783;
			} else
				std::cout << 773;
			std::cout << '\n';
		}
	}
	return 0;
}