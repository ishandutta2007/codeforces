/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

ll ceildiv(ll a, ll b);

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll x, y, p, q;
		cin >> x >> y >> p >> q;

		if (p == 0)
		{
			if (x > 0)
				cout << -1 << '\n';

			else
				cout << 0 << '\n';

			continue;
		}

		if (p == q)
		{
			if (x == y)
				cout << 0 << '\n';

			else
				cout << -1 << '\n';

			continue;
		}

		ll sm = max(ceildiv(q * x - p * y, p), ceildiv(p * y - q * x, q - p));
		sm = max(0ll, sm);

		ll temp = (-(y % q) + q) % q;
		temp = (temp - (sm % q) + q) % q;
		sm += temp;

		cout << sm << endl;
	}	
}

ll ceildiv(ll a, ll b)
{
	return (a / b) + ((a % b) ? 1 : 0);
}