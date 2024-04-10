#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define SIZE 200010
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
typedef long long ll;
ll mod = 1000000007;
ll solve(vector<pi3>vec, int n)
{
	uf.init();
	//printf("%d-----\n",n);
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].first.first>vec[i].first.second)abort();
		//printf("%d %d  %d\n", vec[i].first.first, vec[i].first.second, vec[i].second);
		if (vec[i].second == 0)
		{
			uf.unite(vec[i].first.first * 2, (vec[i].first.second + 1) * 2);
			uf.unite(vec[i].first.first * 2 + 1, (vec[i].first.second + 1) * 2 + 1);
		}
		else
		{
			uf.unite(vec[i].first.first * 2 + 1, (vec[i].first.second + 1) * 2);
			uf.unite(vec[i].first.first * 2, (vec[i].first.second + 1) * 2 + 1);
		}
	}
	for (int i = 0; i <= n; i++)if (uf.find(i * 2) == uf.find(i * 2 + 1))return 0;
	int cnt = 0;
	for (int i = 0; i < 2 * (n + 1); i++)
	{
		if (uf.find(i) == i)cnt++;
	}
	if (cnt % 2 != 0)abort();
	ll ret = 1;
	for (int i = 0; i < cnt / 2 - 1; i++)
	{
		ret *= 2;
		ret %= mod;
	}
	return ret;
}
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<pi3>v1, v2;
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		char zc;
		scanf("%d%d %c", &za, &zb, &zc);
		if (za % 2 == zb % 2)
		{
			v1.push_back(make_pair(make_pair(abs(za - zb) / 2, (num - 1 - abs(za + zb - (num + 1))) / 2), int(zc == 'o')));
		}
		else
		{
			v2.push_back(make_pair(make_pair(abs(za - zb) / 2, (num - 1 - abs(za + zb - (num + 1))) / 2), int(zc == 'o')));
		}
	}
	ll a = solve(v1, (num + 1) / 2);
	ll b = solve(v2, num / 2);
	printf("%I64d\n", a*b%mod);
}