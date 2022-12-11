#include <bits/stdc++.h>
int main()
{
	const int N = 50000;
	std::vector<int> p, vis(N);
	
	for(int i = 2; i < N; ++i) if(!vis[i])
	{
		p.push_back(i);
		for(int j = 2 * i; j < N; j += i) vis[j] = 1;
	}
	
	int T, n; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 0; i < n; ++i) std::cout << p[i] << " ";
		std::cout << std::endl;
	}
	return 0;
}