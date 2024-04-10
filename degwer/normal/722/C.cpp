#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 100000
typedef long long ll;
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	ll d[SIZE];
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
			d[a] += d[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
			d[b] += d[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf;
int dat[100000];
int main()
{
	int num;
	scanf("%d", &num);
	uf.init();
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		uf.d[i] = z;
	}
	vector<int>v;
	vector<ll>ans;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		v.push_back(z);
		dat[z] = i;
	}
	ll maxi = 0;
	for (int i = num - 1; i >= 0; i--)
	{
		ans.push_back(maxi);
		if (v[i] != 0)if (dat[v[i] - 1]>i)uf.unite(v[i] - 1, v[i]);
		if (v[i] != num - 1)if (dat[v[i] + 1]>i)uf.unite(v[i] + 1, v[i]);
		maxi = max(maxi, uf.d[uf.find(v[i])]);
	}
	for (int i = ans.size() - 1; i >= 0; i--)printf("%I64d\n", ans[i]);
}