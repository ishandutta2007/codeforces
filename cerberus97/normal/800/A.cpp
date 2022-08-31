/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;
const double MX = 1e12, eps = 1e-5;

double a[N], b[N], c[N];

int main()
{
	int n; double p, sum = 0;
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i];
		sum += a[i];
		c[i] = b[i] / a[i];
	}

	if (sum <= p)
	{
		cout << -1 << endl;
		return 0;
	}

	double l = 0, r = MX;
	while (abs(l - r) > eps)
	{
		double mid = (l + r) / 2, req = 0;
		for (int i = 0; i < n; ++i)
		{
			if (c[i] >= mid)
				continue;

			req += ((mid - c[i]) * a[i]) / p;
		}

		if (req <= mid)
			l = mid;

		else
			r = mid;
	}

	cout << fixed << setprecision(7) << l << endl;

}