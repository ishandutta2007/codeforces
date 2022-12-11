#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::string s; std::cin >> s;
		int n = s.size(), cnt = std::count(s.begin(), s.end(), '1');
		if(cnt == 0) { std::cout << -1 << "\n"; continue; }
		
		int expect = 1;
		while(expect < cnt) expect <<= 1;
		
		auto score = [&](int x) -> int { return x - __builtin_popcount(x); };
		
		std::vector<std::pair<int, int>> ans;
		while(true)
		{
			int delta = expect - cnt;
			for(int l = 0, r = 0; l < n; l = r)
			{
				int cur = 0;
				while(r < n &&
					score(2 * cur + (s[r] - '0')) <= delta) cur = 2 * cur + (s[r++] - '0');
				ans.emplace_back(l + 1, r);
				delta -= score(cur);
			}
			
			if(delta == 0) break;
			else expect <<= 1, ans.clear();
		}
		
		std::cout << ans.size() << "\n";
		for(const auto &p : ans) std::cout << p.first << " " << p.second << "\n";
	}
	return 0;
}