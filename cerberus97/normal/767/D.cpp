/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 5, M = 1e7 + 5;

int a[M] = {0}, c[M];
pii b[N];

int main()
{
	fast_cin();
	int n, m; ll k;
	cin >> n >> m >> k;

	int d = 0;
	for (int i = 1; i <= n; ++i)
	{
		int f;
		cin >> f;
		a[f]++;
		d = max(d, f);
	}

	for (int i = 1; i <= m; ++i)
	{
		cin >> b[i].first;
		b[i].second = i;
		d = max(d, b[i].first);
	}

	if (a[0] > k)
	{
		cout << -1;
		return 0;
	}

	c[0] = a[0];
	for (int i = 1; i <= d; ++i)
	{
		c[i] = a[i] + c[i - 1];
		if (c[i] > (i + 1) * k)
		{
			cout << -1;
			return 0;
		}
	}

	sort(b + 1, b + m + 1);
	int l = 1, r = m;
	while (l <= r)
	{
		int mid = (l + r)/2;
		bool ans = true;
		for (int i = 0; i <= d; ++i)
			c[i] = a[i];

		for (int i = mid; i <= m; ++i)
			++c[b[i].first];

		for (int i = 1; i <= d; ++i)
			c[i] += c[i - 1];

		for (int i = b[mid].first; i <= d; ++i)
		{
			if (c[i] > (i + 1) * k)
			{
				ans = false;
				break;
			}
		}

		if (ans)
			r = mid - 1;
		else
			l = mid + 1;
	}

	cout << m - r << endl;
	for (int i = r + 1; i <= m; ++i)
		cout << b[i].second << ' ';
}