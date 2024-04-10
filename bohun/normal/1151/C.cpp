#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 505, mod = 1e9 + 7;
ll l, r;
ll pt(int a, int b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return res;
}
ll fun(ll x)
{
	if(x == 0)
		return 0;
	ll b = 1;
	ll ile = 1;
	ll gdzie = 0;
	ll res = 0;
	ll parz = 2;
	ll nieparz = 1;
	while(gdzie <= x)
	{
		ll ele = 0;
		if(b == 1)
		{
			ele = nieparz;
		}
		else
		{
			ele = parz;
		}
		
		ll prawo = ile % mod;
		if(gdzie + ile >= x)
			prawo = (x - gdzie) % mod;
		ll eee = (ele + 2 * (prawo - 1)) % mod;
		res = (res + (ll) prawo % mod * (ele + eee) % mod * pt(2, mod - 2) % mod) % mod;
		if(b == 0)
		{
			parz = (parz + 2 * ile) % mod;
		}
		else
			nieparz = (nieparz + 2 * ile) % mod;
		b ^= 1;
		gdzie += ile;
		ile *= 2;
	}
	return res;
}
			
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> l >> r;
	int ans = (fun(r) - fun(l - 1) + mod) % mod;
	cout << ans;
	return 0;
}