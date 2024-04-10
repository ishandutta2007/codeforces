#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[1024][1024];
int dp[1024][1024];
int xdp[1024][1024];
typedef pair<int, int>pii;
typedef pair<pii, pii>pi4;
vector<pi4>dat[1024];
int ans[1048576];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			scanf("%d", &map[i + 1][j + 1]);
		}
	}
	for (int i = 1; i <= mx; i++)
	{
		for (int j = 1; j <= my; j++)
		{
			if (map[i][j] == 1)
			{
				int t = min(dp[i - 1][j], dp[i][j - 1]);
				if (map[i - t][j - t] == 1)dp[i][j] = t + 1;
				else dp[i][j] = t;
			}
			xdp[i][j] = max(xdp[i - 1][j], dp[i][j]);
		}
	}
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zb, &zc, &zd);
		dat[za].push_back(make_pair(make_pair(p, zb), make_pair(zc, zd)));
	}
	for (int i = 1; i <= mx; i++)
	{
		for (int j = 0; j < dat[i].size(); j++)
		{
			int yl = dat[i][j].first.second, yu = dat[i][j].second.second, xu = dat[i][j].second.first;
			int maxi = 0;
			int t = yl - 1;
			for (int k = yl; k <= yu; k++)
			{
				maxi = max(maxi, min(k - t, xdp[xu][k]));
			}
			ans[dat[i][j].first.first] = maxi;
		}
		for (int j = 1; j <= my; j++)xdp[i][j] = 0;
		for (int j = i + 1; j <= mx; j++)
		{
			int d = j - i;
			int s = j - 1;
			for (int k = 1; k <= my; k++)
			{
				xdp[j][k] = max(xdp[s][k], min(dp[j][k], d));
			}
		}
	}
	for (int i = 0; i < query; i++)printf("%d\n", ans[i]);
}