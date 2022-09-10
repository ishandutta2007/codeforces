#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <string.h>
#include <cstdio>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1e6 + 47;

struct pt
{
	int x;
	int y;
	void read()
	{
		cin >> x >> y;
	}
};

inline int area(pt a, pt b, pt c) 
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1(int a, int b, int c, int d) 
{
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return max(a, c) <= min(b, d);
}

bool intersect(pt a, pt b, pt c, pt d) 
{
	return intersect_1(a.x, b.x, c.x, d.x)
		&& intersect_1(a.y, b.y, c.y, d.y)
		&& area(a, b, c) * area(a, b, d) <= 0
		&& area(c, d, a) * area(c, d, b) <= 0;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("In.txt", "r", stdin);

	vector<pt> a(4), b(4);
	FOR(i, 0, 4)
		a[i].read();
	FOR(i, 0, 4)
		b[i].read();

	a.push_back(a[0]);
	b.push_back(b[0]);
	bool ok = 0;
	FOR(i, 0, 4)
		FOR(j, 0, 4)
			ok |= intersect(a[i], a[i + 1], b[j], b[j + 1]);

	int left, right, up, down;
	left = right= a[0].x;
	up = down = a[0].y;

	FOR(i, 1, 4)
	{
		left = min(left, a[i].x);
		right = max(right, a[i].x);

		up = max(up, a[i].y);
		down = min(down, a[i].y);
	}

	FOR(i, 0, 4)
		ok |= (b[i].x >= left && b[i].x <= right && b[i].y >= down && b[i].y <= up);
	
	left = right = b[0].x;
	up = down = b[0].y;

	FOR(i, 1, 4)
	{
		left = min(left, b[i].x);
		right = max(right, b[i].x);

		up = max(up, b[i].y);
		down = min(down, b[i].y);
	}

	pt x = a[0];
	int suma = abs(area(b[0], b[1], b[2])) + abs(area(b[1], b[2], b[3]));
	int tuta = 0;
	FOR(i, 0, 4)
		tuta += abs(area(x, b[i], b[i + 1]));

	ok |= suma == tuta;

	if (ok)
		cout << "Yes";
	else
		cout << "No";
	a[0].read();
	return 0;
}