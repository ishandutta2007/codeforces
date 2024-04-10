#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
vector<pii>pat[2000];
ll d1[2000], d2[2000];
bool flag[2000];
ll dat[2000];
ll pnt[2000][2000];
ll p2[2000][2000];
ll rui[2001][2001];
ll r2[2001][2001];
ll dp[2001][2001][2];
int num, way;
ll dfs(int na, int nb, int t)
{
	if (r2[num][num] - r2[na][num] - r2[num][nb] + r2[na][nb] == 0)return 0;
	if (dp[na][nb][t] != -1000000000000000000LL)return dp[na][nb][t];
	ll maxi = -1000000000000000000LL;
	ll ret;
	if (t == 0)
	{
		int beg = na + 1, end = num;
		for (;;)
		{
			if (beg == end)break;
			int med = (beg + end) / 2;
			if (r2[med][num] - r2[na][num] - r2[med][nb] + r2[na][nb] > 0)end = med;
			else beg = med + 1;
		}
		ll g = rui[beg][num] - rui[na][num] - rui[beg][nb] + rui[na][nb];
		ret = dp[na][nb][t] = max(dfs(beg, nb, t) + g, rui[num][num] - rui[beg][num] - rui[num][nb] + rui[beg][nb] - dfs(beg, nb, 1 - t) + g);
	}
	else
	{
		int beg = nb + 1, end = num;
		for (;;)
		{
			if (beg == end)break;
			int med = (beg + end) / 2;
			if (r2[num][med] - r2[num][nb] - r2[na][med] + r2[na][nb] > 0)end = med;
			else beg = med + 1;
		}
		ll g = rui[num][beg] - rui[num][nb] - rui[na][beg] + rui[na][nb];
		ret = dp[na][nb][t] = max(dfs(na, beg, t) + g, rui[num][num] - rui[num][beg] - rui[na][num] + rui[na][beg] - dfs(na, beg, 1 - t) + g);
	}
	return ret;
}
int main()
{
	scanf("%d%d", &num, &way);
	int s1, s2;
	scanf("%d%d", &s1, &s2);
	s1--;
	s2--;
	for (int i = 0; i < num; i++)scanf("%I64d", &dat[i]);
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--;
		zb--;
		pat[za].push_back(make_pair(zb, zc));
		pat[zb].push_back(make_pair(za, zc));
	}
	fill(flag, flag + num, false);
	fill(d1, d1 + num, 1000000000000000000LL);
	fill(d2, d2 + num, 1000000000000000000LL);
	priority_queue<pii>que;
	que.push(make_pair(0, s1));
	for (;;)
	{
		if (que.empty())break;
		pii z = que.top();
		que.pop();
		if (flag[z.second])continue;
		flag[z.second] = true;
		d1[z.second] = -z.first;
		for (int i = 0; i < pat[z.second].size(); i++)
		{
			if (d1[pat[z.second][i].first]>d1[z.second] + pat[z.second][i].second)
			{
				d1[pat[z.second][i].first] = d1[z.second] + pat[z.second][i].second;
				que.push(make_pair(-d1[pat[z.second][i].first], pat[z.second][i].first));
			}
		}
	}
	fill(flag, flag + num, false);
	que.push(make_pair(0, s2));
	for (;;)
	{
		if (que.empty())break;
		pii z = que.top();
		que.pop();
		if (flag[z.second])continue;
		flag[z.second] = true;
		d2[z.second] = -z.first;
		for (int i = 0; i < pat[z.second].size(); i++)
		{
			if (d2[pat[z.second][i].first]>d2[z.second] + pat[z.second][i].second)
			{
				d2[pat[z.second][i].first] = d2[z.second] + pat[z.second][i].second;
				que.push(make_pair(-d2[pat[z.second][i].first], pat[z.second][i].first));
			}
		}
	}
	vector<ll>vx, vy;
	for (int i = 0; i < num; i++)
	{
		vx.push_back(d1[i]);
		vy.push_back(d2[i]);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	for (int i = 0; i < num; i++)
	{
		int lx = lower_bound(vx.begin(), vx.end(), d1[i]) - vx.begin();
		int ly = lower_bound(vy.begin(), vy.end(), d2[i]) - vy.begin();
		pnt[lx][ly] += dat[i];
		p2[lx][ly]++;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			rui[i + 1][j + 1] = rui[i + 1][j] + rui[i][j + 1] - rui[i][j] + pnt[i][j];
			r2[i + 1][j + 1] = r2[i + 1][j] + r2[i][j + 1] - r2[i][j] + p2[i][j];
		}
	}
	for (int i = 0; i <= num; i++)for (int j = 0; j <= num; j++)for (int k = 0; k < 2; k++)dp[i][j][k] = -1000000000000000000LL;
	ll r = dfs(0, 0, 0);
	if (r < rui[num][num] - r)printf("Cry\n");
	else if (r == rui[num][num] - r)printf("Flowers\n");
	else printf("Break a heart\n");
}