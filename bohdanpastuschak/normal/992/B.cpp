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
const LL MAX = 1e5 + 47;

LL l, r, x, y;

LL gcd(LL a, LL b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);	

	cin >> l >> r >> x >> y;	
	int ans = 0;

	LL val = x * y;

	if (x == y)
	{
		if (l <= x && x <= r)
			++ans;

		cout << ans << endl;
		return 0;
	}

	VI d;
	for (int i = 1; i * i <= y; ++i)
	{
		if (y % i)
			continue;

		d.push_back(i);
		if (i*i < y)
			d.push_back(y / i);
	}

	sort(ALL(d));
	for (auto i : d)
	{
		if (i < l || i > r)
			continue;

		LL sh = val / i;

		if (sh < l || sh > r)
			continue;

		if (gcd(i, sh) != x)
			continue;

		++ans;
	}

	cout << ans << endl;
	cin >> l;	
	return 0;
}