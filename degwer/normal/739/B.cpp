#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
vector<pii>ko[200000];
int par[20][200000];
ll cst[20][200000];
ll d[200000];
int ans[200000];
void dfs(int node)
{
	for (int i = 0; i < ko[node].size(); i++)dfs(ko[node][i].first), ans[node] += ans[ko[node][i].first];
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &d[i]);
	for (int i = 1; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		ko[za].push_back(make_pair(i, zb));
		par[0][i] = za, cst[0][i] = zb;
	}
	for (int j = 1; j < 20; j++)
	{
		for (int i = 0; i < num; i++)
		{
			par[j][i] = par[j - 1][par[j - 1][i]];
			cst[j][i] = cst[j - 1][i] + cst[j - 1][par[j - 1][i]];
		}
	}
	for (int i = 0; i < num;i++)
	{
		int t = i;
		ll c = d[i];
		for (int j = 19; j >= 0; j--)if (c >= cst[j][t])c -= cst[j][t], t = par[j][t];
		ans[i]++;
		if (t != 0)ans[par[0][t]]--;
	}
	dfs(0);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", ans[i] - 1);
	}
	printf("\n");
}