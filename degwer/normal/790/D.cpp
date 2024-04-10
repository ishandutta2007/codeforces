#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
ll d[3][400000];
int nxt[3][400000];
int dp[400000][2];
int x[400000][2];
typedef pair<int, int>pii;
map<pii, int>ans;
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &d[0][i + 1]), d[0][i + 1] += d[0][i];
	for (int i = 0; i < num; i++)scanf("%I64d", &d[1][i + 1]), d[1][i + 1] += d[1][i], d[2][i + 1] = d[0][i + 1] + d[1][i + 1];
	for (int i = 0; i < 3; i++)fill(nxt[i], nxt[i] + num + 1, 1000000000);
	for (int p = 0; p < 3; p++)
	{
		map<ll, int>ma;
		for (int i = num; i >= 0; i--)
		{
			if (ma.count(d[p][i]))nxt[p][i] = ma[d[p][i]];
			ma[d[p][i]] = i;
		}
		for (int i = num - 1; i >= 0; i--)nxt[p][i] = min(nxt[p][i], nxt[p][i + 1]);
		//for (int i = 0; i <= num; i++)printf("%d ", nxt[p][i]); printf("\n");
	}
	for (int i = 0; i < num; i++)
	{
		for (int p = 0; p < 2; p++)
		{
			if (nxt[p][i] != 1000000000)
			{
				int t = nxt[p][i];
				if (dp[t][p] < dp[i][p] + 1)dp[t][p] = dp[i][p] + 1, x[t][p] = x[i][p];
				else if (dp[t][p] == dp[i][p] + 1)x[t][p] = min(x[t][p], x[i][p]);
			}
			if (nxt[1 - p][x[i][p]] != 1000000000 && nxt[1 - p][x[i][p]] >= i)
			{
				int t = nxt[1 - p][x[i][p]];
				if (dp[t][1 - p] < dp[i][p] + 1)dp[t][1 - p] = dp[i][p] + 1, x[t][1 - p] = i;
				else if (dp[t][1 - p] == dp[i][p] + 1)x[t][1 - p] = min(x[t][1 - p], i);
			}
			if (nxt[p][i] != 1000000000 && nxt[p][i] == nxt[1 - p][x[i][p]])
			{
				int t= nxt[p][i];
				if (dp[t][p] < dp[i][p] + 2)dp[t][p] = dp[i][p] + 2, x[t][p] = t;
				if (dp[t][1 - p] < dp[i][p] + 2)dp[t][1 - p] = dp[i][p] + 2, x[t][1 - p] = t;
			}
			int t = nxt[2][i];
			if (t != 1000000000 && dp[t][p] < dp[i][p] + 1)dp[t][p] = dp[i][p] + 1, x[t][p] = t;
			if (t != 1000000000 && dp[t][1 - p] < dp[i][p] + 1)dp[t][1 - p] = dp[i][p] + 1, x[t][1 - p] = t;
		}
		//printf("%d %d  %d %d\n", dp[i + 1][0], x[i+1][0], dp[i + 1][1],x[i+1][1]);
	}
	int maxi = 0;
	for (int i = 0; i <= num; i++)maxi = max(maxi, max(dp[i][0], dp[i][1]));
	printf("%d\n", maxi);
}