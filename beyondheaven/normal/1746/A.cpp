#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, k; std::cin >> n >> k;
		std::valarray<int> a(n);
		for(int &x : a) std::cin >> x;
		std::cout << (a.sum() ? "YES" : "NO") << "\n";
	}
	return 0;
}