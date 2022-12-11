#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	using ll = long long;
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i) std::cin >> a[i];
		for(int i = 0; i < n; ++i) std::cin >> b[i];

		auto calc = [&](const auto &v, int t)
		{
			ll res = 0;
			for(int i = 0; i < std::min(t, int(v.size())); ++i) res += v[i];
			return res;
		};

		std::vector<int> p, q;
	 	for(int i = 0; i < n; ++i) (a[i] ? p : q).push_back(b[i]);

	 	std::sort(p.begin(), p.end(), std::greater<>());
	 	std::sort(q.begin(), q.end(), std::greater<>());
	 	
	 	ll ans = 0, ans2 = 0;
	 	for(int x : p) ans += x;
	 	for(int x : q) ans += x;
	 	
	 	for(int t : { 0, 1 })
	 	ans2 = std::max(ans2, calc(p, int(q.size()) - t) + calc(q, int(p.size()) - (t ^ 1)));
	 	std::cout << ans + ans2 << "\n";
	}
	return 0;
}