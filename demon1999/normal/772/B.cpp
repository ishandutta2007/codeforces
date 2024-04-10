/*
  !










*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)
const int MAXN = 1007;
double x[MAXN], y[MAXN];
double dist(int a, int b)
{
	double dx = x[a] - x[b], dy = y[a] - y[b];
	return sqrt(dx * dx + dy * dy);
}
double area(int a, int b, int c)
{
	double res = (x[b] - x[a]) * (y[c] - y[a]) - (x[c] - x[a]) * (y[b] - y[a]);
	if (res < 0) res = -res;
	return res / 2;
}
double height(int a, int b, int c) // from C
{
	double res = 2 * area(a, b, c) / dist(a, b);
	return res;
}
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf", &x[i], &y[i]);
	}
	double res = 1e50;
	for (int i = 0; i < n; i++)
	{
		int pi = (i + n - 1) % n, ni = (i + 1) % n;
		for (int j = i + 1; j < n; j++)
		{
			int pj = (j + n - 1) % n, nj = (j + 1) % n;
			if (ni != i && ni != j)
			{
				res = min(res, height(i, j, ni));
			}
			if (nj != j && nj != i)
			{
				res = min(res, height(i, j, nj));
			}
			if (pi != i && pi != j)
			{
				res = min(res, height(i, j, pi));
			}
			if (pj != i && pj != j)
			{
				res = min(res, height(i, j, pj));
			}
		}
	}
	printf("%.20lf\n", res / 2.0);
}