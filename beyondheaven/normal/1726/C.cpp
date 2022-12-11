#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::string s; std::cin >> s;
		std::vector<int> match(2 * n), stk;
		for(int i = 0; i < 2 * n; ++i)
		{
			if(s[i] == '(') stk.push_back(i);
			else
			{
				int j = stk.back(); stk.pop_back();
				match[i] = j; match[j] = i;
			}
		}
		
		auto solve = [&](auto self, int l, int r)
		{
			if(l >= r) return 0;
			if(l + 1 == r) return 1;
			
			int x = l, ans = 1;
			while(x <= r)
			{
				ans += self(self, x + 1, match[x] - 1);
				x = match[x] + 1;
			}
			return ans;
		};
		
		std::cout << solve(solve, 0, 2 * n - 1) << "\n";
	}
	return 0;
}