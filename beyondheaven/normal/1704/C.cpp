#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, m; std::cin >> n >> m;
		std::vector<int> a(m);
		for(int &x : a) std::cin >> x;
		std::sort(a.begin(), a.end());
		
		std::vector<int> b;
		for(int i = 0; i + 1 < m; ++i) b.push_back(a[i + 1] - a[i] - 1);
		b.push_back(a[0] + n - a[m - 1] - 1);
		std::sort(b.begin(), b.end(), std::greater<>());
		
		int ans = m;
		for(int i = 0, T = 0; i < m; ++i)
		{
			if(b[i] <= 2 * T) ans += b[i];
			else if(b[i] <= 2 * T + 2) { ans += b[i] - 1; ++T; }
			else { ans += 2 * T + 1; T += 2; }
		}
		std::cout << ans << "\n";
	} 
	return 0;
}