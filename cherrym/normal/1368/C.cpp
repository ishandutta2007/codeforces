#include <bits/stdc++.h>

int main()
{
	int n; std::cin >> n;
	std::cout << (n + 1) * 3 + 1 << std::endl;
	puts("0 0");
	for (int i = 1; i <= n + 1; i++)
		printf("%d %d\n%d %d\n%d %d\n", i, i - 1, i - 1, i, i, i);
	return 0;
}