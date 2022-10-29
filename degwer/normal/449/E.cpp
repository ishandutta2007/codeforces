#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
vector<ll>dat[1000001];
ll tim[1000001];
ll rui[1000001];
ll r1[1000001], r2[1000001], r3[1000001];
int main()
{
	for (int i = 2; i <= 1000000; i++)
	{
		ll x = i;
		for (int j = 0; j < dat[i].size(); j++)x /= dat[i][j];
		if (x == 1)continue;
		for (int j = i; j <= 1000000; j += i)
		{
			dat[j].push_back(x);
		}
	}
	for (int i = 1; i <= 1000000; i++)
	{
		sort(dat[i].begin(), dat[i].end());
		dat[i].push_back(-1);
		ll t = 1;
		ll now = 0;
		ll c = 0;
		for (int j = 0; j < dat[i].size(); j++)
		{
			if (now != dat[i][j])
			{
				if (j != 0)
				{
					ll x = ((c + 1)*(now - 1) + 1) % mod;
					for (int k = 1; k < c; k++)x = x*now%mod;
					t *= x;
					t %= mod;
				}
				now = dat[i][j];
				c = 1;
			}
			else c++;
		}
		tim[i] = t;
		//if (i <= 10)printf("%I64d\n", tim[i]);
	}
	for (ll i = 1; i <= 1000000; i++)rui[i] = rui[i - 1] + i*i;
	for (ll i = 1; i <= 1000000; i++)
	{
		ll s = ((rui[i] * 2 - i*i * 3 + tim[i] * 2) % mod + mod) % mod;
		//if (i <= 10)printf("%I64d\n", s);
		r1[i] = (r1[i - 1] + s) % mod;
		r2[i] = (r2[i - 1] + s*i) % mod;
		r3[i] = (r3[i - 1] + s*i%mod*i) % mod;
	}
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		ll za, zb;
		scanf("%I64d%I64d", &za, &zb);
		ll n = min(za, zb);
		printf("%I64d\n", (mod + r3[n] - r2[n] * (za + zb + 2) % mod + r1[n] * ((za + 1)*(zb + 1) % mod)) % mod);
	}
}