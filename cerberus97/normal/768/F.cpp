/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 5;
const ll mod = 1e9 + 7;

ll fact[N], factInv[N];

ll total(int n, int s1, int s2);
ll desir(int i, int j, int s1, int s2, ll h);
ll choose(ll n, ll k);
ll fastModExp(ll x, ll e);

int main()
{
	fact[0] = factInv[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		fact[i] = (i * fact[i - 1]) % mod;
		factInv[i] = fastModExp(fact[i], mod - 2);
	}

	int f, w, h;
	cin >> f >> w >> h;

	int n = f + w;
	ll num = 0, den = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (j)
				swap(f, w);

			num += desir(i, j, f, w, h);
			den += total(i, f, w);
			num %= mod;
			den %= mod;

			if (j)
				swap(f, w);
		}
	}

	cout << (num * fastModExp(den, mod - 2)) % mod;
}

ll total(int n, int s1, int s2)
{
	int p = (n + 1)/2, q = n - p;
	if (s1 > 0 and !p)
		return 0;
	if (s2 > 0 and !q)
		return 0;
	if (s1 < p or s2 < q)
		return 0;

	ll ans = 1;
	if (p)
		ans = (ans * choose(s1 - 1, p - 1));
	if (q)
		ans = (ans * choose(s2 - 1, q - 1)) % mod;

	return ans;
}

ll desir(int i, int j, int s1, int s2, ll h)
{
	int p = (i + 1)/2, q = i - p;
	if (s1 > 0 and !p)
		return 0;
	if (s2 > 0 and !q)
		return 0;

	ll ans = 1;
	if (!j)
	{
		swap(p, q);
		swap(s1, s2);
	}

	if (s1 < p*(h + 1) or s2 < q)
		return 0;

	if (p)
		ans = (ans * choose(s1 - p*(h + 1) + p - 1, p - 1));
	if (q)
		ans = (ans * choose(s2 - 1, q - 1)) % mod;

	return ans;
}

ll choose(ll n, ll k)
{
	ll ans = (fact[n] * factInv[k]) % mod;
	ans = (ans * factInv[n - k]) % mod;
	return ans;
}

ll fastModExp(ll x, ll e)
{
	ll res = 1;
	while (e)
	{
		if (e & 1)
			res = (res * x) % mod;

		x = (x * x) % mod;
		e /= 2;
	}

	return res;
}