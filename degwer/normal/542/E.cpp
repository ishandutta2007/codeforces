#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[1000];
int col[1000];
bool isok = true;
vector<int>nr;
void dfs(int node, int c)
{
	if (col[node] != -1 && col[node] != c)
	{
		isok = false;
	}
	if (col[node] != -1)return;
	nr.push_back(node);
	col[node] = c;
	for (int i = 0; i < pat[node].size(); i++)
	{
		dfs(pat[node][i], 1 - c);
	}
}
int dist[1024][1024];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)dist[i][j] = 1000000000;
	for (int i = 0; i < num; i++)dist[i][i] = 0;
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
		dist[za][zb] = dist[zb][za] = 1;
	}
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)for (int k = 0; k < num; k++)dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	fill(col, col + num, -1);
	int ans = 0;
	for (int i = 0; i < num; i++)
	{
		if (col[i] == -1)
		{
			nr.clear();
			dfs(i, 0);
			int maxi = 0;
			for (int j = 0; j < nr.size(); j++)
			{
				for (int k = 0; k < num; k++)
				{
					if (dist[nr[j]][k] != 1000000000)maxi = max(maxi, dist[nr[j]][k]);
				}
			}
			ans += maxi;
		}
	}
	if (!isok)printf("-1\n");
	else printf("%d\n", ans);
}