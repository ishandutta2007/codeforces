/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 4e5 + 5, mod = 1e9 + 7;

ll a[N], b[N], fact[N], factInv[N];

void solve(int &n, bool &cur);
ll ncr(ll n, ll k);
ll fastModExp(ll x, ll e);

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	fact[0] = 1;
	factInv[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		fact[i] = (i * fact[i - 1]) % mod;
		factInv[i] = fastModExp(fact[i], mod - 2);
	}

	bool cur = 0;
	if (n < 2)
	{
		while (n > 1)
			solve(n, cur);

		cout << a[1];
		return 0;
	}

	if (n % 2 == 1)
		solve(n, cur);

	ll cycles = (n - 1) / 4, m = 2 * cycles, left = 2;
	if (n % 4 == 0)
		left = 4;

	for (int i = 1; i <= left; ++i)
	{
		ll temp = 0;
		for (int j = i, k = 0; k <= m; j += 2, ++k)
		{
			temp += (a[j] * ncr(m, k)) % mod;
			temp %= mod;
		}

		b[i] = temp;
	}

	n = left;
	for (int i = 1; i <= n; ++i)
		a[i] = b[i];

	while (n > 1)
		solve(n, cur);

	cout << a[1];
}

void solve(int &n, bool &cur)
{
	for (int i = 1; i < n; ++i)
	{
		if (!cur)
			a[i] = (a[i] + a[i + 1]) % mod;

		else
			a[i] = (a[i] - a[i + 1] + mod) % mod;

		cur = !cur;
	}

	--n;
}

ll ncr(ll n, ll k)
{
	ll ans = (fact[n] * factInv[k]) % mod;
	ans = (ans * factInv[n - k]) % mod;
	return ans;
}

ll fastModExp(ll x, ll e)
{
	x %= mod;
	ll res = 1;
	while (e)
	{
		if (e % 2)
			res = (res * x) % mod;

		x = (x * x) % mod;
		e /= 2;
	}

	return res;

}