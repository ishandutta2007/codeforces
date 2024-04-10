#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int dp[2001];
int num, gen;
int ab[2000][2000];
typedef long long ll;
bool solve(vector<int>v, int med)
{
	for (int i = 0; i < num; i++)dp[i] = i;
	int mt[2000];
	for (ll i = 0; i < num; i++)mt[i] = min((ll)med*i, 2100000000LL);
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (ab[i][j] <= mt[j - i])
			{
				dp[j] = min(dp[j], dp[i] + (j - i - 1));
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (dp[i] + (num - i - 1) <= gen)return true;
	}
	return false;
}
int main()
{
	scanf("%d%d", &num, &gen);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)ab[i][j] = abs(v[i] - v[j]);
	ll beg = 0, end = 2000000000LL;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end) / 2;
		if (solve(v, med))end = med;
		else beg = med + 1;
	}
	printf("%d\n", beg);
}