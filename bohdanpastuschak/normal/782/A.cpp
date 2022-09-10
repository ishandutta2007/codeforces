#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i>= (a); --i)

#define vec(a) vector<ll> a
#define vec(a,n) vector<ll>a(n)
#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cin>>a[i]
#define sortVec(a) sort(a.begin(), a.end())
#define infinity (ll)1e18
#define epsilon 1e-5

bool isPrime(ll n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i*i <= n; ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

ll power(int n, int to)
{
	if (to == 0) return 1;
	if (to == 1) return n;
	int exp = 1;
	ll ans = n;
	while (2 * exp <= to)
	{
		ans *= ans;
		ans %= mod;
		exp *= 2;
	}
	return ((ans*power(n, to - exp)) % mod);
}

ll C(int n, int k)
{
	ll* fact = new ll[k + 1];
	fact[0] = 1;
	for (int i = 1; i <= k; ++i)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	if (k > n - k) k = n - k;
	ll factK = fact[k];
	ll factNK = factK;
	for (int i = k + 1; i <= n - k; ++i)
	{
		factNK *= i;
		factNK %= mod;
	}

	ll factN = factNK;
	for (int i = n - k + 1; i <= n; ++i)
	{
		factN *= i;
		factN %= mod;
	}

	ll answer = factN;
	answer *= power(factK, mod - 2);
	answer %= mod;
	answer *= power(factNK, mod - 2);
	return answer%mod;
}

ll phi(ll n)
{
	if (n == 1) return 0;
	ll ans = n;
	for (int i = 2; i <= n; ++i)
	{
		if (n%i == 0)
		{
			ans = (ans*(i - 1)) / i;
			while (n%i == 0)
				n /= i;
		}
	}
	return ans;
}

ll tau(ll n)
{
	if (n == 1) return 1;
	ll ans = 1;
	for (ll i = 2; i < n; ++i)
	{
		int exp = 0;
		while (n%i == 0)
		{
			n /= i;
			exp++;
		}
		ans *= (exp + 1);
	}
	return ans;
}

int main()
{
	ll n;
	cin >> n;
	
	vector<bool> used(n);
	FOR(i, 0, n)
		used[i] = false;

	ll already = 0;
	ll max = -1;
	FOR(i, 0, 2 * n)
	{
		int t;
		cin >> t;
		if (used[t - 1])already--;
		else
		{
			used[t - 1] = true;
			already++;
		}
		if (already > max) max = already;
	}
	cout << max;

	return 0;
}