/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include "iomanip"
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
const double inf = 1e18;

int main()
{
	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	double t1 = -inf, t2 = inf;
	for (int i = 1; i <= n; ++i)
	{
		int x, y, vx, vy;
		cin >> x >> y >> vx >> vy;
		if (!vx)
		{
			if (x <= x1 or x >= x2)
			{
				t2 = -1;
				break;
			}
		}

		else if (vx > 0)
		{
			t1 = max(t1, double(x1 - x) / vx);
			t2 = min(t2, double(x2 - x) / vx);
		}

		else
		{
			t1 = max(t1, double(x2 - x) / vx);
			t2 = min(t2, double(x1 - x) / vx);
		}

		if (!vy)
		{
			if (y <= y1 or y >= y2)
			{
				t2 = -1;
				break;
			}
		}

		else if (vy > 0)
		{
			t1 = max(t1, double(y1 - y) / vy);
			t2 = min(t2, double(y2 - y) / vy);
		}

		else
		{
			t1 = max(t1, double(y2 - y) / vy);
			t2 = min(t2, double(y1 - y) / vy);
		}
	}

	if (t1 >= t2 or t2 <= 0)
		cout << -1;

	else
		cout << fixed << setprecision(7) << max(0.0, t1);
}