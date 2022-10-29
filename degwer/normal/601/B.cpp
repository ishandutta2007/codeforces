#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define SIZE 100000
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
typedef long long ll;
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	vector<pii>dat;
	for (int i = 0; i < num - 1; i++)
	{
		dat.push_back(make_pair(abs(v[i + 1] - v[i]), i));
	}
	sort(dat.begin(), dat.end());
	for (int p = 0; p < query; p++)
	{
		ll ans = 0;
		uf.init();
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		for (int i = 0; i < dat.size(); i++)
		{
			if (za <= dat[i].second&&dat[i].second + 1 <= zb)
			{
				ans += (ll)dat[i].first*(ll)uf.ren[uf.find(dat[i].second)] * (ll)uf.ren[uf.find(dat[i].second + 1)];
				uf.unite(dat[i].second, dat[i].second + 1);
			}
		}
		printf("%I64d\n", ans);
	}
}