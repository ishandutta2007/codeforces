#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<int> d(n + 1), ans(n + 1);
		for(int i = 1; i <= n; ++i) std::cin >> d[i];
		
		int cur = 0;
		while(true)
		{
			int p = -1;
			for(int i = 1; i <= n; ++i)
			{
				if(!ans[i] && (p == -1 || d[i] > d[p])) p = i;
			}
			
			if(p == -1) break;
			
			std::vector<int> v;
			for(int i = 1; i <= d[p]; ++i)
			{
				std::cout << "? " << p << "\n";
				std::cout.flush();
				int x; std::cin >> x;
				v.push_back(x);
				if(ans[x])
				{
					ans[p] = ans[x];
					for(int y : v) ans[y] = ans[x];
					goto _break;
				}
			}
			
			ans[p] = ++cur;
			for(int x : v) ans[x] = cur;
_break:		 
            ;
		}
		
		std::cout << "! ";
		for(int i = 1; i <= n; ++i) std::cout << ans[i] << " ";
		std::cout << "\n";
		std::cout.flush();
	}
	return 0;
}