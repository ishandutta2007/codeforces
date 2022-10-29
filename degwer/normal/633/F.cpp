#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[100000];
vector<int>ko[100000];
typedef long long ll;
ll dat[100000];
ll dp[100000][3];
bool flag[100000];
ll maxi = 0;
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
		}
	}
}
void calc(int node)
{
	for (int i = 0; i < ko[node].size(); i++)calc(ko[node][i]);
	ll mx[3][3];
	int rr[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mx[i][j] = 0;
			rr[i][j] = -i * 3 - j;
		}
	}
	for (int i = 0; i < ko[node].size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (mx[j][0] < dp[ko[node][i]][j])
			{
				mx[j][2] = mx[j][1];
				mx[j][1] = mx[j][0];
				mx[j][0] = dp[ko[node][i]][j];
				rr[j][2] = rr[j][1];
				rr[j][1] = rr[j][0];
				rr[j][0] = i;
			}
			else if (mx[j][1] < dp[ko[node][i]][j])
			{
				mx[j][2] = mx[j][1];
				mx[j][1] = dp[ko[node][i]][j];
				rr[j][2] = rr[j][1];
				rr[j][1] = i;
			}
			else if (mx[j][2] < dp[ko[node][i]][j])
			{
				mx[j][2] = dp[ko[node][i]][j];
				rr[j][2] = i;
			}
		}
	}
	dp[node][0] = mx[0][0] + dat[node];
	dp[node][1] = max(mx[1][0], mx[0][0] + mx[0][1] + dat[node]);
	dp[node][2] = mx[2][0] + dat[node];
	if (rr[0][0] != rr[1][0])dp[node][2] = max(dp[node][2], mx[0][0] + mx[1][0] + dat[node]);
	else dp[node][2] = max(dp[node][2], max(mx[0][0] + mx[1][1], mx[0][1] + mx[1][0]) + dat[node]);
	maxi = max(maxi, mx[0][0] + mx[0][1] + mx[0][2] + dat[node]);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (rr[0][(i + 1) % 3] != rr[1][j] && rr[0][i] != rr[1][j])
			{
				maxi = max(maxi, mx[0][i] + mx[0][(i + 1) % 3] + mx[1][j] + dat[node]);
			}
		}
	}
	maxi = max(maxi, mx[1][0] + mx[1][1]);
	if (rr[0][0] != rr[2][0])maxi = max(maxi, mx[0][0] + mx[2][0] + dat[node]);
	else maxi = max(maxi, max(mx[0][0] + mx[2][1], mx[0][1] + mx[2][0]) + dat[node]);
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &dat[i]);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag, flag + num, false);
	dfs(0);
	calc(0);
	printf("%I64d\n", maxi);
}