#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
int main() {
	int Q;
	std::cin >> Q;
	while (Q --> 0) {
		int l, r;
		std::cin >> l >> r;
		long long ans = 0;
		if (l % 2 != 0) ans -= --l;
		if (r % 2 == 0) ans += ++r;
		ans -= r - l + 1 >> 1;
		std::cout << ans << std::endl;
	}
	return 0;
}