#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[100000];
bool flag[100000];
int col[100000];
bool isok = true;
void dfs(int node, int c)
{
	if (flag[node])
	{
		if (col[node] != c)isok = false;
		return;
	}
	flag[node] = true;
	col[node] = c;
	for (int i = 0; i < pat[node].size(); i++)
	{
		dfs(pat[node][i], -c);
	}
}
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag, flag + num, false);
	for (int i = 0; i < num; i++)if (!flag[i])dfs(i, 1);
	if (!isok)printf("-1\n");
	else
	{
		vector<int>a1, a2;
		for (int i = 0; i < num; i++)
		{
			if (col[i] == 1)a1.push_back(i + 1);
			else a2.push_back(i + 1);
		}
		printf("%d\n", a1.size());
		for (int i = 0; i < a1.size(); i++)
		{
			if (i != 0)printf(" ");
			printf("%d", a1[i]);
		}
		printf("\n");
		printf("%d\n", a2.size());
		for (int i = 0; i < a2.size(); i++)
		{
			if (i != 0)printf(" ");
			printf("%d", a2[i]);
		}
		printf("\n");
	}
}