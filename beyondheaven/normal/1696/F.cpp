#include <bits/stdc++.h>
const int MaxN = 100 + 5;

int n, d[MaxN][MaxN], f[MaxN][MaxN][MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i < n; ++i)
		for(int j = 1; j <= n - i; ++j)
		for(int k = 1; k <= n; ++k)
		{
			char c; std::cin >> c;
			f[i][i + j][k] = f[j + i][i][k] = c - '0';
		}
		
		bool solved = false;
		for(int t = 2; t <= n; ++t) if(!solved)
		{
			for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) d[i][j] = (i == j ? 0 : n + 1);
			
			std::vector<std::array<int, 2>> E;
			auto add = [&](int x, int y) { E.push_back({x, y}); d[x][y] = d[y][x] = 1; };
			
			auto dfs = [&](auto &&self, int u, int p)
			{
				if(int(E.size()) >= n) return;
				for(int v = 1; v <= n; ++v)
				if(v != p && f[p][v][u]) add(u, v), self(self, v, u);
			};
			
			add(1, t);
			dfs(dfs, 1, t);
			dfs(dfs, t, 1);
			
			if(int(E.size()) == n - 1)
			{
				for(int k = 1; k <= n; ++k)
				for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
				
				bool ok = true;
				for(int x = 1; x <= n; ++x)
				for(int y = x + 1; y <= n; ++y)
				for(int z = 1; z <= n; ++z) ok &= (f[x][y][z] == (d[x][z] == d[y][z]));
				
				if(ok)
				{
					std::cout << "Yes" << "\n";
					for(auto e : E) std::cout << e[0] << " " << e[1] << "\n";
					solved = true;
				}
			}
		}
		
		if(!solved) std::cout << "No" << "\n";
	}
	return 0;
}