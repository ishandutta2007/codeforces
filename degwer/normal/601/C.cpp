#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long double ld;
ld dp[2][100005];
ld rui[2][100005];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	if (gen == 1)
	{
		printf("1\n");
		return 0;
	}
	vector<int>vec;
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
		sum += z;
	}
	dp[0][0] = 1.0;
	rui[0][0] = 0.0;
	for (int i = 1; i <= 100004; i++)rui[0][i] = 1.0;
	int cur = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= 100004; j++)
		{
			dp[1 - cur][j] = (rui[cur][j] - rui[cur][max(0, j - gen)] - dp[cur][j - vec[i]]) / ld(gen - 1);
		}
		for (int j = 0; j <= 100004; j++)
		{
			dp[cur][j] = rui[cur][j] = 0.0;
		}
		for (int j = 1; j <= 100004; j++)
		{
			rui[1 - cur][j] = rui[1 - cur][j - 1] + dp[1 - cur][j - 1];
		}
		cur = 1 - cur;
	}
	ld ans = 1.0;
	for (int i = 0; i < sum; i++)ans += dp[cur][i] * ld(gen - 1);
	//for (int i = 0; i < 20; i++)printf("%d %Lf\n", i, dp[cur][i]);
	printf("%.20lf\n", double(ans));
}