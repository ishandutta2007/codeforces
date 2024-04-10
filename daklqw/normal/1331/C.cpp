#include <bits/stdc++.h>

int a[6];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 0; i < 6; ++i)
		a[i] = n >> i & 1;
	std::swap(a[0], a[4]);
	std::swap(a[2], a[3]);
	n = 0;
	for (int i = 0; i < 6; ++i)
		n |= a[i] << i;
	std::cout << n << std::endl;

	return 0;
}