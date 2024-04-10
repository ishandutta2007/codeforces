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
#include <bitset>
#include <complex>
#include <cassert>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
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
const LL LINF = 1e13;
const LL mod = 1e9 + 7;
const LL MAX = 1e5 + 47;

int n, m, cl, ce, v;
VI dr;
VI lift;

int solve(PII x, PII y)
{
    if (x.X == y.X)
        return abs(x.Y - y.Y);
	int ans = INF;
	int curr = 0;

	auto it = lower_bound(ALL(dr), x.Y);
	if (it != dr.end())
	{
		curr = abs(*it - x.Y) + abs(x.X - y.X);
		curr += abs(*it - y.Y);
		ans = min(ans, curr);
	}

	if (it != dr.begin())
	{
		--it;

		curr = abs(*it - x.Y) + abs(x.X - y.X);
		curr += abs(*it - y.Y);
		ans = min(ans, curr);
	}

	it = lower_bound(ALL(lift), x.Y);
	if (it != lift.end())
	{
		curr = abs(*it - x.Y) + (abs(x.X - y.X) + v - 1) / v;
		curr += abs(*it - y.Y);
		ans = min(ans, curr);
	}

	if (it != lift.begin())
	{
		--it;

		curr = abs(*it - x.Y) + (abs(x.X - y.X) + v - 1) / v;
		curr += abs(*it - y.Y);
		ans = min(ans, curr);
	}


	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> m >> cl >> ce >> v;
	dr.resize(cl);
	lift.resize(ce);
	FOR(i, 0, cl)
		cin >> dr[i];
	FOR(i, 0, ce)
		cin >> lift[i];

	sort(ALL(dr));
	sort(ALL(lift));

	int q;
	cin >> q;
	PII x, y;
	REP(Q, q)
	{
		cin >> x.X >> x.Y >> y.X >> y.Y;
		cout << solve(x, y) << endl;
	}

	
	return 0;
}