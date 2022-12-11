#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, d; std::cin >> n >> d;
	std::vector<int> V;
	std::vector<std::pair<int, int>> P;
	
	std::map<int, int> mp;
	
	for(int i = 1, s, a; i <= n; ++i)
	{
		std::cin >> s >> a;
		if(s < d) continue;
		
		s -= d; a -= d;
		
		V.push_back(s);
		V.push_back(a);
		P.emplace_back(s, a);
		if(s >= a)
		{
			if(!mp.count(a)) mp[a] = s;
			else mp[a] = std::min(mp[a], s);
		}
	}
	
	int last = INT_MAX;
	for(auto it = mp.rbegin(); it != mp.rend(); ++it)
	last = it -> second = std::min(it -> second, last);
	
	std::sort(V.begin(), V.end());
	V.erase(std::unique(V.begin(), V.end()), V.end());
	int m = V.size();
	
	auto rk = [&](int x) {return std::lower_bound(V.begin(), V.end(), x) - V.begin() + 1;};
	
	std::vector<int> dp(m + 1), val(m + 1);
	std::vector<std::vector<int>> G(m + 1);
	
	int cnt = 0;
	for(const auto &p : P)
	if(p.first < p.second)
	{
		auto t = mp.upper_bound(p.first);
		if(t != mp.end() && p.second > t -> second) continue;
		G[rk(p.second)].push_back(rk(p.first));
	}
	else ++cnt;
	
	
	for(int i = 1; i <= m; ++i)
	{
		dp[i] = dp[i - 1];
		for(int j : G[i]) dp[i] = std::max(dp[i], dp[j] + 1);
	}
	
	printf("%d\n", dp[m] + cnt);
	return 0;
}