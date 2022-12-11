#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, x; std::cin >> n >> x;
		std::vector<int> a(n);
		for(int &x : a) std::cin >> x;
		
		int last = -1, mn = 0, mx = 0, ans = 0;
		for(int i = 0; i < n; ++i)
		{
			if(last == -1 || std::max(mx, a[i]) - std::min(mn, a[i]) > 2 * x)
			{
				++ans;
				last = i;
				mn = mx = a[i];
			}
			else mn = std::min(mn, a[i]), mx = std::max(mx, a[i]);
		} 
		
		std::cout << ans - 1 << "\n";
	}
	return 0;
}