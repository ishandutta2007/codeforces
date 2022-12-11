#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n, k; std::cin >> n >> k;
		if(k > (n + 1) / 2) {std::cout << "-1\n"; continue;}
		
		std::vector<std::vector<char>> mp(n + 1, std::vector<char>(n + 1, '.'));
		
		int i = 1;
		while(k--) mp[i][i] = 'R', i += 2;
		
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j) std::cout << mp[i][j];
			std::cout << "\n";
		}
	}
	return 0;
}