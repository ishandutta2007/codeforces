#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 1987654321987654321LL
#define PI 3.14159265358979323
#define MOD 998244353LL
using namespace std;
typedef long long ll;
ll fac[5001];
ll Pow(ll a, ll b)
{
	if (b == 0)return 1;
	if (b == 1)return a;
	if (b & 1) return (a*((Pow(a, b - 1)) % MOD)) % MOD;
	ll t = Pow(a, b / 2) % MOD;
	return (t*t) % MOD;
}
ll C(ll n, ll k)
{
	ll a = fac[n];
	ll b = (fac[k] * fac[n - k]) % MOD;
	return (a*Pow(b, MOD - 2)) % MOD;
}
ll P(ll n, ll k)
{
	ll a = fac[n];
	ll b = fac[n - k];
	return (a*Pow(b, MOD - 2)) % MOD;
}
inline ll cnt(ll a, ll b)
{
	ll d = min(a, b);
	ll c = 0;
	for (ll i = 0; i <= d; i++)
		c = (c + ((C(a, i)*P(b, i)) % MOD)) % MOD;
	return c;
}
int main() {
	fac[0] = 1;
	for (ll i = 1; i <= 5000; i++)
		fac[i] = (i*fac[i-1]) % MOD;
	ll a, b, c;
	scanf("%I64d%I64d%I64d", &a, &b, &c);
	ll AB = cnt(a, b), BC = cnt(b, c), CA = cnt(c, a);
	printf("%I64d", ((AB*BC)%MOD*CA)%MOD);
}