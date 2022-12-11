#include <bits/stdc++.h>
const int MaxN = 1e6 + 5;

int n, L, c[MaxN], s[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> L;
		for(int i = 1; i <= L; ++i) c[i] = s[i] = 0;
		for(int i = 1, x; i <= n; ++i) std::cin >> x, c[x] = 1;
		for(int i = 1; i <= L; ++i) s[i] = s[i - 1] + c[i];
		
		bool ans = true;
		for(int t = 1; t <= L; ++t) if(ans && !c[t])
		{
			for(int i = 1; i * t <= L; ++i) if(c[i])
			{
				int z = s[std::min(i * (t + 1) - 1, L)] - s[i * t - 1];
				if(z) { ans = false; break; }
			}
		}
		
		std::cout << (ans ? "Yes" : "No") << "\n";
	}
	return 0;
}