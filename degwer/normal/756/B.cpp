#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[200000];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>vec;
	dp[0] = 0;
	vec.push_back(-10000);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		int u1 = upper_bound(vec.begin(), vec.end(), z - 90) - vec.begin() - 1;
		int u2 = upper_bound(vec.begin(), vec.end(), z - 1440) - vec.begin() - 1;
		dp[i + 1] = min(dp[i] + 20, min(dp[u1] + 50, dp[u2] + 120));
		printf("%d\n", dp[i + 1] - dp[i]);
		vec.push_back(z);
	}
}