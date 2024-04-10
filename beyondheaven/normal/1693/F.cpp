#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, a[MaxN], s[MaxN];
std::set<int> V[MaxN];

int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) V[i].clear();
		
		int cnt1 = 0;
		for(int i = 1; i <= n; ++i)
		{
			char c; std::cin >> c;
			a[i] = c - '0';
			cnt1 += a[i];
		}
		
		if(cnt1 < n - cnt1)
		{
			for(int i = 1; i <= n; ++i) a[i] ^= 1;
			std::reverse(a + 1, a + n + 1);
			cnt1 = n - cnt1; 
		}
		
		for(int i = 1; i <= n; ++i)
		{
			s[i] = s[i - 1] + (a[i] == 1 ? 1 : -1);
			if(s[i] > 0) V[s[i]].insert(i);
		}
		
		auto apply = [&](int l, int r)
		{
			int m = (r - l + 1) / 2;
			for(int i = l; i < l + m; ++i) a[i] = 0;
			for(int i = l + m; i <= r; ++i) a[i] = 1;
			for(int i = l; i <= r; ++i) if(s[i] > 0) V[s[i]].erase(i);
			for(int i = l; i <= r; ++i)
			{
				s[i] = s[i - 1] + (a[i] == 1 ? 1 : -1);
				if(s[i] > 0) V[s[i]].insert(i);
			}
		};
		
		int idx = n, ans = 0;
		while(true)
		{
			while(idx > 0 && s[idx - 1] < s[idx]) --idx;
			
			if(s[idx] <= 0)
			{
				ans += (s[idx] == cnt1 - n ? 0 : 1);
				break;
			}
			
			assert(V[s[idx]].size() >= 2);
			apply(*V[s[idx]].begin() + 1, idx);
			++ans;
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}