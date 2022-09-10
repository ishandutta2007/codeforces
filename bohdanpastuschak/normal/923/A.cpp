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
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
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
const LL mod = 1000000007;
const LL MAXN = 1e6 + 7;

int sieve[MAXN];

VI get(int x)
{
	VI res;
	int t;
	while (x > 1)
	{
		t = sieve[x];
		if (x%t == 0)
			x /= t;

		res.push_back(t);
	}

	return res;
}

int a, b, c;

int get_min(int x)
{
	if (sieve[x] == x)
		return MAXN;

	int realx = x;
	VI vec;
	int t;
	while (x > 1)
	{
		t = sieve[x];
		if (x%t == 0)
			x /= t;

		vec.push_back(t);
	}
	x = realx;

	int res = x;

	for (auto i : vec)
	{
		int b = x - i + 1;
		res = min(res, 1 + max(i, x - i));
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	FOR(i, 0, MAXN)
		sieve[i] = i;

	FOR(i, 2, MAXN)
		if (sieve[i] == i)
		{
			for (LL j = i * 1LL * i; j < MAXN; j += i)
				if (sieve[j] == j)
					sieve[j] = i;
		}

	cin >> c;
	VI x = get(c);

	int res = c + 1;
	int start = c;

	for (auto p : x)
	{
		int b = c - p + 1;
		b = max(b, p + 1);
		start = min(start, b);
	}

	FOR(i, start, c + 1)
		res = min(res, get_min(i));

	cout << res;
	cin >> c;
	return 0;
}