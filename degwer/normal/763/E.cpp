#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 120000
typedef pair<int, int>pii;
typedef pair<int, pii>pi3;
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	vector<pi3>hs;
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
		}
		hs.clear();
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else
		{
			int x = par[a];
			par[a] = find(par[a]);
			hs.push_back(make_pair(0, make_pair(a, x)));
			return par[a];
		}
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			hs.push_back(make_pair(0, make_pair(b, par[b])));
			par[b] = a;
		}
		else
		{
			hs.push_back(make_pair(0, make_pair(a, par[a])));
			par[a] = b;
		}
		if (ran[a] == ran[b])
		{
			hs.push_back(make_pair(1, make_pair(b, ran[b])));
			ran[b]++;
		}
	}
	void rolb()
	{
		for (int i = int(hs.size()) - 1; i >= 0; i--)
		{
			if (hs[i].first == 0)par[hs[i].second.first] = hs[i].second.second;
			else ran[hs[i].second.first] = hs[i].second.second;
		}
		hs.clear();
	}
};
unionfind uf;
#define B 320
#define NB 320
vector<int>pat[120000];
vector<pi3>qs[NB + 10];
int lb, ub;
int cnt;
void add(int x)
{
	for (int i = 0; i < pat[x].size(); i++)
	{
		if (lb <= pat[x][i] && pat[x][i] <= ub)
		{
			if (uf.find(x) != uf.find(pat[x][i]))
			{
				uf.unite(x, pat[x][i]);
				cnt--;
			}
		}
	}
	if (x == lb - 1)lb--;
	else ub++;
	cnt++;
	//printf("%d   %d %d\n", x,lb,ub);
}
int ans[120000];
int main()
{
	int num, gen, way;
	scanf("%d%d%d", &num, &gen, &way);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	int query;
	scanf("%d", &query);
	uf.init();
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		if (za / B == zb / B)
		{
			lb = za, ub = za - 1;
			cnt = 0;
			for (int j = za; j <= zb; j++)add(j);
			ans[i] = cnt;
			for (int j = za; j <= zb; j++)uf.par[j] = j, uf.ran[j] = 0;
		}
		else qs[za / B].push_back(make_pair(zb, make_pair(za, i)));
	}
	for (int p = 0; p < NB; p++)
	{
		uf.init();
		int x = (p + 1)*B;
		lb = x, ub = x - 1;
		cnt = 0;
		sort(qs[p].begin(), qs[p].end());
		for (int i = 0; i < qs[p].size(); i++)
		{
			//printf("--%d %d\n", qs[p][i].second.first, qs[p][i].first);
			for (int j = ub + 1; j <= qs[p][i].first; j++)add(j);
			uf.hs.clear();
			int nc = cnt;
			for (int j = x - 1; j >= qs[p][i].second.first; j--)add(j);
			ans[qs[p][i].second.second] = cnt;
			//printf("%d %d %d\n", lb, ub, cnt);
			uf.rolb();
			cnt = nc;
			lb = x;
			//printf("%d %d %d\n", lb, ub, cnt);
		}
	}
	for (int i = 0; i < query; i++)printf("%d\n", ans[i]);
}