#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>ko[300000];
int par[300000];
int dp[300000];
int siz[300000];
void calc(int node)
{
	siz[node] = 1;
	int maxi = 0;
	int rr = -1;
	for (int i = 0; i < ko[node].size(); i++)
	{
		calc(ko[node][i]);
		siz[node] += siz[ko[node][i]];
		if (maxi < siz[ko[node][i]])
		{
			maxi = siz[ko[node][i]];
			rr = i;
		}
	}
	if (maxi <= siz[node] - maxi)
	{
		dp[node] = node;
		return;
	}
	dp[node] = dp[ko[node][rr]];
	for (;;)
	{
		if (siz[dp[node]] >= siz[node] - siz[dp[node]])
		{
			break;
		}
		dp[node] = par[dp[node]];
	}
}
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	for (int i = 1; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		ko[z].push_back(i);
		par[i] = z;
	}
	calc(0);
	for (int i = 0; i < query; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		printf("%d\n", dp[z] + 1);
	}
}