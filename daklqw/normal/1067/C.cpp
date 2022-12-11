#include <bits/stdc++.h>

int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 0, t = 0; i < n; ++i)
		std::cout << t << ' ' << ("132"[i % 3]) << '\n', t += !!(i % 3);
	return 0;
}