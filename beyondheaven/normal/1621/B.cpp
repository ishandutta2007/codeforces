#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::map<int, int> V;
		std::map<std::pair<int, int>, int> M;
		
		int mx = 0, mn = 1e9;
		for(int i = 0, l, r, c; i < n; ++i)
		{
			std::cin >> l >> r >> c;
			mn = std::min(mn, l);
			mx = std::max(mx, r);
			
			if(!V.count(l)) V[l] = c;
			else V[l] = std::min(V[l], c);
			if(!V.count(r)) V[r] = c;
			else V[r] = std::min(V[r], c);
			
			if(!M.count({l, r})) M[{l, r}] = c;
			else M[{l, r}] = std::min(M[{l, r}], c);
			
			if(M.count({mn, mx})) std::cout << std::min(M[{mn, mx}], V[mn] + V[mx]) << "\n";
			else std::cout << V[mn] + V[mx] << "\n";
		}
	}
	return 0;
}