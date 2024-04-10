#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 100000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	int r[SIZE];
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
			ren[i] = 1;
			r[i] = 0;
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
			r[a] += r[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
			r[b] += r[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf;
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	uf.init();
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		uf.unite(za, zb);
		uf.r[uf.find(za)]++;
	}
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		if (uf.find(i) == i)
		{
			if (uf.ren[i] - uf.r[i] == 1)cnt++;
		}
	}
	printf("%d\n", cnt);
}