#include <bits/stdc++.h>
const int MaxN = 1e4 + 5;

int T, n, a[MaxN], mx[MaxN], mn[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		mx[1] = a[1];
		for(int i = 2; i <= n; ++i) mx[i] = std::max(a[i], mx[i - 1]);
		mn[n] = a[n];
		for(int i = n - 1; i >= 1; --i) mn[i] = std::min(a[i], mn[i + 1]);
		
		bool flag = true;
		for(int i = 1; i < n; ++i) if(mx[i] > mn[i + 1]) flag = false;
		if(!flag) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}