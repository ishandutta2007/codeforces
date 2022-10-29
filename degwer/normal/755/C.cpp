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
int main()
{
	uf.init();
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		uf.unite(i, z);
	}
	int c = 0;
	for (int i = 0; i < num; i++)c += (uf.find(i) == i);
	printf("%d\n", c);
}