#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod;
ll dp[501][501];
int main()
{
	int num, sum, gen;
	scanf("%d%d%d%I64d", &num, &sum, &gen, &mod);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	dp[0][0] = 1;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			for (int k = 0; k <= gen; k++)
			{
				if (j + 1 <= sum&&k + v[i] <= gen)
				{
					dp[j + 1][k + v[i]] += dp[j][k];
					dp[j + 1][k + v[i]] %= mod;
				}
			}
		}
	}
	ll s = 0;
	for (int i = 0; i <= gen; i++)s += dp[sum][i];
	printf("%I64d\n", s%mod);
}