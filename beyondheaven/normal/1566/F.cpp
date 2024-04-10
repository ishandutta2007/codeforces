#include <bits/stdc++.h>
using LL = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	while(T--)
	{
		int n, m; std::cin >> n >> m;
		std::vector<LL> a(n);
		for(int i = 0; i < n; ++i) std::cin >> a[i];
		std::sort(a.begin(), a.end());
		
		std::vector<std::vector<std::pair<LL, LL>>> s(n + 1);
		for(int i = 0, x, y; i < m; ++i)
		{
			std::cin >> x >> y;
			auto it = std::lower_bound(a.begin(), a.end(), x);
			
			if(it == a.end()) s[n].emplace_back(x, y);
			else if(y < *it) s[it - a.begin()].emplace_back(x, y);
		}
		
		LL dis = 0;
		for(auto p : s[0]) dis = std::max(dis, a[0] - p.second);
		
		LL f1 = dis * 1, f2 = dis * 2;
		for(int i = 1; i < n; ++i)
		{
			auto &V = s[i];
			std::sort(V.begin(), V.end());
			int c = V.size();
			
			std::vector<LL> pre(c + 1), suf(c + 1);
			for(int j = 0; j < c; ++j)
			pre[j + 1] = std::max(pre[j], V[j].first - a[i - 1]);
			for(int j = c - 1; j >= 0; --j)
			suf[j] = std::max(suf[j + 1], a[i] - V[j].second);
			
			LL g1 = LLONG_MAX, g2 = LLONG_MAX;
			for(int j = 0; j <= c; ++j)
			{
				g1 = std::min(g1, f2 + pre[j] * 1 + suf[j] * 1);
				g1 = std::min(g1, f1 + pre[j] * 2 + suf[j] * 1);
				g2 = std::min(g2, f2 + pre[j] * 1 + suf[j] * 2);
				g2 = std::min(g2, f1 + pre[j] * 2 + suf[j] * 2);
			}
			
			f1 = g1; f2 = g2;
		}
		
		dis = 0;
		for(auto p : s[n]) dis = std::max(dis, p.first - a[n - 1]);
		
		printf("%lld\n", std::min(f1 + dis * 2, f2 + dis * 1));
	}
	return 0;
}