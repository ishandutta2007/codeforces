#include <bits/stdc++.h>
int main()
{
	const int Mod = 998244353;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, m; std::cin >> n >> m;
		std::vector<int> a(n);
		for(int &x : a) std::cin >> x;
		
		std::vector<std::vector<int>> G(n);
		std::vector<int> ind(n);
		for(int i = 0, u, v; i < m; ++i)
		{
			std::cin >> u >> v; --u; --v;
			G[u].push_back(v);
			++ind[v];
		}
		
		std::queue<int> q;
		for(int i = 0; i < n; ++i) if(ind[i] == 0) q.push(i);
		
		std::vector<int> ord;
		while(q.size())
		{
			int u = q.front(); ord.push_back(u); q.pop();
			for(int v : G[u]) if(--ind[v] == 0) q.push(v);
		}
		
		int ans = 0;
		for(int _ = 0; _ < n; ++_)
		{
			std::vector<int> S;
			for(int i : ord) if(a[i]) S.push_back(i);
			if(!S.size()) break;
			++ans;
			for(int i : S)
			{
				--a[i];
				for(int j : G[i]) ++a[j];
			}
		}
		
		std::vector<int> f = a;
		for(int i : ord)
		for(int j : G[i]) f[j] = (f[j] + f[i]) % Mod;
		ans = (ans + f[ord.back()]) % Mod;
		std::cout << ans << "\n";
	}
	return 0;
}