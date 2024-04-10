#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double dp[2][5001];
double pr[5000];
int len[5000];
double jp[5001];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num; i++)
	{
		scanf("%lf%d", &pr[i], &len[i]);
		pr[i] /= 100.0;
	}
	dp[0][0] = 1.0;
	int cur = 0;
	double ans = 0.0;
	for (int i = 0; i < num; i++)
	{
		jp[0] = 1.0;
		for (int j = 1; j <= gen; j++)
		{
			if (jp[j - 1] < (1e-12))jp[j - 1] = 0;
			jp[j] = jp[j - 1] * (1.0 - pr[i]);
		}
		double now = 0.0;
		double t = jp[len[i] - 1];
		double s = 1.0 - pr[i];
		double r = t*s;
		if (t < (1e-12))t = 0;
		if (s < (1e-12))s = 0;
		if (r < (1e-12))r = 0;
		int f = 0;
		if (len[i] >= 2)
		{
			for (int j = i; j <= gen; j++)
			{
				if (now < (1e-12))now = 0;
				dp[1 - cur][j] = now;
				if (j - len[i] >= i)now -= t * dp[cur][j - len[i]];
				now *= s;
				if (j - len[i] + 1 >= i)now += r*dp[cur][j - len[i] + 1];
				now += dp[cur][j] * pr[i];
			}
		}
		else
		{
			for (int j = i; j <= gen; j++)
			{
				dp[1 - cur][j] = dp[cur][j - 1];
			}
		}
		for (int j = i; j <= gen; j++)dp[cur][j] = 0;
		cur = 1 - cur;
		for (int j = i; j <= gen; j++)
		{
			if (dp[cur][j] < (1e-12))dp[cur][j] = 0;
			ans += dp[cur][j];
		}
	}
	printf("%.10lf\n", ans);
}