#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, a[MaxN];
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		int c0 = std::count(a + 1, a + n + 1, 0),
			c1 = std::count(a + 1, a + n + 1, 1);
		
		if(!c1) { std::cout << "YES" << "\n"; continue; }
		else if(c0) { std::cout << "NO" << "\n"; continue; }
		else
		{
			bool ans = true;
			std::set<int> s(a + 1, a + n + 1);
			for(int i = 1; i <= n; ++i) ans &= (!s.count(a[i] + 1));
			std::cout << (ans ? "YES" : "NO") << "\n";
		}
	}
	return 0;
}