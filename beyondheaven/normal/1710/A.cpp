#include <bits/stdc++.h>
using ll = long long;
#define int ll
signed main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n, m, k; std::cin >> n >> m >> k;
		std::vector<int> a(k);
		for(int &x : a) std::cin >> x;
		
		auto check = [&](int n, int m)
		{
			int c = 0; bool flag = false;
			for(int x : a)
			{
				if(x / n >= 2) c += x / n;
				flag |= (x / n >= 3);
			}
			
			bool ans = (c >= m);
			if(m % 2 == 1) ans &= flag;
			return ans;
		};
		
		std::cout << ((check(n, m) | check(m, n)) ? "Yes" : "No") << "\n";
	}
	return 0;
}