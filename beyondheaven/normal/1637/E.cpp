#include <bits/stdc++.h>
const int MaxN = 3e5 + 5;

void solve()
{
	int n, m; std::cin >> n >> m;
	std::map<int, int> cnt;
	for(int i = 0, x; i < n; ++i) std::cin >> x, ++cnt[x];
	
	std::vector<int> V;
	for(const auto &p : cnt) V.push_back(p.second);
	std::sort(V.begin(), V.end());
	V.erase(std::unique(V.begin(), V.end()), V.end());
	
	auto rk = [&](int x)
	{
		return std::lower_bound(V.begin(), V.end(), x) - V.begin();
	};
	
	std::vector<std::vector<int>> G(V.size());
	std::vector<std::vector<std::set<std::pair<int, int>>>> Q(V.size(),
		std::vector<std::set<std::pair<int, int>>>(V.size()));
	
	for(const auto &p : cnt) G[rk(p.second)].push_back(p.first);
	for(int i = 0, x, y; i < m; ++i)
	{
		std::cin >> x >> y;
		Q[rk(std::min(cnt[x], cnt[y]))]
			[rk(std::max(cnt[x], cnt[y]))].emplace(x, y);
	}
	
	for(int i = 0; i < int(V.size()); ++i)
	std::sort(G[i].begin(), G[i].end(), std::greater<>());
	
	int64_t ans = 0;
	
	using Tuple = std::array<int, 3>;
	
	for(int a = 0; a < int(V.size()); ++a)
	for(int b = a; b < int(V.size()); ++b)
	if(a == b)
	{
		auto &w = G[a]; auto &ban = Q[a][a];
		int t = w.size(), s = ban.size();
		if(s == int64_t(t) * (t - 1) / 2) continue;
		
		std::priority_queue<Tuple> q;
		for(int i = 0; i + 1 < t; ++i)
		{
			q.push({w[i] + w[i + 1], i, i + 1});
			if(int(q.size()) > s) break;
		}
		
		while(!q.empty())
		{
			auto x = q.top(); q.pop();
			if(!ban.count({w[x[1]], w[x[2]]}) && !ban.count({w[x[2]], w[x[1]]}))
			{
				ans = std::max(ans, int64_t(x[0]) * 2 * V[a]);
				break;
			}
			if(x[2] != t - 1) q.push({w[x[1]] + w[x[2] + 1], x[1], x[2] + 1});
		}
	}
	else
	{
		auto &l = G[a], &r = G[b]; auto &ban = Q[a][b];
		int s = ban.size();
		if(s == int64_t(l.size()) * int64_t(r.size())) continue;
		
		std::priority_queue<Tuple> q;
		for(int i = 0; i < int(l.size()); ++i)
		{
			q.push({l[i] + r[0], i, 0});
			if(int(q.size()) > s) break;
		}
		
		while(!q.empty())
		{
			auto x = q.top(); q.pop();
			if(!ban.count({l[x[1]], r[x[2]]}) && !ban.count({r[x[2]], l[x[1]]}))
			{
				ans = std::max(ans, int64_t(x[0]) * (V[a] + V[b]));
				break;
			}
			if(x[2] != int(r.size()) - 1) q.push({l[x[1]] + r[x[2] + 1], x[1], x[2] + 1});
		}
	}
	std::cout << ans << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--) solve();
	return 0;
}