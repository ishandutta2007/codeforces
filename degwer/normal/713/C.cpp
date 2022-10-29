#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll dp[3001][3001];
int main()
{
	int num;
	scanf("%d", &num);
	vector<ll>vec;
	vector<ll>zat;
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		z -= i;
		vec.push_back(z);
		zat.push_back(z);
	}
	sort(zat.begin(), zat.end());
	for (int i = 1; i <= 3000; i++)
	{
		for (int j = 0; j <= 3000; j++)
		{
			dp[i][j] = 1000000000000000000LL;
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			dp[i + 1][j] = dp[i][j] + abs(zat[j] - vec[i]);
		}
		for (int j = 1; j < num; j++)
		{
			dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][j - 1]);
		}
	}
	printf("%I64d\n", dp[num][num - 1]);
}