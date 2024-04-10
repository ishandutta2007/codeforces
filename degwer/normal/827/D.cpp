#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
typedef pair<int, pii>pi3;
typedef pair<pii, pii>pi4;
#define LOG 20
#define SIZE 500000
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
			ren[i] = 1;
		}
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else return par[a] = find(par[a]);
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			par[b] = a;
			ren[a] += ren[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf;
vector<pii>pat[SIZE];
vector<int>pidx[SIZE];
int idx[SIZE];
int par[LOG][SIZE];
int cst[LOG][SIZE];
int dep[SIZE];
bool flag[SIZE];
class unionfind2
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
			ren[i] = i;
		}
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else return par[a] = find(par[a]);
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			par[b] = a;
			if (dep[ren[a]] > dep[ren[b]])ren[a] = ren[b];
		}
		else
		{
			par[a] = b;
			if (dep[ren[b]] > dep[ren[a]])ren[b] = ren[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind2 uf2;
void dfs(int node, int d)
{
	if (flag[node])return;
	flag[node] = true;
	dep[node] = d;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i].first])
		{
			par[0][pat[node][i].first] = node;
			cst[0][pat[node][i].first] = pat[node][i].second;
			idx[pat[node][i].first] = pidx[node][i];
			dfs(pat[node][i].first, d + 1);
		}
	}
}
void lcainit(int num)
{
	for (int i = 1; i < LOG; i++)
	{
		for (int j = 0; j < num; j++)
		{
			par[i][j] = par[i - 1][par[i - 1][j]];
			cst[i][j] = max(cst[i - 1][j], cst[i - 1][par[i - 1][j]]);
		}
	}
}
pii lca(int a, int b)
{
	if (dep[a] > dep[b])swap(a, b);
	int maxi = 0;
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (dep[a] + (1 << i) <= dep[b])
		{
			maxi = max(maxi, cst[i][b]);
			b = par[i][b];
		}
	}
	if (a == b)return make_pair(a, maxi);
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (par[i][a] != par[i][b])
		{
			maxi = max(maxi, max(cst[i][a], cst[i][b]));
			a = par[i][a];
			b = par[i][b];
		}
	}
	return make_pair(par[0][a], max(maxi, max(cst[0][a], cst[0][b])));
}
int ans[SIZE];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	vector<pi4>zpt;
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		zpt.push_back(make_pair(make_pair(zc, i), make_pair(za, zb)));
	}
	uf.init();
	sort(zpt.begin(), zpt.end());
	vector<pi4>nontree;
	for (int i = 0; i < way; i++)
	{
		int x = zpt[i].second.first, y = zpt[i].second.second;
		if (uf.find(x) != uf.find(y))
		{
			uf.unite(x, y);
			int c = zpt[i].first.first;
			int d = zpt[i].first.second;
			pat[x].push_back(make_pair(y, c));
			pat[y].push_back(make_pair(x, c));
			pidx[x].push_back(d);
			pidx[y].push_back(d);
		}
		else nontree.push_back(zpt[i]);
	}
	dfs(0, 0);
	lcainit(num);
	/*for (int i = 0; i < num; i++)printf("%d %d\n", par[0][i], cst[0][i]);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%d %d  ", lca(i, j).first, lca(i, j).second);
		}
		printf("\n");
	}*/
	uf2.init();
	for (int i = 0; i < nontree.size(); i++)
	{
		int x = nontree[i].second.first, y = nontree[i].second.second;
		pii z = lca(x, y);
		ans[nontree[i].first.second] = z.second;
		for (;;)
		{
			//printf(" %d\n", x);
			x = uf2.ren[uf2.find(x)];
			if (uf2.find(x) == uf2.find(z.first))break;
			uf2.unite(x, par[0][x]);
			ans[idx[x]] = nontree[i].first.first;
		}
		for (;;)
		{
			y = uf2.ren[uf2.find(y)];
			if (uf2.find(y) == uf2.find(z.first))break;
			uf2.unite(y, par[0][y]);
			ans[idx[y]] = nontree[i].first.first;
		}
	}
	for (int i = 0; i < way; i++)printf("%d ", ans[i] - 1);
	printf("\n");
}