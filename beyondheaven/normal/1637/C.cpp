#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;

int n, a[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		if(n == 3 && (a[2] & 1)) {std::cout << -1 << "\n"; continue;}
		if(*std::max_element(a + 2, a + n) == 1) {std::cout << -1 << "\n"; continue;}
		
		int64_t ans = 0;
		for(int i = 2; i < n; ++i) ans += (a[i] + 1) / 2;
		std::cout << ans << "\n";
	}
	return 0;
}