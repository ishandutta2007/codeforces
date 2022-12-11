#include <bits/stdc++.h>

std::string x;
int main() {
	for (int i = 1; i <= 10000; ++i)
		x += std::to_string(i);
	int n; std::cin >> n;
	printf("%c\n", x[n - 1]);
	return 0;
}