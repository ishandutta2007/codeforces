/*
Hanit Banga
*/

#include <algorithm>
// #include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e3 + 5;

int len[N], xL[N], xR[N], yL[N], yR[N];
ll w[N][N] = {0}; //w[i][j] is sum of first j values of garland i
pii a[N][N], g[N][N];
bool off[N] = {0};

bool enclosed(int i, int x1, int y1, int x2, int y2);
bool in_range(int i, int j, int x1, int y1, int x2, int y2);

int main()
{
	// fast_cin();
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			a[i][j] = {0, 0};

	for (int i = 1; i <= k; ++i)
	{
		scanf("%d", &len[i]);
		xL[i] = yL[i] = N;
		xR[i] = yR[i] = -1;
		for (int j = 1; j <= len[i]; ++j)
		{
			scanf("%d%d%lld", &g[i][j].first, &g[i][j].second, &w[i][j]);

			w[i][j] += w[i][j - 1];
			xL[i] = min(xL[i], g[i][j].first);
			xR[i] = max(xR[i], g[i][j].first);
			yL[i] = min(yL[i], g[i][j].second);
			yR[i] = max(yR[i], g[i][j].second);
			a[g[i][j].first][g[i][j].second] = {i, j};
		}
	}

	int q;
	scanf("%d", &q);
	while (q--)
	{
		char s[20];
		scanf("%s", s);

		if (s[0] == 'S')
		{
			int i;
			scanf("%d", &i);
			off[i] = !off[i];
		}

		else
		{
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

			ll ans = 0;
			vector <pii> events;
			for (int i = 1; i <= k; ++i)
			{
				if (off[i])
					continue;

				if (enclosed(i, x1, y1, x2, y2))
					ans += w[i][len[i]];

				else
				{
					if (in_range(i, 1, x1, y1, x2, y2))
						events.pb({i, 1});

					if (in_range(i, len[i], x1, y1, x2, y2))
						events.pb({i, len[i]});
				}
			}

			for (int j = y1; j <= y2; ++j)
			{
				int incr = max(1, x2 - x1);
				for (int i = x1; i <= x2; i += incr)
				{
					int garland = a[i][j].first, garland_pos = a[i][j].second;
					if (!garland or off[garland])
						continue;

					if (garland_pos != 1 and !in_range(garland, garland_pos - 1, x1, y1, x2, y2))
						events.pb({garland, garland_pos});

					if (garland_pos != len[garland] and !in_range(garland, garland_pos + 1, x1, y1, x2, y2))
						events.pb({garland, garland_pos});
				}
			}

			for (int i = x1 + 1; i < x2; ++i)
			{
				int incr = max(1, y2 - y1);
				for (int j = y1; j <= y2; j += incr)
				{
					int garland = a[i][j].first, garland_pos = a[i][j].second;
					if (!garland or off[garland])
						continue;

					if (garland_pos != 1 and !in_range(garland, garland_pos - 1, x1, y1, x2, y2))
						events.pb({garland, garland_pos});

					if (garland_pos != len[garland] and !in_range(garland, garland_pos + 1, x1, y1, x2, y2))
						events.pb({garland, garland_pos});
				}
			}

			sort(events.begin(), events.end());
			int sz = events.size();
			for (int i = 1; i < sz; i += 2)
			{
				ans += w[events[i].first][events[i].second] - w[events[i - 1].first][events[i - 1].second - 1];
				// cout << events[i - 1].first << ' ' << events[i - 1].second << ' ' << events[i].first << ' ' << events[i].second << " askdfj\n";
			}

			printf("%lld\n", ans);
		}
	}
}

bool enclosed(int i, int x1, int y1, int x2, int y2)
{
	return (xL[i] >= x1 and xR[i] <= x2 and yL[i] >= y1 and yR[i] <= y2);
}

bool in_range(int i, int j, int x1, int y1, int x2, int y2)
{
	int x = g[i][j].first, y = g[i][j].second;
	return (x >= x1 and x <= x2 and y>= y1 and y <= y2);
}