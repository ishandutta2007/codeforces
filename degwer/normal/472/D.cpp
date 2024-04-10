#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll map[2000][2000];
#define SIZE 2000
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
typedef pair<ll, ll>pii;
typedef pair<ll, pii>pi3;
bool flag[2000];
ll dat[2000][2000];
vector<pii>pat[2000];
void dfs(int node, int p, ll d)
{
	if (flag[node])return;
	flag[node] = true;
	dat[p][node] = d;
	for (int i = 0; i < pat[node].size(); i++)dfs(pat[node][i].first, p, d + pat[node][i].second);
}
int main()
{
	int num;
	scanf("%d", &num);
	vector<pi3>v;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			scanf("%I64d", &map[i][j]);
			if (i < j)v.push_back(make_pair(map[i][j], make_pair(i, j)));
		}
	}
	sort(v.begin(), v.end());
	uf.init();
	for (int i = 0; i < v.size(); i++)
	{
		if (uf.find(v[i].second.first) != uf.find(v[i].second.second))
		{
			uf.unite(v[i].second.first, v[i].second.second);
			pat[v[i].second.first].push_back(make_pair(v[i].second.second, v[i].first));
			pat[v[i].second.second].push_back(make_pair(v[i].second.first, v[i].first));
		}
	}
	for (int i = 0; i < num; i++)
	{
		fill(flag, flag + num, false);
		dfs(i, i, 0);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (map[i][j] != dat[i][j])
			{
				printf("NO\n");
				return 0;
			}
			if (i != j&&dat[i][j] == 0)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}