#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <tuple>
template <typename T> constexpr T my_abs(const T &x) { return x < 0 ? -x : x; }
using ll = long long;
constexpr int MOD = 1e9 + 7;
inline int quick_pow(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1)
			res = (ll)res * a % MOD;
		a = (ll)a * a % MOD;
		n >>= 1;
	}
	return res;
}
int dp_up[2005][2005], dp_left[2005][2005], sup[2005][2005], sleft[2005][2005];
int up[2005][2005], left[2005][2005];
char arr[2005][2005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1246C.in", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	if (n == 1 && m == 1)
	{
		puts("1");
		return 0;
	}
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);
	for (int i = 0; i < n; i++)
	{
		left[i][m] = m - 1;
		for (int j = m - 1; j >= 0; j--)
		{
			left[i][j] = left[i][j + 1];
			while (left[i][j] >= 0 && arr[i][left[i][j]] == '.')
				left[i][j]--;
			left[i][j] = std::max(-1, left[i][j] - 1);
		}
	}
	for (int j = 0; j < m; j++)
	{
		up[n][j] = n - 1;
		for (int i = n - 1; i >= 0; i--)
		{
			up[i][j] = up[i + 1][j];
			while (up[i][j] >= 0 && arr[up[i][j]][j] == '.')
				up[i][j]--;
			up[i][j] = std::max(-1, up[i][j] - 1);
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		printf("(%d,%d)%c", left[i][j], up[i][j], " \n"[j + 1 == m]);
	// }
	// printf("(0,0) ");
	sup[0][0] = sleft[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = !i; j < m; j++)
		{
			if (i && up[i][j] < i)
			{
				dp_up[i][j] = sup[i - 1][j];
				if (~up[i][j])
					dp_up[i][j] = (dp_up[i][j] + MOD - sup[up[i][j]][j]) % MOD;
			}
			if (j && left[i][j] < j)
			{
				dp_left[i][j] = sleft[i][j - 1];
				if (~left[i][j])
					dp_left[i][j] = (dp_left[i][j] + MOD - sleft[i][left[i][j]]) % MOD;
			}
			// printf("(%d,%d)%c", dp_left[i][j], dp_up[i][j], " \n"[j + 1 == m]);
			sup[i][j] = ((i ? sup[i - 1][j] : 0) + dp_left[i][j]) % MOD;
			sleft[i][j] = ((j ? sleft[i][j - 1] : 0) + dp_up[i][j]) % MOD;
		}
	}
	printf("%d\n", (dp_up[n - 1][m - 1] + dp_left[n - 1][m - 1]) % MOD);
	return 0;
}