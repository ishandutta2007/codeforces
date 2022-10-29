#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map<int, int>ma;
typedef long long ll;
ll mod = 1000000007;
#define SIZE 100000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
void bun(int a)
{
	for (int i = 2;; i++)
	{
		if (i*i > a)break;
		for (;;)
		{
			if (a%i != 0)break;
			ma[i]++;
			a /= i;
		}
	}
	if (a != 1)ma[a]++;
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		bun(z);
	}
	map<int, int>::iterator it = ma.begin();
	ll ans = 1;
	invinit();
	for (;;)
	{
		if (it == ma.end())break;
		int t = (*it).second;
		ans *= com(t + num - 1, num - 1);
		ans %= mod;
		it++;
	}
	printf("%I64d\n", ans);
}