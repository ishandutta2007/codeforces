/*
Hanit Banga
*/

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)
// #define double long double

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e4 + 5;
const double eps = 1e-7;

int main()
{
	int n, k; double l, v1, v2;
	cin >> n >> l >> v1 >> v2 >> k;

	double lo = 0, hi = l/v1, temp = (v1 * v2)/(v1 - v2);
	while ((hi - lo) > eps and (hi - lo) / hi > eps)
	{
		double mid = (lo + hi) / 2, dist = l, left = mid;
		int groups = (n / k) + (n % k ? 1 : 0);
		bool ok = true;
		while (groups > 0)
		{
			if (dist / v2 > left)
			{
				ok = false;
				break;
			}

			else if (dist / v1 <= left)
				break;

			double i = (left - dist/v1) * temp, j = (2 * i * v1)/(v1 + v2);
			--groups;
			dist -= j;
			left -= j / v1;
		}

		if (ok)
			hi = mid;
		else
			lo = mid;
	}

	cout << fixed << setprecision(7) << hi;
}