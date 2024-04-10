#include <cstdio>
#include <cstring>
#include <utility>

int n, m;
char s[2048];
char p[512];

int ne[2048][256];

int end[2048][512];

std::pair<int, int> dp[2048][2048];

std::pair<int, int> getDP(int ps, int le)
{
	if (ps == n && !le)
		return std::make_pair(0, 0);
	if (ps >= n)
		return std::make_pair(-200000, 100000);
	if (dp[ps][le] != std::make_pair(-1, -1))
		return dp[ps][le];

	dp[ps][le] = std::make_pair(getDP(end[ps][0], le - 1).first + end[ps][0] - ps - m,
						   getDP(end[ps][0], le - 1).second + end[ps][0] - ps - m);
	if (end[ps][0] > n)
		dp[ps][le] = std::make_pair(-200000, 1000000);
	if (getDP(ps + 1, le).first + 1 > dp[ps][le].first)
		dp[ps][le].first = getDP(ps + 1, le).first + 1;
	if (getDP(ps + 1, le).second < dp[ps][le].second)
		dp[ps][le].second = getDP(ps + 1, le).second;
	//~ printf("DP %d %d :: (%d, %d) : E %d\n", ps, le, dp[ps][le].first, dp[ps][le].second, end[ps][0]);
	return dp[ps][le];
}

int main()
{
	scanf("%s", s);
	scanf("%s", p);

	n = strlen(s);
	m = strlen(p);

	for (int i = 0; i < 256; ++i)
	{
		ne[n][i] = n;
	}
	for (int i = n - 1; i >= 0; --i)
	{
		memcpy(ne[i], ne[i + 1], sizeof(ne[i]));
		ne[i][(int) s[i]] = i;
	}

	memset(end, 63, sizeof(end));
	end[n][m] = n;
	for (int i = n - 1; i >= 0; --i)
	{
		end[i][m] = i;
		for (int j = m - 1; j >= 0; --j)
		{
			int ns = ne[i][(int) p[j]] + 1;
			if (ns <= n)
				end[i][j] = end[ns][j + 1];
			else
				end[i][j] = n + 1;
		}
	}
	memset(dp, -1, sizeof(dp));
	//~ printf("%d %d\n", dp[0][0].first, dp[0][0].second);

	int pu = 0;
	int i;
	for (i = 0; i <= n; ++i)
	{
		while (getDP(0, pu).second <= n && getDP(0, pu).second <= i)
			++pu;
		if (getDP(0, pu).second > n)
		{
			--pu;
			if (i < n)
				printf("%d ", pu);
			else
				printf("%d\n", pu);
			++i;
			break;
		}
		--pu;
		if (i < n)
			printf("%d ", pu);
		else
			printf("%d\n", pu);
	}
	for (; i <= n; ++i)
	{
		while (getDP(0, pu).first < 0 || getDP(0, pu).first < i)
			--pu;
		if (i < n)
			printf("%d ", pu);
		else
			printf("%d\n", pu);
	}

	return 0;
}