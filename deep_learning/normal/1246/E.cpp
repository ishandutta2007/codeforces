#include <algorithm>
#include <utility>
#include <cstdio>
#include <bitset>
int arr[25], dep[25];
std::bitset<2005> dp[70005];
std::pair<int, int> seq[25];
int main()
{
	// freopen("1246E.in", "r", stdin);
	int n, k, sum = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		sum += arr[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				dp[i] |= dp[i ^ (1 << j)] << arr[j];
		}
		for (int j = sum / k; j >= 0; j--)
		{
			if (dp[i][j * k])
				dp[i][j] = 1;
		}
	}
	if (!dp[(1 << n) - 1][1])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int x = (1 << n) - 1, y = 1, d = 0;
	while (x)
	{
		if (y * k <= sum && dp[x][y * k])
		{
			y *= k;
			d++;
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			if (x & (1 << i) && y >= arr[i] && dp[x ^ (1 << i)][y - arr[i]])
			{
				dep[i] = d;
				x ^= 1 << i;
				y -= arr[i];
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		seq[i] = {dep[i], arr[i]};
	for (int cnt = n; cnt > 1; cnt--)
	{
		std::sort(seq, seq + cnt);
		printf("%d %d\n", seq[cnt - 1].second, seq[cnt - 2].second);
		seq[cnt - 2].second += seq[cnt - 1].second;
		while (!(seq[cnt - 2].second % k))
		{
			seq[cnt - 2].second /= k;
			seq[cnt - 2].first--;
		}
	}
	return 0;
}