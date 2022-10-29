#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 600000
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
#define LOG 20
typedef long long ll;
typedef pair<ll, ll>pii;
vector<pii>pat[SIZE];
int par[SIZE];
int dep[SIZE];
bool flag[SIZE];
bool used[SIZE];
int nowpar[SIZE];
void dfs(int node, int d)
{
	if (flag[node])return;
	flag[node] = true;
	dep[node] = d;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i].first])
		{
			par[pat[node][i].first] = node;
			used[pat[node][i].first] = pat[node][i].second;
			dfs(pat[node][i].first, d + 1);
			nowpar[pat[node][i].first] = node;
		}
	}
}
int a[SIZE], b[SIZE];
ll cst[SIZE];
int main()
{
	uf.init();
	int num, way, zway;
	scanf("%d%d%d", &num, &way, &zway);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(make_pair(zb, 0));
		pat[zb].push_back(make_pair(za, 0));
		uf.unite(za, zb);
	}
	for (int i = 0; i < zway; i++)
	{
		scanf("%d%d%I64d", &a[i], &b[i], &cst[i]);
		a[i]--, b[i]--;
		if (uf.find(a[i]) != uf.find(b[i]))
		{
			pat[a[i]].push_back(make_pair(b[i], 1));
			pat[b[i]].push_back(make_pair(a[i], 1));
			uf.unite(a[i], b[i]);
		}
	}
	dfs(0, 0);
	ll ret = 0;
	int g = 0;
	for (int i = 0; i < zway; i++)
	{
		int x = a[i], y = b[i];
		vector<int>zv;
		int cnt = 0;
		for (;;)
		{
			if (x == y)break;
			if (dep[x] < dep[y])swap(x, y);
			zv.push_back(x);
			if (!used[x])cnt++, used[x] = true;
			x = nowpar[x];
		}
		for (int j = 0; j < zv.size(); j++)nowpar[zv[j]] = x;
		ret += cst[i] * cnt;
		g += cnt;
	}
	if (g != way)printf("-1\n");
	else printf("%I64d\n", ret);
}