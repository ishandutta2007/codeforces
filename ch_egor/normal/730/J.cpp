/*






le
toucan
has
arrived*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[107], b[107], bb[107];
int dp[2][107][10007];
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		total += a[i];
	}
	int go2 = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		go2 += b[i];
		bb[i] = b[i];
	}
	sort(bb + 1, bb + 1 + n);
	int kk = 0, tmp = total;
	for (int i = n; i >= 1; i--)
	{
		if (tmp > 0)
		{
			kk++;
			tmp -= bb[i];
		}
	}
	printf("%d\n", kk);
	int cur = 0, next = 1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 107; j++)
		{
			for (int k = 0; k < 10007; k++)
			{
				dp[i][j][k] = -(int)1e9;
			}
		}
	}
	dp[cur][0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 107; j++)
		{
			for (int k = 0; k < 10007; k++)
			{
				dp[next][j][k] = -(int)1e9;
			}
		}
		for (int j = 0; j <= kk; j++)
		{
			for (int k = 0; k <= go2; k++)
			{
				if (dp[cur][j][k] >= 0)
				{
					//cerr << i << " " << j << " " << k << endl;
					dp[next][j][k] = max(dp[next][j][k], dp[cur][j][k]);
					dp[next][j + 1][k + b[i + 1]] = max(dp[next][j + 1][k + b[i + 1]], dp[cur][j][k] + a[i + 1]);
				}
			}
		}
		swap(next, cur);
	}
	int res = 0;
	for (int j = total; j <= go2; j++)
	{
	//	cerr << kk << " " << j << " " << dp[cur][kk][j] << endl;
		res = max(res, dp[cur][kk][j]);
	}
	printf("%d\n", total - res);
	
}