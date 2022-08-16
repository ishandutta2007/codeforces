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
#define sq(x) (x) * (x)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5;
const double inf = 1e15;

double dist(int i, int j);
double solve(int p1, int n);

double x[N], y[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];

	double ans = inf;
	for (int i = 0; i < n; ++i)
	{
		ans = min(ans, dist(i, (i + 1) % n) / 2);
		ans = min(ans, solve(i, n));
	}

	cout << fixed << setprecision(7) << ans;
}

double dist(int i, int j)
{
	return sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));
}

double solve(int p1, int n)
{
	int p2 = (p1 + 1) % n, p3 = (p2 + 1) % n;
	double a = y[p1] - y[p3], b = x[p3] - x[p1], c = (x[p1] - x[p3]) * y[p1] + (y[p3] - y[p1]) * x[p1];
	double d = abs(a * x[p2] + b * y[p2] + c) / sqrt(a * a + b * b);
	return d / 2;
}