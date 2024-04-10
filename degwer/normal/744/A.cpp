#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 200001
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
int d[1000];
int main()
{
	int num, way, gen;
	scanf("%d%d%d", &num, &way, &gen);
	vector<int>v;
	uf.init();
	for (int i = 0; i < gen; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		v.push_back(z);
	}
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		uf.unite(za, zb);
	}
	for (int i = 0; i < v.size(); i++)d[uf.find(v[i])] = 1;
	int maxi = 0, sum = 0;
	int ans = 0;
	for (int i = 0; i < num; i++)
	{
		if (i == uf.find(i))
		{
			if (d[i])
			{
				maxi = max(maxi, uf.ren[i]);
				ans += uf.ren[i] * (uf.ren[i] - 1) / 2;
			}
			else sum += uf.ren[i];
		}
	}
	printf("%d\n", ans - maxi*(maxi - 1) / 2 + (maxi + sum)*(maxi + sum - 1) / 2 - way);
}