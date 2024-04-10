/*
Author: Dynamic JQ

Problem: Codeforce 54E - Vacuum Cleaner

Time & Date(start): Mar/4/2018 16:04

Verdict: Coding [the solution is not worked out completely by me]

Tags:
Geometry
Two pointers
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
typedef pair<double, double> point;

double absv(double x)
{
	return x < 0 ? -x : x;
}

double sqrrt(double x)
{
	if(x <= 0.0) return 0.0;
	return sqrt(x);
}

double sqr(double x)
{
	return x * x;
}

double area(point a, point b, point c)
{
	return absv(a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second)) / 2;
}

double dist(point a, point b)
{
	return sqrrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}

double dist(point p, point a, point b)
{
	return area(p, a, b) * 2 / dist(a, b);
}

point rotate(point o, point p)
{
	double d1 = p.first - o.first, d2 = p.second - o.second;
	return MP(o.first + d2, o.second - d1);
}

point midpoint(point a, point b)
{
	return MP((a.first + b.first) / 2, (a.second + b.second) / 2);
}

bool sameside(point a1, point b1, point a2, point b2)
{
	point c2 = midpoint(a2, b2);
	double da = dist(a2, a1, b1), db = dist(b2, a1, b1), dc = dist(c2, a1, b1);
	return absv(da + db - 2 * dc) < EPS;
}


double solve(vector<point> vec)
{
	int n = vec.size();
	rep(i, n) vec.push_back(vec[i]);
	int bp = 1;
	double ans = 1.0 / 0.0;
	double ta = 0.0;
	rep(i, n) {
		if(bp == i) bp ++;
		point da = vec[i], db = rotate(vec[i], vec[i + 1]);
		while(sameside(da, db, vec[bp], vec[bp + 1]) && dist(vec[bp + 1], da, db) > dist(vec[bp], da, db)) {
			ta += area(vec[i], vec[bp], vec[bp + 1]);
			bp ++;
		}
		ans = min(ans, dist(vec[bp], da, db) * sqrrt(sqr(dist(vec[bp], vec[i])) - sqr(dist(vec[bp], da, db))) / 2 - ta);
		ta -= area(vec[bp], vec[i], vec[i + 1]);
	}
	return ans;
}

int main()
{
	int n, x, y;
	vector<point> poly;
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d%d", &x, &y);
		poly.push_back(MP(x, y));
	}
	double ans = solve(poly);
	reverse(poly.begin(), poly.end());
	ans = min(ans, solve(poly));
	printf("%lf\n", ans);
	return 0;
}