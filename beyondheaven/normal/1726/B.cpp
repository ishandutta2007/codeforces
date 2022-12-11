#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, m; std::cin >> n >> m;
		if(n % 2 == 1)
		{
			if(m < n) std::cout << "No" << "\n";
			else
			{
				std::cout << "Yes" << "\n";
				for(int i = 1; i < n; ++i) std::cout << 1 << " ";
				std::cout << m - (n - 1) << "\n";
			}
		}
		else
		{
			if(m % 2 == 1 || m < n) std::cout << "No" << "\n";
			else
			{
				std::cout << "Yes" << "\n";
				for(int i = 1; i <= n - 2; ++i) std::cout << 1 << " ";
				for(int i : { 1, 2 }) std::cout << (m - (n - 2)) / 2 << " ";
				std::cout << "\n";
			}
		}
	}
	return 0;
}