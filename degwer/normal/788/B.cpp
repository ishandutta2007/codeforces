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
typedef long long ll;
ll deg[1000000];
int isv[1000000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	uf.init();
	ll cnt = 0;
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		uf.unite(za, zb);
		if (za == zb)cnt++;
		else deg[za]++, deg[zb]++;
		isv[za] = isv[zb] = 1;
	}
	int root;
	for (int i = 0; i < num; i++)
	{
		if (isv[i])root = uf.find(i);
	}
	for (int i = 0; i < num; i++)
	{
		if (isv[i] && uf.find(i) != root)
		{
			printf("0\n");
			return 0;
		}
	}
	ll ans = 0;
	for (int i = 0; i < num; i++)ans += deg[i] * (deg[i] - 1) / 2;
	ans += cnt*((ll)way - cnt);
	ans += cnt*(cnt - 1) / 2;
	printf("%I64d\n", ans);
}