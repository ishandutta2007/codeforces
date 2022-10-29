#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1000010];
int m1[1000010];
int m2[1000010];
int r1[1000010];
int r2[1000010];
int par[1000010];
int main()
{
	int num;
	scanf("%d", &num);
	fill(r1, r1 + 1000010, -1);
	fill(r2, r2 + 1000010, -2);
	int maxi = 0;
	for (int i = 1; i <= num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		par[i] = z;
		dp[i] = 1;
		int now = i;
		for (;;)
		{
			if (par[now] == 0)
			{
				maxi = max(maxi, max(m1[now], m2[now] + 1));
				break;
			}
			if (m1[par[now]] < dp[now])
			{
				if (r1[par[now]] != now)
				{
					m2[par[now]] = m1[par[now]];
					r2[par[now]] = r1[par[now]];
					m1[par[now]] = dp[now];
					r1[par[now]] = now;
				}
				else
				{
					m1[par[now]] = dp[now];
				}
			}
			else if (m2[par[now]] < dp[now] && r1[par[now]] != now)
			{
				if (r2[par[now]] != now)
				{
					m2[par[now]] = dp[now];
					r2[par[now]] = now;
				}
				else
				{
					m2[par[now]] = dp[now];
				}
			}
			else break;
			now = par[now];
			dp[now] = max(m1[now], m2[now] + 1);
		}
		printf("%d ", maxi);
	}
	printf("\n");
}