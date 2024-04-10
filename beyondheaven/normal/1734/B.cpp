#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::cout << 1 << "\n";
		for(int i = 2; i <= n; ++i)
		{
			for(int j = 1; j <= i; ++j) std::cout << ((j == 1 || j == i) ? 1 : 0) << " ";
			std::cout << "\n";
		}
	}
	return 0;
}