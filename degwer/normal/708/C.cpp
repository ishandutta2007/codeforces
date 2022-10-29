#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[400000];
vector<int>ko[400000];
int siz[400000];
bool flag[400000];
int cent;
int num;
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	siz[node] = 1;
	int maxi = 0;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			dfs(pat[node][i]);
			siz[node] += siz[pat[node][i]];
			maxi = max(maxi, siz[pat[node][i]]);
		}
	}
	if (maxi <= num / 2 && num - siz[node] <= num / 2)cent = node;
}
void dfs2(int node)
{
	if (flag[node])return;
	flag[node] = true;
	siz[node] = 1;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			dfs2(pat[node][i]);
			ko[node].push_back(pat[node][i]);
			siz[node] += siz[pat[node][i]];
		}
	}
}
int ans[400000];
void calc(int node, int m1, int m2,int up)
{
	//printf("%d %d %d %d\n", node + 1, m1, m2, up);
	if (num - m1 <= num / 2)ans[node] = 1;
	if (num - m2 - (m1 - up) <= num / 2)ans[node] = 1;
	for (int i = 0; i < ko[node].size(); i++)
	{
		calc(ko[node][i], m1, m2, up + siz[node] - siz[ko[node][i]]);
	}
}
int main()
{
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag, flag + num, false);
	dfs(0);
	fill(flag, flag + num, false);
	dfs2(cent);
	int m1 = 0, m2 = 0, r1 = -1, r2 = -2;
	for (int i = 0; i < ko[cent].size(); i++)
	{
		if (m1 < siz[ko[cent][i]])
		{
			m2 = m1;
			m1 = siz[ko[cent][i]];
			r2 = r1;
			r1 = i;
		}
		else if (m2 < siz[ko[cent][i]])
		{
			m2 = siz[ko[cent][i]];
			r2 = i;
		}
		//printf("%d %d %d\n", ko[cent][i] + 1, m1, m2);
	}
	for (int i = 0; i < ko[cent].size(); i++)
	{
		if (r1 != i)calc(ko[cent][i], siz[ko[cent][i]], m1, 0);
		else calc(ko[cent][i], siz[ko[cent][i]], m2, 0);
	}
	ans[cent] = 1;
	for (int i = 0; i < num; i++)printf("%d ", ans[i]); printf("\n");
}