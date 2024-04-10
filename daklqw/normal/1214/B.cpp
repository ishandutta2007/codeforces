#include <bits/stdc++.h>

int b, g, n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> b >> g >> n;
	int l = n - g, r = b;
	if (l < 0) l = 0;
	if (r > n) r = n;
	std::cout << (l > r ? 0 : r - l + 1) << std::endl;
	return 0;
}