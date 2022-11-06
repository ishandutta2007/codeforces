#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
ll md[] = {1000000007, 998244353}; 
int bz[] = {37, 31}; 
ll ha[2][100005], hb[2][100005], bs[2][100005]; 
int n, m, x, dp[100005][35]; 
char a[100005], b[100005]; 
inline void upd(int &x, int y)
{
	x = max(x, y); 
}
inline bool check(int x, int y, int len)
{
	for (int i = 0; i < 2; i++)
		if ((ha[i][x + len - 1] - ha[i][x - 1] * bs[i][len] % md[i] + md[i]) % md[i]
		 != (hb[i][y + len - 1] - hb[i][y - 1] * bs[i][len] % md[i] + md[i]) % md[i])
			return false; 
	return true; 
}
inline int work(int x, int y)
{
	int l = 0, r = min(n - x + 1, m - y + 1), ans = 0; 
	while (l <= r)
	{
		int mid = l + r >> 1; 
		if (check(x, y, mid))
		{
			ans = mid; 
			l = mid + 1; 
		}
		else
			r = mid - 1; 
	}
	// cout << x << " " << y << " " << ans << endl; 
	return ans; 
}
int main()
{
	// freopen("822E.in", "r", stdin); 
	scanf("%d%s%d%s%d", &n, a + 1, &m, b + 1, &x); 
	for (int j = 0; j < 2; j++)
	{
		bs[j][0] = 1; 
		for (int i = 1; i <= n; i++)
		{
			bs[j][i] = bs[j][i - 1] * bz[j] % md[j]; 
			ha[j][i] = (ha[j][i - 1] * bz[j] + a[i] - 'a') % md[j]; 
		}
		for (int i = 1; i <= m; i++)
			hb[j][i] = (hb[j][i - 1] * bz[j] + b[i] - 'a') % md[j]; 
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < x; j++)
		{
			upd(dp[i + 1][j], dp[i][j]); 
			int res = work(i + 1, dp[i][j] + 1); 
			upd(dp[i + res][j + 1], dp[i][j] + res); 
		}
	}
	for (int i = 0; i <= x; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[j][i] >= m)
			{
				printf("YES\n");
				return 0; 
			}
		}
	}
	printf("NO\n");
	return 0; 
}