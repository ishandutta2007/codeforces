#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<int> a(n);
		for(int &x : a) std::cin >> x;
		
		int ans = 0;
		for(int i = 1; i < n; ++i) ans = std::max(ans, a[i] - a[0]);
		for(int i = 0; i < n - 1; ++i) ans = std::max(ans, a[n - 1] - a[i]);
		
		for(int i = 0; i < n; ++i) ans = std::max(ans, a[i] - a[(i + 1) % n]);
		std::cout << ans << "\n";
	}
	return 0;
}