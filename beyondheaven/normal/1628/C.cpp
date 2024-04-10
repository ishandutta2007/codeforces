#include <bits/stdc++.h>
const int MaxN = 1e3 + 5;

int n, a[MaxN][MaxN], b[MaxN][MaxN], c[MaxN][MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 0; i <= n + 1; ++i)
		for(int j = 0; j <= n + 1; ++j) a[i][j] = b[i][j] = c[i][j] = 0;
		
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) std::cin >> a[i][j];
		
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			if(i == 1) b[i][j] = 0;
			else b[i][j] = (c[i - 1][j] ^ 1);
			
			if(b[i][j])
			{
				c[i + 1][j] ^= 1;
				c[i][j - 1] ^= 1;
				c[i][j + 1] ^= 1;
			}
		}
		
		int ans = 0;
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		if(b[i][j]) ans ^= a[i][j];
		std::cout << ans << "\n";
	}
	return 0;
}