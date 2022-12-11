#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, k; std::cin >> n >> k;
		if(n <= 4)
		{
			std::vector<int> a(n);
			std::iota(a.begin(), a.end(), 0);
			
			bool solved = false;
			do
			{
				int s = 0;
				for(int i = 0; i < n / 2; ++i) s += (a[i] & a[i + n / 2]);
				if(s == k)
				{
					solved = true;
					for(int i = 0; i < n / 2; ++i) std::cout << a[i] << " " << a[i + n / 2] << "\n";
					break;
				}
			} while(std::next_permutation(a.begin(), a.end()));
			if(!solved) std::cout << -1 << "\n";
		}
		else
		{
			if(k == 0)
			{
				for(int i = 0; i < n / 2; ++i)
				std::cout << i << " " << (i ^ (n - 1)) << "\n";
			}
			else if(k == n - 1)
			{
				std::cout << 0 << " " << 2 << "\n";
				std::cout << (n - 1) << " " << (1 ^ (n - 1)) << "\n";
				std::cout << 1 << " " << (2 ^ (n - 1)) << "\n";
				for(int i = 3; i < n / 2; ++i)
				std::cout << i << " " << (i ^ (n - 1)) << "\n";
			}
			else
			{
				std::cout << 0 << " " << (k ^ (n - 1)) << "\n";
				std::cout << k << " " << (n - 1) << "\n";
				for(int i = 1; i < n / 2; ++i)
				if(i != k && (i ^ (n - 1)) != k) std::cout << i << " " << (i ^ (n - 1)) << "\n";
			}
		}
	}
	return 0;
}