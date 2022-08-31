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

int lt[N], rt[N];

int main()
{
	string a, b;
	cin >> a >> b;

	int n = a.length(), m = b.length();
	for (int i = 0, j = 0; i < n; ++i)
	{
		if (j >= m)
		{
			lt[i] = m - 1;
			continue;
		}

		if (a[i] == b[j])
		{
			lt[i] = j;
			++j;
		}

		else
			lt[i] = j - 1;
	}

	rt[n] = m;
	for (int i = n - 1, j = m - 1; i >= 0; --i)
	{
		if (j < 0)
		{
			rt[i] = 0;
			continue;
		}

		if (a[i] == b[j])
		{
			rt[i] = j;
			--j;
		}

		else
			rt[i] = j + 1;
	}

	int ans = rt[0], best_l = -1, best_r = rt[0];
	for (int i = 0; i < n; ++i)
	{
		int l = lt[i], r = rt[i + 1];
		if (l >= r)
		{
			ans = 0;
			best_l = 0;
			best_r = 1;
			break;
		}

		if (r - l - 1 < ans)
		{
			ans = r - l - 1;
			best_l = lt[i];
			best_r = rt[i + 1];
		}
	}

	if (ans == m)
		cout << '-';

	else
	{
		for (int i = 0; i <= best_l and i < m; ++i)
			cout << b[i];

		for (int i = best_r; i < m; ++i)
			cout << b[i];
	}
}