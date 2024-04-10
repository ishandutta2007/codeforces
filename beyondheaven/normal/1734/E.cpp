#include <bits/stdc++.h>
int main()
{
	int n; std::cin >> n;
	std::vector<int> b(n);
	for(int &x : b) std::cin >> x;
	
	std::vector<int> h(n);
	for(int i = 0; i < n; ++i) h[i] = (b[i] - i * i) % n;
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			int x = i * j + h[i];
			std::cout << (x % n + n) % n << " ";
		}
		std::cout << "\n";
	}
	return 0;
}