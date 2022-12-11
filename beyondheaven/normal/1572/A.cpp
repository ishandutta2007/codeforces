#include <bits/stdc++.h>
void solve()
{
	int n; std::cin >> n;
	std::vector<std::vector<int>> G(n + 1);
	std::vector<int> deg(n + 1);
	
	for(int i = 1; i <= n; ++i)
	{
		std::cin >> deg[i];
		for(int j = 1, x; j <= deg[i]; ++j)
		std::cin >> x, G[x].push_back(i);
	}
	
	std::vector<int> ord;
	std::deque<int> q;
	
	for(int i = 1; i <= n; ++i) if(!deg[i]) q.push_back(i);
	
	while(!q.empty())
	{
		int u = q.front(); q.pop_front();
		ord.push_back(u);
		for(int v : G[u])
		if(--deg[v] == 0) q.push_back(v);
	}
	
	if(static_cast<int>(ord.size()) != n) return puts("-1"), void();
	
	std::vector<int> dp(n + 1, 1);
	for(int u : ord)
	for(int v : G[u])
	dp[v] = std::max(dp[v], dp[u] + (u > v ? 1 : 0));
	
	printf("%d\n", *std::max_element(dp.begin(), dp.end()));
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	while(T--) solve();
	return 0;
}