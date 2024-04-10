#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<int> a(n), c(n + 1);
		for(int &x : a) std::cin >> x, ++c[x];
		
		int mex = n + 1;
		for(int i = 0; i <= n; ++i) if(c[i] == 0) mex = std::min(mex, i);
		
		auto erase = [&](int i)
		{
			if(--c[a[i]] == 0) mex = std::min(mex, a[i]);
		};
		
		std::vector<int> ans;
		int idx = 0;
		
		while(idx != n)
		{
			ans.push_back(mex);
			std::vector<int> vis(mex);
			for(int i = idx, cnt = 0; i < n; ++i)
			{
				if(a[i] < mex) { if(++vis[a[i]] == 1) ++cnt; }
				if(cnt == mex)
				{
					for(int j = idx; j <= i; ++j) erase(j);
					idx = i + 1; break;
				}
			}
		}
		
		std::cout << ans.size() << "\n";
		for(int x : ans) std::cout << x << " ";
		std::cout << "\n";
	}
	return 0;
}