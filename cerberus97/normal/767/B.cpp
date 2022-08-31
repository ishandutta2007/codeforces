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
const ll inf = 1e15;

ll a[N];

int main()
{
	ll s, f, t; int n;
	cin >> s >> f >> t >> n;	

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	ll ans = -1, wait = inf;
	if (!n or a[1] > s)
	{
		cout << s;
		return 0;
	}

	if (a[1] > 0)
	{
		wait = s - a[1] + 1;
		ans = a[1] - 1;
	}

	ll x = t + s;
	for (int i = 2; i <= n; ++i)
	{
		if (x + t > f)
			break;

		if (a[i] == a[i - 1])
		{
			x += max(0ll, a[i] - x) + t;
			continue;
		}

		ll temp = max(0ll, x - a[i] + 1);
		if (temp < wait)
		{
			wait = temp;
			ans = min(x, a[i] - 1);
		}

		x += max(0ll, a[i] - x) + t;
	}

	if (x + t <= f)
	{
		wait = 0;
		ans = x;
	}

	cout << ans;
}