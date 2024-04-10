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
#include <cstring>
#include <stdio.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, int> PLL;
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
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const int MAXN = 507;


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	LD r1, x1, y1, x2, y2, x3, y3, r3;
	cin >> r1 >> x1 >> y1 >> x2 >> y2;
	LD d = r1 - sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	LD a;
	if (d <= 0)
	{
		x3 = x1;
		y3 = y1;
		r3 = r1;
		goto ANS;
	}

	if (abs(r1 - d) < EPS)
	{
		x3 = x1 + r1/2.0;
		y3 = y1;
		r3 = r1/2.0;
		goto ANS;
	}

	r3 = r1 - d / 2.0;
	x3 = (x1*r3 - x2 * (r3 + d - r1)) / (r1 - d);
	y3 = (y1*r3 - y2 * (r3 + d - r1)) / (r1 - d);



ANS:
	cout << fixed << setprecision(10) << x3 << " " << y3 << " " << r3;
	cin >> r1;
	return 0;
}