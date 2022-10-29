#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double dp[1<<20];
double ans[20];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	vector<double>v;
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		double z;
		scanf("%lf", &z);
		v.push_back(z);
		if (z > (1e-9))cnt++;
	}
	if (cnt <= gen)
	{
		for (int i = 0; i < num; i++)
		{
			if (v[i] > (1e-9))printf("1 ");
			else printf("0 ");
		}
		printf("\n");
		return 0;
	}
	dp[0] = 1.0;
	for (int i = 0; i < (1 << num); i++)
	{
		vector<int>z;
		double sum = 0.0;
		for (int j = 0; j < num; j++)
		{
			if (!(i&(1 << j)))z.push_back(j), sum += v[j];
		}
		if (num - z.size() == gen)
		{
			for (int j = 0; j < num; j++)if (i&(1 << j))ans[j] += dp[i];
		}
		if (sum < (1e-10))sum = 1.0;
		for (int j = 0; j < z.size(); j++)dp[i + (1 << z[j])] += dp[i] * v[z[j]] / sum;
	}
	for (int i = 0; i < num; i++)printf("%.10lf ", ans[i]); printf("\n");
}