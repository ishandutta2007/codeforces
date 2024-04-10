#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second



int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> p(n);
	vector<int> x(m);
	for (auto &i : p) cin >> i;
	for (auto &i : x) cin >> i;

	sort(x.begin(), x.end());
	p.insert(p.begin(), 0);
	for (int i = 1; i <= n; ++i)
		p[i] += p[i - 1];

	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int b = i, e = n - 1;
		auto it = lower_bound(x.begin(), x.end(), 100 * i);
		while (b < e)
		{
			int j = (b + e + 1) >> 1;

			if (it != x.end() && *it <= 100 * j)
			{
				e = j - 1;
				continue;
			}

			if (it == x.begin() || it == x.end())
			{
				b = j;
				continue;
			}

			int l = *prev(it), r = *it;
			if (100 * i - l + 100 * i - 1 >= 100 * j - (r - 100 * j))
				b = j;
			else
				e = j - 1;
		}

		if (b == i)
		{
			if (it == x.end() || *it != 100 * i)
				ans = max(ans, p[i + 1] - p[i]);
		}
		else
		{
			ans = max(ans, p[b + 1] - p[i]);
		}
	}
	cout << ans << "\n";

	return 0;
}