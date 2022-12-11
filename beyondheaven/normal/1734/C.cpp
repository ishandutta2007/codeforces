#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::string S; std::cin >> S;
		
		std::vector<std::vector<int>> D(n + 1);
		for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; j += i) D[j].push_back(i);
		
		long long ans = 0;
		std::vector<bool> mark(n + 1);
		for(int i = 1; i <= n; ++i)
		{
			if(S[i - 1] == '0')
			{
				for(int j : D[i]) if(!mark[j]) { ans += j; break; }
			}
			else for(int j : D[i]) mark[j] = true;
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}