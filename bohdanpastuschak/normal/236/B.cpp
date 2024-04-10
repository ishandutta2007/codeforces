#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <map>
#include <iostream>
using namespace std;
#define ll long long
#define mod 1073741824
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)

bool isPrime(ll n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0)return false;
	return true;
}

ll tau(ll n)
{
	if (n == 1) return 1;
	if (isPrime(n)) return 2;
	ll ans = 1;
	FOR(i, 2, n + 1)
	{
		int exp = 0;
		while (n%i == 0)
		{
			n /= i;
			++exp;
		}
		ans *= (exp + 1);
	}

	return ans;
}

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans = 0;
	FOR(i, 1, a + 1)
	{
		FOR(j, 1, b + 1)
		{
			FOR(k, 1, c + 1)
			{
				ans += tau(i*j*k);
				ans %= mod;
			}
		}
	}
	cout << ans;
	return 0;
}