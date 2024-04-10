#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
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
int main()
{
	int mx, my, q;
	scanf("%d%d%d", &mx, &my, &q);
	uf.init();
	for (int i = 0; i < q; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		uf.unite(za, mx + zb);
	}
	int cnt = -1;
	for (int i = 0; i < mx + my; i++)cnt += uf.find(i) == i;
	printf("%d\n", cnt);
}