#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n, z, ans = 0; std::cin >> n >> z;
		std::vector<int> a(n);
		for(int i = 0; i < n; ++i) std::cin >> a[i], ans = std::max(ans, (a[i] | z));
		std::cout << ans << "\n"; 
	}
	return 0;
}