/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include "map"
#include "cstdlib"

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;
const ll inf = 1e15;

ll a[N], s[N];
ll count(ll x, int n);

int main()
{
	int n, k;
	cin >> n >> k;

	s[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	ll temp = 1, ans = 0;
	if (k == 1)
		ans = count(1, n);
	else if (k == -1)
		ans = count(1, n) + count(-1, n);
	else
	{
		while (abs(temp) <= inf)
		{
			ans += count(temp, n);
			temp *= k;
		}
	}

	cout << ans;
}

ll count(ll x, int n)
{
	map <ll, ll> ctr;
	ll ans = 0;
	for (int i = n; i >= 1; --i)
	{
		++ctr[s[i]];
		ans += ctr[x + s[i - 1]];
	}

	return ans;
}