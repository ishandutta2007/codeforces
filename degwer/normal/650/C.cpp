#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 1000000
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
vector<int>dat[1000000];
typedef pair<int, int>pii;
vector<int>pat[1000000];
vector<int>d[1000000];
int ans[1000000];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			int z;
			scanf("%d", &z);
			dat[i].push_back(z);
		}
	}
	uf.init();
	for (int i = 0; i < mx; i++)
	{
		vector<pii>vec;
		for (int j = 0; j < my; j++)vec.push_back(make_pair(dat[i][j], i*my + j));
		sort(vec.begin(), vec.end());
		for (int j = 0; j < my - 1; j++)
		{
			if (vec[j].first == vec[j + 1].first)
			{
				uf.unite(vec[j].second, vec[j + 1].second);
			}
			else
			{
				pat[vec[j].second].push_back(vec[j + 1].second);
			}
		}
	}
	for (int i = 0; i < my; i++)
	{
		vector<pii>vec;
		for (int j = 0; j < mx; j++)vec.push_back(make_pair(dat[j][i], j*my + i));
		sort(vec.begin(), vec.end());
		for (int j = 0; j < mx - 1; j++)
		{
			if (vec[j].first == vec[j + 1].first)
			{
				uf.unite(vec[j].second, vec[j + 1].second);
			}
			else
			{
				pat[vec[j].second].push_back(vec[j + 1].second);
			}
		}
	}
	for (int i = 0; i < mx*my; i++)
	{
		for (int j = 0; j < pat[i].size(); j++)
		{
			d[uf.find(i)].push_back(uf.find(pat[i][j]));
		}
	}
	vector<pii>to;
	for (int i = 0; i < mx*my; i++)
	{
		to.push_back(make_pair(dat[i / my][i%my], i));
	}
	sort(to.begin(), to.end());
	fill(ans, ans + mx*my, 1);
	for (int i = 0; i < to.size(); i++)
	{
		if (uf.find(to[i].second) == to[i].second)
		{
			for (int j = 0; j < d[to[i].second].size(); j++)
			{
				ans[d[to[i].second][j]] = max(ans[d[to[i].second][j]], ans[to[i].second] + 1);
			}
		}
	}
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			if (j != 0)printf(" ");
			printf("%d", ans[uf.find(i*my + j)]);
		}
		printf("\n");
	}
}