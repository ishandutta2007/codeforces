#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 223456;
const int P = 998244353;
int n, m, rnk;
i64 base[maxN], p[maxN], dp[60][60][2];
int cnt[maxN], ans[maxN];

void dfs1(int d, i64 x)
{
	if (d == rnk)
	{
		cnt[__builtin_popcountll(x)]++;
	}
	else
	{
		dfs1(d + 1, x);
		dfs1(d + 1, x ^ p[d]);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		i64 x;
		scanf("%lld", &x);
		for (int j = m - 1; j >= 0; j--)
		{
			if (base[j])
			{
				x = min(x, base[j] ^ x);
			}
			else if (x & (1ll << j))
			{
				base[j] = x;
				p[rnk++] = x;
				break;
			}
		}
	}
	if (rnk <= m / 2)
	{
		dfs1(0, 0);
		i64 multi = 1;
		for (int i = 0; i < n - rnk; i++)
			multi = multi * 2 % P;
		for (int i = 0; i <= m; i++)
		{
			printf("%lld ", cnt[i] * multi % P);
		}
	}
	else
	{
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = i - 1; j >= 0; j--)
				base[i] = min(base[i], base[i] ^ base[j]);
		}
		rnk = 0;
		for (int i = 0; i < m; i++)
			if (base[i] == 0)
			{
				i64 x = (1ll << i);
				for (int j = i + 1; j < m; j++)
					if (base[j] & (1ll << i))
					{
						x ^= (1ll << j);
					}
				p[rnk++] = x;
			}
		dfs1(0, 0);
		for (int x = 0; x <= m; x++)
		{

			memset(dp, 0, sizeof(dp));
			dp[0][0][0] = 1;
			for (int j = 0; j < m; j++)
				for (int k = 0; k <= m; k++)
					for (int par = 0; par <= 1; par++)
					{
						dp[j + 1][k + 1][par ^ (j < x)] += dp[j][k][par];
						dp[j + 1][k][par] += dp[j][k][par];
					}
			for (int k = 0; k <= m; k++)
			{
				i64 w = dp[m][k][0] - dp[m][k][1];
				w %= P;
				if (w < 0)
					w += P;
				ans[k] = (ans[k] + cnt[x] * w) % P;
			}
		}
		i64 multi = 1;
		for (int i = 0; i < n; i++)
			multi = multi * 2 % P;
		for (int i = 0; i < m; i++)
			multi = multi * (P + 1) / 2 % P;
		for (int i = 0; i <= m; i++)
		{
			printf("%lld ", ans[i] * multi % P);
		}
	}
}