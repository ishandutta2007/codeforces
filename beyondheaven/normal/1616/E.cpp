#include <bits/stdc++.h>
int idx(char c) {return c - 'a';}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n; std::string s, t; std::cin >> s >> t;
		
		auto _s = s; std::sort(_s.begin(), _s.end());
		if(_s >= t) {std::cout << "-1\n"; continue;}
		if(s < t) {std::cout << "0\n"; continue;}
		
		std::vector<int> c(n + 1);
		auto add = [&](int x)
		{
			for(++x; x <= n; x += (x & -x)) ++c[x];
		};
		
		auto sum = [&](int x)
		{
			int res = 0;
			for(++x; x; x -= (x & -x)) res += c[x];
			return res;
		};
		
		std::array<std::set<int>, 26> p;
		for(int i = 0; i < n; ++i) p[idx(s[i])].insert(i);
		
		int64_t ans = (int64_t(1) << 60), pre = 0;
		for(int i = 0; i < n; ++i)
		{
			for(int z = 0; z < idx(t[i]); ++z)
			if(!p[z].empty())
			{
				int u = *p[z].begin();
				//std::cerr << "i = " << i << " checkmin " << pre + u - sum(u - 1) << std::endl;
				ans = std::min(ans, pre + u - sum(u - 1));
			}
			
			if(!p[idx(t[i])].empty())
			{
				int u = *p[idx(t[i])].begin();
				pre += u - sum(u - 1);
				p[idx(t[i])].erase(u);
				add(u);
			}
			else break;
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}