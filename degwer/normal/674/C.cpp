#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double dp[51][200001];
double arr[200000];
double rui[200001];
double invrui[200001];
typedef pair<double, double>pdd;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	double sum = 0.0;
	for (int i = 0; i < num; i++)
	{
		double z;
		scanf("%lf", &z);
		arr[i] = z;
		rui[i + 1] = rui[i] + z;
		invrui[i + 1] = invrui[i] + 1.0 / z;
		sum += rui[i + 1] / z;
	}
	dp[1][0] = 0;
	for (int i = 1; i < gen; i++)
	{
		vector<pdd>vec;
		vector<pdd>lin;
		lin.push_back(make_pair(0, 0));
		for (int j = 0; j < num; j++)
		{
			double kt = rui[j + 1], se = dp[i][j] - rui[j + 1] * invrui[j + 1];
			for (;;)
			{
				if (vec.empty())break;
				if (vec[vec.size() - 1].first*kt + se>vec[vec.size() - 1].second)
				{
					vec.pop_back();
					lin.pop_back();
				}
				else break;
			}
			double x = (lin[lin.size() - 1].second - se) / (kt - lin[lin.size() - 1].first);
			vec.push_back(make_pair(x, x*kt + se));
			lin.push_back(make_pair(kt, se));
			int low = lower_bound(vec.begin(), vec.end(), make_pair(invrui[j + 1], 0.0)) - vec.begin();
			dp[i + 1][j] = lin[low].first*invrui[j + 1] + lin[low].second;
		}
	}
	printf("%lf\n", sum - dp[gen][num - 1]);
}