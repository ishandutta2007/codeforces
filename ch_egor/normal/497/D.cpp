#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1005;

const double eps = 1e-9;

struct point 
{
	double x;
	double y;
};

point operator+(const point &a, const point &b)
{
	return {a.x + b.x, a.y + b.y};
}

point operator-(const point &a, const point &b)
{
	return {a.x - b.x, a.y - b.y};
}

point operator*(const point &a, double x)
{
	return {a.x * x, a.y * x};
}

double operator*(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}

double operator%(const point &a, const point &b)
{
	return a.x * b.x + a.y * b.y;
}

int n, m;
point p, q;
point arr1[MAX_N];
point arr2[MAX_N];

double get_min(point a, point b, point c)
{
	double l = 0;
	double r = 100;
	double best = LLINF;
	for (int i = 0; i < 22; ++i)
	{
		point x1 = a + (b - a) * ((2 * l + r) / 3 / 100);
		point x2 = a + (b - a) * ((l + 2 * r) / 3 / 100);
		double ax1 = (c - x1) % (c - x1);
		double ax2 = (c - x2) % (c - x2);
		if (ax1 < ax2)
		{
			r = (l + 2 * r) / 3;
		}
		else
		{
			l = (2 * l + r) / 3;
		}
		best = min(best, min(ax1, ax2));
	}
	return sqrt(best);
}

double get_max(point a, point b, point c)
{
	double l = 0;
	double r = 100;
	double best = -LLINF;
	for (int i = 0; i < 22; ++i)
	{
		point x1 = a + (b - a) * ((2 * l + r) / 3 / 100);
		point x2 = a + (b - a) * ((l + 2 * r) / 3 / 100);
		double ax1 = (c - x1) % (c - x1);
		double ax2 = (c - x2) % (c - x2);
		if (ax1 > ax2)
		{
			r = (l + 2 * r) / 3;
		}
		else
		{
			l = (2 * l + r) / 3;
		}
		best = max(best, max(ax1, ax2));
	}
	return sqrt(best);
}

bool solve(int n, int m, point arr1[], point arr2[], point p, point q)
{
	for (int i = 0; i < n; ++i)
	{
		point c = q - p + arr1[i];
		double r = sqrt((q - p) % (q - p));
		for (int j = 0; j < m; ++j)
		{
			double mn = get_min(arr2[j], arr2[j + 1], c);
			double mx = get_max(arr2[j], arr2[j + 1], c);
			if (mn < r + eps && r - eps < mx)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%lf%lf", &p.x, &p.y);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf%lf", &arr1[i].x, &arr1[i].y);
	}
	arr1[n] = arr1[0];

	scanf("%lf%lf", &q.x, &q.y);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%lf%lf", &arr2[i].x, &arr2[i].y);
	}
	arr2[m] = arr2[0];
	
	if (!solve(n, m, arr1, arr2, p, q) && !solve(m, n, arr2, arr1, q, p))
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}

	return 0;
}