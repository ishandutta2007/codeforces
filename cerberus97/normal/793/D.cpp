/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 81, inf = 1e5;

int dist[N][N] = {0}, dp[N][N][N][N];
vector <pii> g[N];
vector <pii>::iterator mp[N][N];

int main()
{
	int n, t, m;
	cin >> n >> t >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		if (!dist[u][v] or dist[u][v] > c)
			dist[u][v] = c;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			if (dist[i][j])
				g[i].push_back({j, dist[i][j]});

		mp[i][1] = g[i].begin();
		for (int l = 2; l <= n; ++l)
		{
			mp[i][l] = mp[i][l - 1];
			while (mp[i][l] != g[i].end() and mp[i][l]->first < l)
				++mp[i][l];
		}
	}

	for (int k = 1; k <= t; ++k)
		for (int l = 1; l <= n; ++l)
			for (int r = l; r <= n; ++r)
				for (int i = l; i <= r; ++i)
					dp[i][l][r][k] = inf;

	for (int l = 1; l <= n; ++l)
		for (int r = l; r <= n; ++r)
			for (int i = l; i <= r; ++i)
				dp[i][l][r][1] = 0;

	for (int k = 2; k <= t; ++k)
	{
		for (int l = 1; l <= n; ++l)
		{
			for (int r = l + k - 1; r <= n; ++r)
			{
				for (int i = l; i <= r; ++i)
				{
					int temp = inf;
					auto j = mp[i][l];
					while (j != g[i].end())
					{
						if (j->first > r)
							break;

						if (j->first < i)
							temp = min(temp, j->second + dp[j->first][l][i - 1][k - 1]);

						else if (j->first > i)
							temp = min(temp, j->second + dp[j->first][i + 1][r][k - 1]);

						++j;
					}

					dp[i][l][r][k] = temp;
				}
			}
		}
	}

	int ans = inf;
	for (int l = 1; l <= n; ++l)
		for (int r = l + t - 1; r <= n; ++r)
			for (int i = l; i <= r; ++i)
				ans = min(ans, dp[i][l][r][t]);

	if (ans == inf)
		cout << -1;

	else
		cout << ans;
}