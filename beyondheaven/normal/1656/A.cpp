#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;

int n, a[MaxN];
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		std::cout << std::min_element(a + 1, a + n + 1) - a << " " << 
			std::max_element(a + 1, a + n + 1) - a << "\n";
	}
	return 0;
}