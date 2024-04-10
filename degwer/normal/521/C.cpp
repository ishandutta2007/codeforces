#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define SIZE 100000
ll inv[SIZE+1];
ll kai[SIZE+1];
ll invkai[SIZE+1];
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
ll rui[100001];
int main()
{
	invinit();
	int num, gen;
	scanf("%d%d", &num, &gen);
	ll ans = 0;
	vector<ll>v;
	for (int i = 0; i < num; i++)
	{
		char z;
		scanf(" %c", &z);
		ll t = z - '0';
		v.push_back(t);
		rui[i + 1] = rui[i] + t;
	}
	ll now = 1;
	for (int i = 1; i <= num; i++)
	{
		ll s = 0;
		s += com(num - i - 1, gen - 1)*rui[num - i];
		s += com(num - i, gen)*v[num - i];
		ans += s%mod*now;
		ans %= mod;
		now *= 10;
		now %= mod;
	}
	printf("%I64d\n", ans);
}