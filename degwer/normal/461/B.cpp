#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>ko[100000];
typedef long long ll;
ll mod = 1000000007;
ll dp[100000][2];
int dat[100000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 1; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		ko[z].push_back(i);
	}
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]);
	for (int i = num - 1; i >= 0; i--)
	{
		dp[i][dat[i]] = 1;
		for (int j = 0; j < ko[i].size(); j++)
		{
			ll t0 = 0, t1 = 0;
			t0 += dp[i][0] * dp[ko[i][j]][0];
			t1 += dp[i][0] * dp[ko[i][j]][1] + dp[i][1] * dp[ko[i][j]][0];
			t0 += dp[i][0] * dp[ko[i][j]][1];
			t1 += dp[i][1] * dp[ko[i][j]][1];
			dp[i][0] = t0%mod;
			dp[i][1] = t1%mod;
		}
	}
	printf("%I64d\n", dp[0][1]);
}