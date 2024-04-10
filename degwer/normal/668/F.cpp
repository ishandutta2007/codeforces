#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll po(ll a, ll b)
{
	if (b == 0)return 1;
	ll z = po(a, b / 2);
	z = z*z%mod;
	if (b % 2 == 1)z = z*a%mod;
	return z;
}
ll inv(ll a)
{
	return po(a, mod - 2);
}
map<int, ll>ma[10000];
int deg[10000];
vector<int>frm[10000];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < gen; i++)
	{
		for (int j = 0; j < gen; j++)
		{
			if (i != j)ma[i][j] = mod - 1;
			if (i < j)frm[j].push_back(i);
		}
		deg[i] = gen - 1;
	}
	for (int i = gen; i < num; i++)
	{
		for (int j = 0; j < gen; j++)
		{
			int z;
			scanf("%d", &z);
			z--;
			ma[i][z] = ma[z][i] = mod - 1;
			deg[i]++;
			deg[z]++;
			frm[i].push_back(z);
		}
	}
	for (int i = 0; i < num; i++)ma[i][i] = deg[i];
	ll ans = 1;
	for (int i = num - 1; i >= 1; i--)
	{
		ll t = ma[i][i];
		ll iv = inv(mod - t);
		for (int j = 0; j < frm[i].size(); j++)
		{
			ll tim = iv*ma[frm[i][j]][i] % mod;
			for (int k = 0; k < frm[i].size(); k++)
			{
				ma[frm[i][j]][frm[i][k]] = (ma[frm[i][j]][frm[i][k]] + ma[i][frm[i][k]] * tim) % mod;
			}
		}
		ans *= t;
		ans %= mod;
	}
	printf("%I64d\n", ans);
}