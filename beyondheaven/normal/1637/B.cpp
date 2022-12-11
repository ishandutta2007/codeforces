#include <bits\stdc++.h>
const int MaxN = 105;

int T, n, a[MaxN], mex[MaxN][MaxN], f[MaxN][MaxN];
int main()
{
	std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		for(int l = 1; l <= n; ++l)
		{
			std::vector<int> vis(n + 1);
			for(int r = l; r <= n; ++r)
			{
				if(a[r] <= n) vis[a[r]] = 1;
				mex[l][r] = std::find(vis.begin(), vis.end(), 0) - vis.begin();
			}
		}
		
		int ans = 0;
		for(int len = 1; len <= n; ++len)
		for(int i = 1, j = len; j <= n; ++i, ++j)
		{
			f[i][j] = mex[i][j] + 1;
			for(int k = i; k < j; ++k)
			f[i][j] = std::max(f[i][j], f[i][k] + mex[k + 1][j] + 1);
			ans += f[i][j];
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}