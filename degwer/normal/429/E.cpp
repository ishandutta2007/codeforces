#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 200000
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
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
bool flag[200000];
int main()
{
	int num;
	scanf("%d", &num);
	vector<pi3>vec;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		vec.push_back(make_pair(make_pair(za, 0), i));
		vec.push_back(make_pair(make_pair(zb, 1), i));
	}
	sort(vec.begin(), vec.end());
	uf.init();
	for (int i = 0; i < num; i++)
	{
		if (vec[i * 2].first.second == vec[i * 2 + 1].first.second)
		{
			uf.unite(vec[i * 2].second * 2, vec[i * 2 + 1].second * 2 + 1);
			uf.unite(vec[i * 2].second * 2 + 1, vec[i * 2 + 1].second * 2);
		}
		else
		{
			uf.unite(vec[i * 2].second * 2, vec[i * 2 + 1].second * 2);
			uf.unite(vec[i * 2].second * 2 + 1, vec[i * 2 + 1].second * 2 + 1);
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (i * 2 == uf.find(i * 2))
		{
			if (!flag[uf.find(i * 2 + 1)])
			{
				flag[i * 2] = true;
			}
		}
		if (i * 2 + 1 == uf.find(i * 2 + 1))
		{
			if (!flag[uf.find(i * 2)])
			{
				flag[i * 2 + 1] = true;
			}
		}
		//printf("%d %d\n", uf.find(i * 2), uf.find(i * 2 + 1));
	}
	for (int i = 0; i < num; i++)
	{
		if (flag[uf.find(i * 2)])printf("0 ");
		else printf("1 ");
	}
	printf("\n");
}