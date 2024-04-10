#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 2; ; ++i)
		if (n % i == 0) {
			std::cout << i << n/i << '\n';
			return 0;
		}

	return 0;
}