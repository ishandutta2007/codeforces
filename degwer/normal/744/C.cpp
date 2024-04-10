#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<int, pii>pi3;
ll dp[1 << 16][257];
ll INF = 1000000000000LL;
int main()
{
	int num;
	scanf("%d", &num);
	vector<pi3>vec;
	ll sum = 0;
	for (int i = 0; i < num; i++)
	{
		char za;
		int zb, zc;
		scanf(" %c%d%d", &za, &zb, &zc);
		if (zb > 16)
		{
			sum += zb - 16;
			zb = 16;
		}
		vec.push_back(make_pair((za == 'R'), make_pair(zb, zc)));
	}
	for (int i = 0; i < (1 << num); i++)for (int j = 0; j <= 256; j++)dp[i][j] = INF;
	dp[0][0] = 0;
	for (int p = 0; p < (1 << num); p++)
	{
		int cb = 0, cr = 0;
		for (int i = 0; i < num; i++)
		{
			if (p&(1 << i))
			{
				if (vec[i].first == 0)cb++;
				else cr++;
			}
		}
		for (int k = 0; k < num; k++)
		{
			if ((p&(1 << k)) == 0)
			{
				for (int i = 0; i <= 256; i++)
				{
					if (dp[p][i] == INF)continue;
					ll t = i + max(0LL, vec[k].second.first - cr);
					if (t <= 256)dp[p | (1 << k)][t] = min(dp[p | (1 << k)][t], dp[p][i] + max(0LL, vec[k].second.second - cb));
				}
			}
		}
	}
	ll mini = INF;
	for (int i = 0; i <= 256; i++)
	{
		mini = min(mini, max(sum + i, dp[(1 << num) - 1][i]));
	}
	printf("%I64d\n", mini + num);
}