#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
pii num2(ll a)
{
	int ret = 0;
	for (;;)
	{
		if (a % 2 != 0)return make_pair(ret, a);
		a /= 2;
		ret++;
	}
}
ll mat[131][131];
ll rev[200];
ll now[131];
ll imos[131][131];
int main()
{
	ll num, gen, query;
	scanf("%I64d%I64d%I64d", &num, &gen, &query);
	gen = min(gen, num - 1);
	for (int i = 1; i < 200; i++)
	{
		if (i % 2 != 0)
		{
			for (ll j = 0;; j++)
			{
				if (((1LL << 32)*j + 1) % i == 0)
				{
					rev[i] = ((1LL << 32)*j + 1) / i;
					break;
				}
			}
		}
	}
	for (int i = 0; i <= gen; i++)
	{
		for (int j = i; j <= gen; j++)
		{
			ll n = num - i;
			ll p = j - i;
			int c = 0;
			ll now = 1;
			for (int k = 1; k <= p; k++)
			{
				pii z1 = num2(n - k + 1);
				pii z2 = num2(k);
				c += z1.first - z2.first;
				now *= z1.second*rev[z2.second] & ((1LL << 32) - 1);
				now &= ((1LL << 32) - 1);
			}
			mat[i][j] = now << (c % 32);
		}
	}
	fill(now, now + 131, 1);
	for (int i = 0; i <= gen; i++)
	{
		int n[131];
		fill(n, n + 131, 0);
		for (int j = 0; j <= gen; j++)
		{
			for (int k = 0; k <= gen; k++)
			{
				n[j] += mat[j][k] * now[k];
				n[j] &= ((1LL << 32) - 1);
			}
		}
		imos[0][i] = now[0];
		for (int j = 0; j <= gen; j++)now[j] = n[j];
	}
	for (int i = 0; i < gen; i++)
	{
		for (int j = 0; j < gen - i; j++)
		{
			imos[i + 1][j] = (imos[i][j + 1] - imos[i][j] + (1LL << 32))&((1LL << 32) - 1);
		}
	}
	ll t = imos[gen][0];
	ll ans[131];
	for (int i = 0; i <= gen; i++)ans[i] = imos[i][0];
	ll ret = 0;
	for (int i = 1; i <= query; i++)
	{
		ll n[131];
		fill(n, n + 131, 0);
		n[gen] = t;
		for (int j = gen - 1; j >= 0; j--)
		{
			n[j] = (ans[j + 1] + ans[j])&((1LL << 32) - 1);
		}
		for (int j = 0; j <= gen; j++)ans[j] = n[j];
		ret ^= (ans[0] * i)&((1LL << 32) - 1);
	}
	printf("%I64d\n", ret);
}