#include <bits/stdc++.h>
int main()
{
	using ll = long long;
	const int L = 120;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int q; std::cin >> q;
	while(q--)
	{
		ll t; std::cin >> t;
		int x, y; std::cin >> x >> y;
		if(t < x + y) { std::cout << "NO" << "\n"; continue; }
		
		std::vector<std::vector<ll>> f(L, std::vector<ll>(L)), g = f;
		f[0][0] = t - (x + y) + 1; g[0][0] = t - (x + y);
		for(int i = 0; i < L; ++i)
		for(int j = 0; j < L; ++j)
		{
			if(j + 1 < L) f[i][j + 1] += (f[i][j] + 1) / 2, g[i][j + 1] += (g[i][j] + 1) / 2;
			if(i + 1 < L) f[i + 1][j] += f[i][j] / 2, g[i + 1][j] += g[i][j] / 2;
		}
		std::cout << (f[x][y] != g[x][y] ? "YES" : "NO") << "\n";
	}
	return 0;
}