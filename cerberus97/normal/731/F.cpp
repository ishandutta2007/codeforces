#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int a[N];
bool seen[N];

ll numBetw(int l, int r, int n)
{
	return upper_bound(a, a+n, r) - lower_bound(a, a+n, l);
	// return 1;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a+n);

	ll res = 0;

	for (int i = 0; i < n; ++i)
	{
		if (seen[a[i]])
			continue;

		seen[a[i]] = true;

		ll temp = 0;

		// cout << i << ' ' << a[i] << endl;

		for (int st = a[i], en = 2*a[i]-1, j = 1; st <= a[n-1]; st += a[i], en += a[i], ++j)
		{
			// cout << st << ' ' << en << ' ' << numBetw(st, en, n) << endl;
			temp += j * numBetw(st, en, n);
		}

		temp *= a[i];
		res = max(temp, res);
	}	

	cout << res;
}