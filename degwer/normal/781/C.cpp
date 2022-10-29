#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[200000];
vector<int>eul;
bool flag[200000];
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	eul.push_back(node);
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			dfs(pat[node][i]);
			eul.push_back(node);
		}
	}
}
int main()
{
	int num, way, kai;
	scanf("%d%d%d", &num, &way, &kai);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	dfs(0);
	for (int i = 0; i < kai; i++)
	{
		vector<int>r;
		int t = (num + num + kai - 1) / kai;
		for (int j = i*t; j < min((i + 1)*t, int(eul.size())); j++)r.push_back(eul[j]);
		if (r.empty())r.push_back(0);
		printf("%d", r.size());
		for (int j = 0; j < r.size(); j++)printf(" %d", r[j] + 1); printf("\n");
	}
}