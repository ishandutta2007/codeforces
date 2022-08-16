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

const int N = 1e2 + 5;
const ll INF = 1e18;

int row[2*N];

int main()
{
	int n, m, x, y; ll k;
	cin >> n >> m >> k >> x >> y;

	ll mx = 0, mn = INF, ser = 0, r = k/m, c = k%m;
	if (n == 1)
	{
		cout << r + (c ? 1 : 0) << ' ' << r << ' ' << r + ((y <= c) ? 1 : 0);
		return 0;
	}

	ll cycleSize = 2*n - 2, cycles = r / (cycleSize), left = r % (cycleSize);

	for (int i = 1; i <= n; ++i)
		row[i] = i;

	for (int i = n+1, j = n-1; i <= cycleSize; ++i, --j)
		row[i] = j;

	for (int i = 1; i <= n; ++i)
	{
		ll times = cycles;
		if (i != 1 and i != n)
			times *= 2;

		for (int j = 1; j <= left; ++j)
			if (row[j] == i)
				++times;

		if (x == i)
			ser += times;

		mn = min(mn, times);
		if (row[left + 1] == i and c)
		{
			++times;
			if (x == i and c >= y)
				++ser;
		}

		mx = max(mx, times);
	}

	cout << mx << ' ' << mn << ' ' << ser;

}