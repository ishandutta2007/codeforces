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

const int N = 1e2 + 10;

int a[N] = {0}, b[N] = {0};

int main()
{
	int n, l;
	cin >> n >> l;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	int temp = l;
	for (int i = n; i >= 2; --i)
	{
		a[i] -= a[i - 1];
		temp -= a[i];
	}

	a[1] = temp;
	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	temp = l;
	for (int i = n; i >= 2; --i)
	{
		b[i] -= b[i - 1];
		temp -= b[i];
	}

	b[1] = temp;
	// for (int i = 1; i <= n; ++i)
	// 	cout << a[i] << ' ' << b[i] << endl;

	bool match = false;
	for (int j = 1; j <= n; ++j)
	{
		match = true;
		for (int i = 1, k = j; i <= n; ++i, ++k)
		{
			if (k > n)
				k = 1;

			if (a[i] != b[k])
			{
				match = false;
				break;
			}
		}

		if (match)
			break;
	}

	if (match)
		cout << "YES";

	else
		cout << "NO";


}