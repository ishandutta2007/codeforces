#include <bits/stdc++.h>
int main()
{
	auto chkmin = [&](int &x, int y) { x = std::min(x, y); };
	
	int n, k; std::cin >> n >> k;
	std::vector<int> a(n);
	for(int &x : a) std::cin >> x, --x;
	if(k >= n - 1) { std::cout << 0 << "\n"; exit(0); }
	
	std::vector<int> b(n);
	for(int i = 0; i < n; ++i) b[a[i]] = i;
	
	const int inf = n * n;
	std::vector<std::vector<int>> f(n, std::vector<int>((1 << k), inf));
	std::vector<int> pre(n), mask(n);
	
	for(int i = 0, U = (1 << k) - 1; i < n; ++i)
	{
		if(i <= k) f[i][(U << i) & U] = 0;
		
		if(i - k - 1 >= 0)
		{
			int t = i - k - 1;
			for(int j = 0; j < n; ++j) if(b[t] > b[j]) pre[j] += 1;
		}
		
		for(int S = 0; S < (1 << k); ++S) if(f[i][S] < inf)
		{
			auto calc = [&](int j)
			{
				int ans = (b[i] > b[j]) + pre[j];
				for(int t = 0; t < k && i - 1 - t >= 0; ++t)
				if(((S >> t) & 1) && b[i - 1 - t] > b[j]) ans += 1;
				return ans;
			};
			
			for(int j = 0; j < k; ++j) if(!((S >> j) & 1))
			chkmin(f[i][S | (1 << j)], f[i][S] + calc(i - 1 - j));
			
			for(int j = 1; j <= k && i + j < n; ++j)
			{
				if(!((S >> (k - j)) & 1)) break;
				chkmin(f[i + j][((S << j) | (1 << (j - 1))) & U], f[i][S] + calc(i + j));
			}
			
			if(i + k + 1 < n && S == U) chkmin(f[i + k + 1][0], f[i][S] + calc(i + k + 1));
		}
	}
	
	std::cout << f[n - 1][(1 << k) - 1] << "\n";
	return 0;
}