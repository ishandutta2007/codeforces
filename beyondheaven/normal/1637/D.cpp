#include <bits/stdc++.h>
const int MaxN = 105;

void chk(int &x, int y) {x = std::min(x, y);}

int T, n, a[MaxN], b[MaxN], s[MaxN], dp[MaxN][MaxN * MaxN];
int main()
{
	std::cin >> T;
	while(T--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(s, 0, sizeof(s));
		memset(dp, 0x3f, sizeof(dp));
		
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		for(int i = 1; i <= n; ++i) std::cin >> b[i];
		s[n] = a[n] + b[n];
		for(int i = n - 1; i; --i) s[i] = s[i + 1] + a[i] + b[i];
		
		dp[n][a[n]] = dp[n][b[n]] = 0;
		for(int i = n; i > 1; --i)
		for(int S = 0; S <= s[i]; ++S)
		{
			chk(dp[i - 1][S + a[i - 1]], dp[i][S] + a[i - 1] * S + b[i - 1] * (s[i] - S));
			chk(dp[i - 1][S + b[i - 1]], dp[i][S] + b[i - 1] * S + a[i - 1] * (s[i] - S));
		}
		
		int ans = 0x3f3f3f3f;
		for(int S = 0; S <= s[1]; ++S) ans = std::min(ans, dp[1][S]);
		ans *= 2;
		
		for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
		{
			ans += a[i] * a[i] + a[j] * a[j];
			ans += b[i] * b[i] + b[j] * b[j];
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}