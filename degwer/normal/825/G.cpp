#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[1000000];
int r[1000000];
bool flag[1000000];
void dfs(int node, int d)
{
	if (flag[node])return;
	flag[node] = true;
	r[node] = d;
	for (int i = 0; i < pat[node].size(); i++)dfs(pat[node][i], min(d, pat[node][i]));
}
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	int za, zb;
	scanf("%d%d", &za, &zb);
	zb = zb%num;
	dfs(zb, zb);
	int las = 0, now = zb;
	for (int i = 1; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		zb = (zb + las) % num;
		if (za == 1)now = min(now, r[zb]);
		else
		{
			printf("%d\n", min(now, r[zb]) + 1);
			las = min(now, r[zb]) + 1;
		}
	}
}