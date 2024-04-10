#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
#define SIZE 100000
#define LOG 20
vector<int>pat[SIZE];
vector<int>ko[SIZE];
int par[LOG][SIZE];
bool flag[SIZE];
int ord[SIZE];
int rord[SIZE];
int depth[SIZE];
int ordpt = 0;
void dfs(int node, int d)
{
	if (flag[node])return;
	flag[node] = true;
	rord[ordpt] = node;
	ord[node] = ordpt++;
	depth[node] = d;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			par[0][pat[node][i]] = node;
			dfs(pat[node][i], d + 1);
		}
	}
}
int num;
void lcainit()
{
	for (int i = 1; i < LOG; i++)
	{
		for (int j = 0; j < num; j++)
		{
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
}
int lca(int a, int b)
{
	if (a == -1 || b == num)return -1;
	if (depth[a] > depth[b])swap(a, b);
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (depth[b] >= depth[a] + (1 << i))
		{
			b = par[i][b];
		}
	}
	if (a == b)return a;
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (par[i][a] != par[i][b])
		{
			a = par[i][a];
			b = par[i][b];
		}
	}
	return par[0][a];
}
set<pi3>se;
set<int>idx;
int getd(int a, int b)
{
	if (a == -1 || b == num)return -1;
	return depth[lca(rord[a], rord[b])];
}
int getl(int a, int b)
{
	if (a == -1 || b == num)return -1;
	return ord[lca(rord[a], rord[b])];
}
int main()
{
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag, flag + num, false);
	dfs(0, 0);
	lcainit();
//	for (int i = 0; i < num; i++)
//	{
//		for (int j = 0; j < num; j++)
	//	{
	//		printf("%d ", lca(i, j));
	//	}
	//	printf("\n");
//	}
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int zn;
		scanf("%d", &zn);
		se.clear();
		idx.clear();
		for (int i = 0; i < zn; i++)
		{
			int z;
			scanf("%d", &z);
			z--;
			idx.insert(ord[z]);
		//	printf("%d\n", ord[z]);
		}
		set<int>::iterator it = idx.begin();
		for (;;)
		{
			int x = *it;
			it++;
			if (it == idx.end())break;
			int y = *it;
			se.insert(make_pair(make_pair(getd(x, y), getl(x, y)), x));
		}
		idx.insert(-1);
		idx.insert(num);
		se.insert(make_pair(make_pair(-1, -1), -1));
		se.insert(make_pair(make_pair(-1, -1), num));
		bool f = true;
		int ans = 0;
		int cnt = zn;
		for (;;)
		{
		//	printf("-----\n");
		//	set<pi3>::iterator ooo = se.begin();
		//	for (;;)
		//	{
		//		if (ooo == se.end())break;
		//		printf("%d %d %d\n", (*ooo).first.first, rord[(*ooo).first.second]+1, rord[(*ooo).second]+1);
		//		ooo++;
		//	}
			if (cnt<=1)break;
			set<pi3>::iterator it2 = se.end();
			it2--;
			pi3 z = *it2;
			vector<int>v;
			it = idx.find(z.second);
		//	printf("%d %d\n", *it, z.second);
			it++;
			v.push_back(*it);
		//	printf("%d %d\n", (*it), z.second);
			int now = z.first.second;
			for (;;)
			{
				if (now != (*it2).first.second)
				{
					break;
				}
				v.push_back((*it2).second);
				if (it2 == se.begin())break;
				it2--;
			}
			//for (int i = 0; i < v.size(); i++)printf(" %d ", v[i]); printf("\n");
		//	printf("  now %d\n", rord[now]+1);
			if (v[v.size() - 1] == now)
			{
				int mini = 1000000000;
				for (int i = 0; i < v.size() - 1; i++)mini = min(mini, depth[rord[v[i]]]);
				if (mini == depth[rord[now]] + 1)
				{
					f = false;
					break;
				}
				ans += v.size() - 1;
				it = idx.find(v[0]);
				it++;
				int y = *it;
				it = idx.find(v[v.size() - 1]);
				int x = *it;
				it--;
				int w = *it;
				se.erase(make_pair(make_pair(getd(v[0], y), getl(v[0], y)), v[0]));
				for (int i = 0; i < v.size() - 1; i++)se.erase(make_pair(make_pair(getd(v[i + 1], v[i]), getl(v[i + 1], v[i])), v[i + 1]));
				for (int i = 0; i < v.size() - 1; i++)idx.erase(v[i]);
				se.insert(make_pair(make_pair(getd(x, y), getl(x, y)), x));
				se.insert(make_pair(make_pair(getd(w, x), getl(w, x)), w));
				cnt -= v.size() - 1;
			}
			else
			{
				ans++;
				it = idx.find(v[0]);
				it++;
				int y = *it;
				it = idx.find(v[v.size() - 1]);
				it--;
				int x = *it;
				se.erase(make_pair(make_pair(getd(x, v[v.size() - 1]), getl(x, v[v.size() - 1])), x));
				se.erase(make_pair(make_pair(getd(v[0], y), getl(v[0], y)), v[0]));
				for (int i = 0; i < v.size() - 1; i++)se.erase(make_pair(make_pair(getd(v[i + 1], v[i]), getl(v[i + 1], v[i])), v[i + 1]));
				for (int i = 0; i < v.size(); i++)idx.erase(v[i]);
				se.insert(make_pair(make_pair(getd(x, y), getl(x, y)), x));
				cnt -= v.size();
			}
		}
		if (f)printf("%d\n", ans);
		else printf("-1\n");
	}
}