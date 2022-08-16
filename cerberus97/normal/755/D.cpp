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

const int N = 1e5 + 5;

int main()
{
	ll n, k;
	cin >> n >> k;

	if (n - k < k)
		k = n - k;

	ll cur = 1, incr = 1, prev, st = 1, crossed = 0;
	for (int i = 1; i <= n; ++i)
	{
		prev = st;
		st += k;

		if (st > n)
			st -= n;

		if (crossed)
		{
			crossed = 0;
			++incr;
		}

		if (st < prev and st != 1)
		{
			crossed = 1;
			++incr;
		}

		cur += incr;
		cout << cur << ' ';
	}	
}