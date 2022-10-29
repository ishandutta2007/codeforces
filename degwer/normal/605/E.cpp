#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[1000][1000];
double dist[1000];
bool flag[1000];
double stp[1000];
double sum[1000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &dat[i][j]);
		}
	}
	fill(dist, dist + 1000, 1000000000000000000000000.0);
	dist[num - 1] = 0.0;
	fill(flag, flag + num, false);
	fill(stp, stp + 1000, 1.0);
	fill(sum, sum + 1000, 0.0);
	for (;;)
	{
		double mini = 1000000000000000000000000000.0;
		int rr = -1;
		for (int i = 0; i < num; i++)
		{
			if ((!flag[i]) && mini>dist[i])
			{
				mini = dist[i];
				rr = i;
			}
		}
		flag[rr] = true;
		if (rr == 0)
		{
			printf("%lf\n", dist[0]);
			return 0;
		}
		for (int i = 0; i < num; i++)
		{
			sum[i] += stp[i] * (double(dat[i][rr]) / 100.0)*dist[rr];
			stp[i] *= ((100.0 - double(dat[i][rr])) / 100.0);
			dist[i] = (sum[i] + 1.0) / (1.0 - stp[i]);
		}
	}
}