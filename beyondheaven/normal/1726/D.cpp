#include <bits/stdc++.h>
int main()
{
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::cin.tie(nullptr);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, m; std::cin >> n >> m;
		std::vector<int> u(m), v(m);
		for(int i = 0; i < m; ++i)
		{
			std::cin >> u[i] >> v[i], --u[i], --v[i];
			if(u[i] > v[i]) std::swap(u[i], v[i]);
		}
		
		std::vector<int> p(m), ans;
		std::iota(p.begin(), p.end(), 0);
		
		while(true)
		{
			std::vector<int> repr(n);
			std::iota(repr.begin(), repr.end(), 0);
			ans.assign(m, 0);
			
			auto find = [&](int x)
			{
				while(x != repr[x]) x = repr[x] = repr[repr[x]];
				return x;
			};
			
			std::vector<std::array<int, 2>> E;
			for(int i : p)
			{
				if(find(u[i]) == find(v[i])) ans[i] = 1, E.push_back({ u[i], v[i] });
				else repr[find(u[i])] = find(v[i]);
			}
			
			std::sort(E.begin(), E.end());
			if(E.size() == 3 && E[0][0] == E[1][0]
				&& E[0][1] == E[2][0] && E[1][1] == E[2][1])
			std::shuffle(p.begin(), p.end(), rng);
			else break;
		}
		
		for(int i = 0; i < m; ++i) std::cout << ans[i];
		std::cout << "\n";
	}
	return 0;
}