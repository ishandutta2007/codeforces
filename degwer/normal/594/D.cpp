#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll po(ll a, ll b)
{
	if (b == 0)return 1LL;
	ll z = po(a, b / 2);
	z = (z*z) % mod;
	if (b % 2 == 1)z = (z*a) % mod;
	return z;
}
ll calcinv(ll a)
{
	return po(a, mod - 2);
}
ll inv[1000001];
#define SIZE 262144
class BIT
{
public:
	ll bit[SIZE + 1];
	void init()
	{
		fill(bit, bit + SIZE + 1, 1);
	}
	void add(int a, ll b)
	{
		a++;
		for (;;)
		{
			bit[a] *= b;
			bit[a] %= mod;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	ll get(int a)
	{
		if (a < 0)return 1LL;
		a++;
		ll ret = 1;
		for (;;)
		{
			ret *= bit[a];
			ret %= mod;
			a -= a&-a;
			if (a == 0)return ret;
		}
	}
};
BIT bi;
vector<ll>dat[1000001];
typedef pair<ll, ll>pii;
vector<pii>que[200000];
ll ans[200000];
ll las[1000001];
int main()
{
	int num;
	scanf("%d", &num);
	vector<ll>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	for (int i = 1; i <= 1000000; i++)inv[i] = calcinv(i);
	bi.init();
	for (int i = 2; i <= 1000000; i++)
	{
		if (dat[i].empty())
		{
			for (int j = i; j <= 1000000; j += i)dat[j].push_back(i);
		}
	}
	fill(las, las + 1000001, -1);
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		que[zb].push_back(make_pair(za, i));
	}
	for (int i = 0; i < num; i++)
	{
		vector<pii>z;
		ll now = vec[i];
		for (int j = 0; j < dat[vec[i]].size(); j++)
		{
			int c = 0;
			for (;;)
			{
				if (now%dat[vec[i]][j] == 0)
				{
					now /= dat[vec[i]][j];
					c++;
				}
				else break;
			}
			z.push_back(make_pair(dat[vec[i]][j], c));
		}
		for (int j = 0; j < z.size(); j++)
		{
			if (las[z[j].first] != -1)
			{
				bi.add(las[z[j].first], (z[j].first*inv[z[j].first - 1]) % mod);
			}
			las[z[j].first] = i;
			bi.add(i, z[j].first - 1);
			for (int k = 1; k < z[j].second; k++)
			{
				bi.add(i, z[j].first);
			}
		}
		for (int j = 0; j < que[i].size(); j++)
		{
			ans[que[i][j].second] = (bi.get(i)*calcinv(bi.get(que[i][j].first - 1))) % mod;
		}
	}
	for (int i = 0; i < query; i++)printf("%I64d\n", ans[i]);
}