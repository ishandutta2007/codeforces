#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double dp[500010][51];
int par[500010];
int main()
{
	int pt = 1;
	dp[0][0] = 1.0;
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		if (za == 1)
		{
			zb--;
			par[pt] = zb;
			dp[pt][0] = 1.0;
			double t = 1.0;
			double bef = 0.0;
			int now = zb;
			for (int i = 1; i <= 50; i++)
			{
				t *= 0.5;
				t *= (1.0 - dp[now][i]) / (1.0 - bef / 2.0);
				bef = dp[now][i];
				dp[now][i] += t;
				if (now == 0)break;
				now = par[now];
			}
			pt++;
		}
		else
		{
			double ans = 0.0;
			zb--;
			for (int i = 0; i <= 49; i++)
			{
				ans += (dp[zb][i] - dp[zb][i + 1])*double(i);
			}
			printf("%.20lf\n", ans);
		}
		/*for (int i = 0; i < pt; i++) {
			for (int j = 0; j < 5; j++)printf("%lf\n", dp[i][j]); printf("\n");
		}*/
	}
}