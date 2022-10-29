#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[200000];
int col[200000];
int deg[200000];
void dfs(int node, int c1, int c2)
{
	int pt = 1;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (col[pat[node][i]] == 0)
		{
			for (;;)
			{
				if (pt == c1 || pt == c2)pt++;
				else break;
			}
			col[pat[node][i]] = pt;
			dfs(pat[node][i], c2, pt);
			pt++;
		}
	}
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
		pat[za].push_back(zb);
		pat[zb].push_back(za);
		deg[za]++, deg[zb]++;
	}
	int maxi = 0;
	for (int i = 0; i < num; i++)maxi = max(maxi, deg[i] + 1);
	col[0] = 1;
	dfs(0, 1, 1);
	printf("%d\n", maxi);
	for (int i = 0; i < num; i++)printf("%d ", col[i]); printf("\n");
}