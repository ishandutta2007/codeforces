#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[100000];
vector<int>ko[100000];
bool flag[100000];
int d1[100000],d2[100000];
vector<int>ans;
void dfs(int node, int x1, int x2)
{
	if (flag[node])return;
	flag[node] = true;
	int x = x1^d1[node] ^ d2[node];
	if (x)ans.push_back(node);
	for (int i = 0; i < pat[node].size(); i++)dfs(pat[node][i], x2, x1^x);
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[zb].push_back(za);
		pat[za].push_back(zb);
	}
	for (int i = 0; i < num; i++)scanf("%d", &d1[i]);
	for (int i = 0; i < num; i++)scanf("%d", &d2[i]);
	dfs(0, 0, 0);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i] + 1);
}