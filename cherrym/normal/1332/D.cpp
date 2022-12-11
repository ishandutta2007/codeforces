#include <bits/stdc++.h>

int k, m = 1;

int main()
{
	std::cin >> k;
	puts("3 3");
	while (m <= k) m <<= 1;
	std::cout << m + k << " " << k << " " << k << std::endl;
	std::cout << m << " " << m << " " << m + k << std::endl;
	std::cout << 0 << " " << 0 << " " << k << std::endl;
	return 0;
}