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

const int N = 1e2 + 10;
const ll inf = 1e15;

ll a[N];

int main()
{
	int n; ll k;
	cin >> n >> k;
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	k += sum;
	vector <ll> changes;
	changes.pb(1);
	changes.pb(inf);
	for (int i = 1; i <= n; ++i)
	{
		vector <ll> val;
		ll mx = ceil(sqrt(a[i]));
		for (int j = 1; j <= mx; ++j)
		{
			val.pb(j);
			val.pb(a[i] / j + !!(a[i] % j));
		}

		for (auto &j : val)
		{
			if (j == 1)
				continue;

			ll x = a[i] / (j - 1) - !(a[i] % (j - 1));
			if (a[i] / x + !!(a[i] % x) == j)
				changes.pb(x + 1);
		}
	}

	sort(changes.begin(), changes.end());
	int m = changes.size();
	ll ans = 1;
	for (int i = 0; i < m - 1; ++i)
	{
		if (changes[i] == changes[i + 1])
			continue;

		ll l = changes[i], r = changes[i + 1] - 1, x = 0;
		// cout << l << ' ';
		for (int j = 1; j <= n; ++j)
			x += (a[j] / l) + !!(a[j] % l);

		ll d_max = min(r, k / x);
		if (d_max >= l)
			ans = max(ans, d_max);
	}

	cout << ans;
}