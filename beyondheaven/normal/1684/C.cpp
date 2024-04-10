#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

std::vector<int> a[MaxN], b[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, m; std::cin >> n >> m;
		for(int i = 1; i <= n; ++i)
		{
			a[i].resize(m);
			for(int &x : a[i]) std::cin >> x;
			b[i] = a[i];
			std::sort(b[i].begin(), b[i].end());
		}
		
		auto check = [&]()
		{
			for(int i = 1; i <= n; ++i)
			if(!std::is_sorted(a[i].begin(), a[i].end())) return false;
			return true;
		};
		
		if(check()) { std::cout << 1 << " " << 1 << "\n"; continue; }
		
		for(int t = 0; t < m; ++t)
		{
			int idx = -1;
			for(int i = 1; i <= n; ++i) if(a[i][t] != b[i][t])
			for(int j = t + 1; j < m; ++j) if(a[i][j] == b[i][t]) idx = j;
			
			if(idx != -1)
			{
				for(int i = 1; i <= n; ++i) std::swap(a[i][t], a[i][idx]);
				if(check()) std::cout << t + 1 << " " << idx + 1 << "\n";
				else std::cout << -1 << "\n";
				break;
			}
		}
	}
	return 0;
}