#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 300000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
			ren[i] = 0;
		}
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else return par[a] = find(par[a]);
	}
	int merge(int a, int b)
	{
		return max(max(a, b), (a + 1) / 2 + (b + 1) / 2 + 1);
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			par[b] = a;
			ren[a] = merge(ren[a], ren[b]);
		}
		else
		{
			par[a] = b;
			ren[b] = merge(ren[a], ren[b]);
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf;
vector<int>pat[300000];
bool flag[300000];
int dep[300000];
int md = 0, rr = 0;
void dfs(int node, int d)
{
	if (flag[node])return;
	flag[node] = true;
	dep[node] = d;
	if (d > md)md = d, rr = node;
	for (int i = 0; i < pat[node].size(); i++)dfs(pat[node][i], d + 1);
}
int dat[300000];
int main()
{
	int num, way, query;
	scanf("%d%d%d", &num, &way, &query);
	uf.init();
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		uf.unite(za, zb);
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag, flag + num, false);
	for (int i = 0; i < num; i++)
	{
		if (i == uf.find(i))
		{
			md = -1;
			dfs(i, 0);
			dat[i] = rr;
		}
	}
	fill(flag, flag + num, false);
	for (int i = 0; i < num; i++)
	{
		if (i == uf.find(i))
		{
			md = -1;
			dfs(dat[i], 0);
			uf.ren[i] = md;
		}
	}
	for (int i = 0; i < query; i++)
	{
		int za;
		scanf("%d", &za);
		if (za == 2)
		{
			int zb, zc;
			scanf("%d%d", &zb, &zc);
			zb--, zc--;
			uf.unite(zb, zc);
		}
		else
		{
			int z;
			scanf("%d", &z);
			z--;
			printf("%d\n", uf.ren[uf.find(z)]);
		}
	}
}