#include <bits/stdc++.h>
void solve()
{
	int n, m, ans = 0; std::cin >> n >> m;
	std::vector<int> a(n * m + 1), V;
	for(int i = 1; i <= n * m; ++i) std::cin >> a[i], V.push_back(a[i]);
	
	std::sort(V.begin(), V.end());
	std::unique(V.begin(), V.end());
	
	std::vector<int> cnt(n * m + 1), id(n * m + 1);
	std::vector<std::vector<int>> G(n * m + 1), p(n * m + 1);
	for(int i = 1; i <= n * m; ++i)
	{
		a[i] = std::lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
		++cnt[a[i]];
		G[a[i]].push_back(i);
	}
	
	for(int i = 1; i <= n * m; ++i)
	{
		cnt[i] += cnt[i - 1];
		for(int k = cnt[i - 1] + 1; k <= cnt[i]; ++k) p[i].push_back(k);
		std::sort(p[i].begin(), p[i].end(), [&](int x, int y)
			{
				if((x - 1) / m != (y - 1) / m) return (x - 1) / m > (y - 1) / m;
				return x < y;
			});
		
		for(int k : G[i]) id[p[i].back()] = k, p[i].pop_back();
	}
	
	#ifdef Dubug
	for(int i = 1; i <= n * m; ++i)
	{
		printf("%3d", id[i]);
		if(i % m == 0) puts("");
	}
	#endif
	
	for(int x = 1; x <= n * m; ++x)
	{
		for(int y = x; y && (x - 1) / m == (y - 1) / m; --y)
		ans += (id[y] < id[x]);
	}
	
	printf("%d\n", ans);
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	while(T--) solve();
	return 0;
}