/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

ll f(ll n, ll mod);
ll fastModExp(ll x, ll e, ll mod);

int main()
{
	const ll mod = 1e6 + 3;
	ll n, k;
	cin >> n >> k;

	if (n < 60 and (1ll << n) < k)
	{
		cout << "1 1\n";
		return 0;
	}

	ll num = 1, p = fastModExp(2, n, mod);
	for (ll i = 0; i <= k - 1; ++i)
	{
		num = (num * ((p - (i % mod) + mod) % mod)) % mod;
		if (!num)
			break;			
	}

	ll exp = ((n % (mod - 1)) * (k % (mod - 1))) % (mod - 1);
	ll div = fastModExp(fastModExp(2, (f(k - 1, mod - 1) + n) % (mod - 1), mod), mod - 2, mod);
	ll den = (fastModExp(2, exp, mod) * div) % mod;
	num = (num * div) % mod;
	num = (den - num + mod) % mod;

	cout << num << ' ' << den << endl;
}

ll f(ll n, ll mod)
{
	ll ans = 0;
	for (ll i = 2; i <= n; i *= 2)
		ans = (ans + n/i) % mod;

	return ans;
}

ll fastModExp(ll x, ll e, ll mod)
{
	x %= mod;
	ll res = 1;
	while (e)
	{
		if (e % 2 == 1)
			res = (res * x) % mod;

		x = (x * x) % mod;
		e /= 2;
	}

	return res;
}