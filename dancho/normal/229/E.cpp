#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<int> pr[1024];
vector<int> all;
int must_take[1024];
int fs[1024];
int fr;
int fcnt;
double all_pos;

double com[1024][1024];

double gc(int n, int k)
{
	if (n < k)
		return 0.0;
	if (k == 0)
		return 1.0;
	if (k < 0)
		return 0.0;
	if (com[n][k] == com[n][k])
		return com[n][k];
	com[n][k] = gc(n - 1, k) + gc(n - 1, k - 1);
	return com[n][k];
}

double dp[1024][1024];

double getDP(int lf, int p)
{
	//~ printf("DP %d %d _ %d\n", lf, p, m);
	if (p >= m)
	{
		if (lf == 0)
			return 1.0;
		return 0.0;
	}
	if (dp[lf][p] == dp[lf][p])
		return dp[lf][p];
	double sol = 0.0;
	for (int i = 0; i <= min(fs[p], lf); ++i)
	{
		sol += getDP(lf - i, p + 1) / gc(pr[p].size(), must_take[p] + i);
	}
	return (dp[lf][p] = sol);
}

int main()
{
	memset(com, -1, sizeof(com));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j)
		{
			int l;
			scanf("%d", &l);
			pr[i].push_back(l);
			all.push_back(l);
		}
		sort(pr[i].begin(), pr[i].end());
	}
	
	sort(all.begin(), all.end());
	fr = all[(int) all.size() - n];
	fcnt = 0;
	for (int i = (int) all.size() - n; i < (int) all.size(); ++i)
	{
		++fcnt;
		if (i + 1 < (int) all.size() && all[i + 1] != all[i])
		{
			break;
		}
	}
	
	// Take all > fr. From those = fr, pick fcnt arbitrarily.
	int ef = 0;
	for (int i = 0; i < (int) all.size(); i++)
	{
		if (all[i] == fr)
			++ef;
	}
	
	memset(dp, -1, sizeof(dp));
	all_pos = gc(ef, fcnt);
	//~ printf("%d %d %lf\n", fr, fcnt, all_pos);
	for (int i = 0; i < m; ++i)
	{
		must_take[i] = 0;
		fs[i] = 0;
		for (int j = 0; j < (int) pr[i].size(); ++j)
		{
			if (pr[i][j] > fr)
				must_take[i]++;
			if (pr[i][j] == fr)
				fs[i]++;
		}
		//~ printf("I %d %d\n", must_take[i], fs[i]);
	}
	printf("%.12lf\n", getDP(fcnt, 0) / all_pos);
	return 0;
}