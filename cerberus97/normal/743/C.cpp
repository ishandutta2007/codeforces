/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;
const ll C = 1e9;

int main()
{
	ll n;
	cin >> n;
	// n = 10000;

	// ll mx = n*C/(2*C - n);

	for (ll x = 1; x <= 2*n; ++x)
	{
		ll num = n*x*x, den = 2*x*x - n*(x+x), numChange = n*x, denChange = 2*x - n; 

		for (ll y = x+1; y <= 2*n; ++y)
		{
			num += numChange;
			den += denChange;

			if (den <= 0)
				continue;

			ll z = num/den;

			if (num % den == 0 and z <= C and z != x and z != y)
			{
				cout << x << ' ' <<  y << ' ' << z;
				return 0;
			}
		}
	}

	cout << -1;
}