#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <complex>
#include <stdio.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 4e18;
const LL MAXN = 2e5 + 1;
const LD EPS = 1e-9;

struct point
{
	LD x;
	LD y;

	void read()
	{
		cin >> x >> y;
	}

	point operator - (point b) { return { x - b.x, y - b.y }; }
	point operator * (LD mul) { return { x * mul, y * mul }; }
	LD operator * (point b) { return x * b.y - y * b.x; }

	LD dist(point p)
	{
		return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
	}
};

struct L2 {
	point one;
	point two;
	LD dist(point he) {
		return abs((he - one) * (he - two)) / one.dist(two);
	}
};

int dist(int i, int j, int n)
{
	return min(abs(i - j), min(abs(n - i + j), abs(n + i - j)));
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int n;
	cin >> n;
	vector<point> a(n);
	FOR(i, 0, n)
		a[i].read();

	LD ans = LINF;

	FOR(i, 0, n)
		FOR(j, 0, n)
		if (i != j && dist(i, j, n) <= 2)
			FOR(k, 0, n)
			if (k != i && k != j && dist(i, k, n) <= 2)
				ans = min(ans, L2{ a[i], a[j] }.dist(a[k]));

	ans /= 2;
	cout << fixed << setprecision(10) << ans;
	cin >> n;
	return 0;
}