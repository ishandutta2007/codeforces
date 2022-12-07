#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 112345;
vector<int> p[3];
void solve()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 0; i < 3; i++)
		p[i].clear();
	for (int i = 0; i < a; i++)
	{
		int x;
		scanf("%d", &x);
		p[0].push_back(x);
	}
	for (int i = 0; i < b; i++)
	{
		int x;
		scanf("%d", &x);
		p[1].push_back(x);
	}
	for (int i = 0; i < c; i++)
	{
		int x;
		scanf("%d", &x);
		p[2].push_back(x);
	}
	for (int i = 0; i < 3; i++)
		sort(p[i].begin(), p[i].end());
	i64 ans = 1ll << 62;
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			for (int z = 0; z < 3; z++)
				if (x != y && y != z && x != z)
				{
					for (auto u : p[x])
					{
						auto itv = lower_bound(p[y].begin(), p[y].end(), u);
						if (itv == p[y].end())
							continue;
						auto itw = lower_bound(p[z].begin(), p[z].end(), (*itv + u + 1) / 2);
						auto sqr = [&](i64 x) { return x * x; };
						if (itw != p[z].end())
						{
							ans = min(ans, sqr(u - *itv) + sqr(u - *itw) + sqr(*itv - *itw));
						}
						if (itw != p[z].begin())
						{
							--itw;
							ans = min(ans, sqr(u - *itv) + sqr(u - *itw) + sqr(*itv - *itw));
						}
					}
				}
	printf("%lld\n", ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++)
	{
		solve();
	}
}