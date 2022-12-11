#include <bits/stdc++.h>
const int MaxN = 5e3 + 5;

int n, a[MaxN];
int64_t b[MaxN];

int main()
{
	std::cin >> n;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	
	int64_t ans = (int64_t(1) << 60);
	for(int t = 1; t <= n; ++t)
	{
		b[t] = 0;
		
		int64_t cur = 0;
		
		for(int i = t - 1; i >= 1; --i)
		{
			int64_t x = b[i + 1] / a[i] + 1;
			cur += x;
			b[i] = int64_t(x) * a[i];
		}
		
		for(int i = t + 1; i <= n; ++i)
		{
			int64_t x = b[i - 1] / a[i] + 1;
			cur += x;
			b[i] = int64_t(x) * a[i];
		}
		
		ans = std::min(ans, cur);
	}
	std::cout << ans << "\n";
	return 0;
}