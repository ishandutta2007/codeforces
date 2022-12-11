#include <bits/stdc++.h>
int main()
{
	using ll = long long;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, k; std::cin >> n >> k;
		std::vector<ll> s(n + 1);
		for(int i = n - k + 1; i <= n; ++i) std::cin >> s[i];
		if(k == 1) { std::cout << "YES" << "\n"; continue; }
		
		int m = n - k + 1;
		
		std::vector<ll> a(n + 1);
		for(int i = m + 1; i <= n; ++i) a[i] = s[i] - s[i - 1];
		
		bool flag = true;
		for(int i = m + 1; i + 1 <= n; ++i) if(a[i] > a[i + 1]) flag = false;
		
		if(s[m] > a[m + 1] * m) flag = false;
		std::cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}