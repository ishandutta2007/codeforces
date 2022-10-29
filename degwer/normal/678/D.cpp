#include<stdio.h>
#include<vector>
#include<algorithm>
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
int main()
{
	ll a, b, n, x;
	scanf("%I64d%I64d%I64d%I64d", &a, &b, &n, &x);
	ll ans = po(a, n)*x;
	if (a == 1)ans += (n%mod)*b;
	else ans += ((po(a, n) - 1)*inv(a - 1) % mod)*b;
	printf("%I64d\n", ans%mod);
}