#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int par[20][100000];
ll x[100000], y[100000];
int dep[100000];
vector<int>ko[100000];
typedef pair<ll, ll>pii;
void dfs(int node, int d)
{
	for (int i = 0; i < ko[node].size(); i++)dfs(ko[node][i], d + 1);
	dep[node] = d;
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d%I64d", &x[i], &y[i]);
	vector<int>vec;
	for (int i = num - 1; i >= 0; i--)
	{
		for (;;)
		{
			if (vec.size() <= 1)break;
			ll xa = x[vec[vec.size() - 2]], xb = x[vec[vec.size() - 1]];
			ll ya = y[vec[vec.size() - 2]], yb = y[vec[vec.size() - 1]];
			if ((xa - xb)*(yb - y[i]) < (ya - yb)*(xb - x[i]))vec.pop_back();
			else break;
		}
		if (vec.size() >= 1)par[0][i] = vec[vec.size() - 1], ko[vec[vec.size() - 1]].push_back(i);
		vec.push_back(i);
	}
	par[0][num - 1] = num - 1;
	dfs(num - 1, 0);
	for (int i = 1; i <= 19; i++)for (int j = 0; j < num; j++)par[i][j] = par[i - 1][par[i - 1][j]];
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		if (dep[za] > dep[zb])swap(za, zb);
		for (int i = 19; i >= 0; i--)
		{
			if (dep[zb] - (1 << i) >= dep[za])zb = par[i][zb];
		}
		if (za == zb)
		{
			printf("%d\n", za + 1);
			continue;
		}
		for (int i = 19; i >= 0; i--)
		{
			if (par[i][za] != par[i][zb])za = par[i][za], zb = par[i][zb];
		}
		printf("%d\n", par[0][za] + 1);
	}
}