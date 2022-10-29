#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<int>pat1[500000];
vector<int>pat2[500000];
bool flag[500000];
int dep[500000];
#define SIZE 500000
class unionfind
{
public:
	int par[SIZE];
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
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
		if (dep[a]<dep[b])
		{
			par[b] = a;
		}
		else
		{
			par[a] = b;
		}
	}
};
unionfind uf;
vector<int>ko[500000];
int par1[500000];
int par2[500000];
void dfs1(int node)
{
	if (flag[node])return;
	flag[node] = true;
	for (int i = 0; i < pat1[node].size(); i++)
	{
		if (!flag[pat1[node][i]])
		{
			par1[pat1[node][i]] = node;
			ko[node].push_back(pat1[node][i]);
			dfs1(pat1[node][i]);
		}
	}
}
void dfs2(int node, int d)
{
	if (flag[node])return;
	flag[node] = true;
	dep[node] = d;
	for (int i = 0; i < pat2[node].size(); i++)
	{
		if (!flag[pat2[node][i]])
		{
			par2[pat2[node][i]] = node;
			dfs2(pat2[node][i], d + 1);
		}
	}
}
void calc(int node)
{
	for (int i = 0; i < ko[node].size(); i++)calc(ko[node][i]);
	if (node == 0)return;
	if (uf.find(node) != uf.find(par1[node]))
	{
		int s = uf.find(node);
		printf("%d %d %d %d\n", node + 1, par1[node] + 1, s + 1, par2[s] + 1);
		uf.unite(s, par2[s]);
	}
}
typedef pair<int, int>pii;
int main()
{
	int num;
	scanf("%d", &num);
	set<pii>sx, sy;
	int ans = num - 1;
	uf.init();
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		pat1[za].push_back(zb);
		pat1[zb].push_back(za);
		sx.insert(make_pair(min(za, zb), max(za, zb)));
	}
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		pat2[za].push_back(zb);
		pat2[zb].push_back(za);
		sy.insert(make_pair(min(za, zb), max(za, zb)));
	}
	fill(flag, flag + num, false);
	dfs1(0);
	fill(flag, flag + num, false);
	dfs2(0, 0);
	set<pii>::iterator it = sx.begin();
	for (;;)
	{
		if (it == sx.end())break;
		if (sy.find(*it) != sy.end())
		{
			uf.unite((*it).first, (*it).second);
			ans--;
		}
		it++;
	}
	printf("%d\n", ans);
	calc(0);
}