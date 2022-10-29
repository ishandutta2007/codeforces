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
int dat[100000];
int x1[100000], x2[100000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]);
	fill(x1, x1 + 100000, -1);
	fill(x2, x2 + 100000, -1);
	for (int i = 0; i < way; i++)
	{
		int zn;
		scanf("%d", &zn);
		for (int j = 0; j < zn; j++)
		{
			int z;
			scanf("%d", &z);
			z--;
			if (x1[z] == -1)x1[z] = i;
			else x2[z] = i;
		}
	}
	uf.init();
	for (int i = 0; i < num; i++)
	{
		if (dat[i] == 1)uf.unite(x1[i] * 2, x2[i] * 2), uf.unite(x1[i] * 2 + 1, x2[i] * 2 + 1);
		else uf.unite(x1[i] * 2, x2[i] * 2 + 1), uf.unite(x1[i] * 2 + 1, x2[i] * 2);
	}
	for (int i = 0; i < way; i++)
	{
		if (uf.find(i * 2) == uf.find(i * 2 + 1))
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}