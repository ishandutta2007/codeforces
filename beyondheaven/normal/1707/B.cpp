#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, zero = 0; std::cin >> n;
		
		std::vector<int> V;
		for(int i = 0, x; i < n; ++i)
		{
			std::cin >> x;
			if(x == 0) ++zero;
			else V.push_back(x);
		}
		
		while(V.size() > 1)
		{
			std::vector<int> nV;
			if(zero) nV.push_back(V[0]), --zero;
			for(int i = 1; i < int(V.size()); ++i) nV.push_back(V[i] - V[i - 1]);
			std::sort(nV.begin(), nV.end());
			
			V.clear();
			for(int x : nV) if(x == 0) ++zero; else V.push_back(x);
		}
		
		std::cout << (V.size() ? V[0] : 0) << "\n";
	}
	return 0;
}