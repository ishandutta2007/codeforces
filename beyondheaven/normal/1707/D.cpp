#include <bits/stdc++.h>
const int MaxN = 2e3 + 5;

int n, Mod, C[MaxN][MaxN], f[MaxN][MaxN], S[MaxN][MaxN], ans[MaxN];
int pre[MaxN][MaxN], suf[MaxN][MaxN];
std::vector<int> G[MaxN];

int main()
{
	std::cin >> n >> Mod;
	for(int i = C[0][0] = 1; i <= n; ++i)
	for(int j = C[i][0] = 1; j <= i; ++j)
	C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
	
	for(int i = 1, u, v; i < n; ++i)
	{
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	auto dfs = [&](auto &&self, int u, int p) -> void
	{
		if(p) G[u].erase(std::find(G[u].begin(), G[u].end(), p));
		for(int v : G[u]) self(self, v, u);
		
		for(int i = 1; i < n; ++i)
		{
			f[u][i] = 1;
			for(int v : G[u]) f[u][i] = 1LL * f[u][i] * S[v][i] % Mod;
		}
		
		if(u != 1)
		{
			for(int i = 0; i < int(G[u].size()); ++i)
			{
				int v = G[u][i];
				for(int j = 1; j < n; ++j) pre[i][j] = suf[i][j] = S[v][j];
			}
			
			for(int i = 1; i < int(G[u].size()); ++i)
			for(int j = 1; j < n; ++j) pre[i][j] = 1LL * pre[i][j] * pre[i - 1][j] % Mod;
			
			for(int i = int(G[u].size()) - 1; i >= 1; --i)
			for(int j = 1; j < n; ++j) suf[i - 1][j] = 1LL * suf[i - 1][j] * suf[i][j] % Mod;
			
			for(int i = 0; i < int(G[u].size()); ++i)
			{
				int v = G[u][i];
				for(int j = 1, coef = 0; j < n; ++j)
				{
					f[u][j] = (f[u][j] + 1LL * coef * f[v][j]) % Mod;
					coef = (coef + 1LL * (i == 0 ? 1 : pre[i - 1][j]) *
						(i == int(G[u].size()) - 1 ? 1 : suf[i + 1][j])) % Mod;
				}
			}
		}
		
		for(int i = 1; i < n; ++i) S[u][i] = (S[u][i - 1] + f[u][i]) % Mod;
	};
	
	dfs(dfs, 1, 0);
	for(int i = 1; i < n; ++i)
	{
		ans[i] = f[1][i];
		for(int j = 1; j < i; ++j) ans[i] = (ans[i] - 1LL * C[i][j] * ans[j]) % Mod;
		std::cout << (ans[i] + Mod) % Mod << " ";
	}
	return 0;
}