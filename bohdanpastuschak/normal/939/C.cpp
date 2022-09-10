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

typedef double LD;
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
const LL MAXN = 1e5 + 7;

LL t[4 * MAXN];

void update(int v, int tl, int tr, int l, int r, LL add)
{
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] += add;
	else
	{
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(r, tm), add);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
	}
}

LL get(int v, int tl, int tr, int pos)
{
	if (tl == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return t[v] + get(v * 2, tl, tm, pos);
	else
		return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	LL n;
	cin >> n;
	VLL a(n + 1);
	FOR(i, 0, n)
		cin >> a[i + 1];

	LL s, f;
	cin >> s >> f;

	FOR(i, 1, n + 1)
	{
		PII prom(s + 1 - i, f - i);
		if (prom.X <= 0)
			prom.X += n;
		if (prom.Y <= 0)
			prom.Y += n;

		if (prom.X <= prom.Y)
			update(1, 1, n, prom.X, prom.Y, a[i]);
		else
		{
			update(1, 1, n, prom.X, n, a[i]);
			update(1, 1, n, 1, prom.Y, a[i]);
		}
	}

	int ans = 1;
	LL now;
	LL ye = get(1, 1, n, 1);
	FOR(i, 2, n + 1)
	{
		now = get(1, 1, n, i);
		if (now > ye)
		{
			ye = now;
			ans = i;
		}
	}

	cout << ans;
	cin >> n;
	return 0;
}