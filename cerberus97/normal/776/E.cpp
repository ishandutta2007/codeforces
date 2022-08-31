/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include "cmath"

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, mod = 1e9 + 7;

ll solve(ll n, ll k);
ll totient(ll n);

int main()
{
	ll n, k;
	cin >> n >> k;
	cout << solve(n, (k + 1) / 2);	
}

ll solve(ll n, ll k)
{
	ll ans = n;
	while (k--)
	{
		ans = totient(ans);
		if (ans == 1)
			break;
	}

	return ans % mod;
}

ll totient(ll n)
{
	ll sq = sqrt(n), num = 1, den = 1, temp = n;
	for (int i = 2; i <= sq; ++i)
	{
		if (n % i == 0)
		{
			num *= (i - 1);
			den *= i;

			while (n % i == 0)
				n /= i;
		}
	}

	if (n > 1)
	{
		num *= (n - 1);
		den *= n;
	}

	return (temp/den) * num;
}