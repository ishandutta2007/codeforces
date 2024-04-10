#include <bits/stdc++.h>

using namespace std;

const int MAXK = 8, MAXN = 100005;

vector<int> dp(1 << MAXK), cur(MAXK, -1);
vector<vector<int>> lft(2 * MAXN), rht(2 * MAXN);
vector<int> comp;
vector<pair<int, int>> spell(MAXN);

int main()
{
	int n, m, k;
	scanf("%i%i%i", &n, &m, &k);
	for(int x = 0; x < n; x++)
	{
		int l, r;
		scanf("%i%i", &l, &r);
		comp.push_back(l);
		comp.push_back(++r);
		spell[x] = {l, r};

	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int x = 0; x < n; x++)
	{
		int l = spell[x].first, r = spell[x].second;
		l = lower_bound(comp.begin(), comp.end(), l) - comp.begin();
		r = lower_bound(comp.begin(), comp.end(), r) - comp.begin();
		lft[l].push_back(x);
		rht[r].push_back(x);
	}
	for(int x = comp.size() - 1; x > 0; x--)
		comp[x] -= comp[x - 1];
	comp[0] = 0;
	for(int x = 0; x < comp.size() - 1; x++)
	{
		int rm = 0;
		for(auto &y : rht[x])
		{
			for(int z = 0; z < MAXK; z++)
			{
				if(cur[z] == y)
				{
					cur[z] = -1;
					rm |= 1 << z;
					for(int ab = 0; ab < 1 << MAXK - z - 1; ab++)
					{
						for(int aa = 0; aa < 1 << z; aa++)
						{
							int ac = ab << z + 1 ^ aa, ad = ac ^ 1 << z;
							dp[ac] = dp[ad] = max(dp[ac], dp[ad]);
						}
					}
					break;
				}
			}
		}
		for(auto &y : lft[x])
		{
			for(int z = 0; z < MAXK; z++)
			{
				if(cur[z] == -1)
				{
					cur[z] = y;
					break;
				}
			}
		}
		int ad = 0;
		for(int y = 0; y < MAXK; y++)
			if(cur[y] != -1)
				ad |= 1 << y;
		for(int y = (1 << MAXK) - 1; y >= 0; y--)
			dp[y] = dp[y] + (__builtin_popcount(y & ad) & 1) * comp[x + 1];
	}
	int ans = 0;
	for(int x = 0; x < 1 << MAXK; x++)
		ans = max(ans, dp[x]);
	printf("%i\n", ans);
}