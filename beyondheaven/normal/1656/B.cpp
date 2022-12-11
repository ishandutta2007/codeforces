#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, k, a[MaxN];
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> k;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		bool ans = false;
		std::set<int> s(a + 1, a + n + 1);
		
		for(int i = 1; i <= n; ++i) ans |= s.count(a[i] + k);
		std::cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}