#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, k; std::cin >> n >> k;
		std::vector<int> cnt(26);
		for(int i = 0; i < n; ++i)
		{
			char c; std::cin >> c;
			cnt[c - 'a'] += 1;
		}
		
		std::vector<int> ans(k, n / k);
		for(int i = 0; i < 26; ++i)
		{
			for(int j = cnt[i]; j < k; ++j) ans[j] = std::min(ans[j], i);
		}
		
		for(int i = 0; i < k; ++i) std::cout << char(ans[i] + 'a');
		std::cout << "\n";
	}
	return 0;
}