#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long double ld;
ld dp[2][1111];
ld eps = 1e-11;
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	dp[0][0] = 1.0;
	int cur = 0;
	vector<ld>ans;
	for (int i = 0;; i++)
	{
		ans.push_back(dp[cur][num]);
		if (ans[i] > 0.501)break;
		for (int j = 0; j <= num; j++)
		{
			dp[1 - cur][j] += dp[cur][j] * (ld)j / (ld)num;
			dp[1 - cur][j + 1] += dp[cur][j] * (ld)(num - j) / (ld)num;
		}
		for (int j = 0; j <= num + 3; j++)dp[cur][j] = 0.0;
		cur = 1 - cur;
	}
	for (int i = 0; i < query; i++)
	{
		int x;
		scanf("%d", &x);
		int low = lower_bound(ans.begin(), ans.end(), (ld)x / (ld)2000 - eps) - ans.begin();
		printf("%d\n", low);
	}
}