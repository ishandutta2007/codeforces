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
#include <unordered_set>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef double LD;
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
const LL INF = 2e9 + 1;
const LL LINF = 1e12;
const LL MAXN = 2e5 + 1;
const LD EPS = 1e-6;

int n;
int x;

struct e
{
	LL l;
	LL r;
	LL cost;
	void read()
	{
		cin >> l >> r >> cost;
	}
};
vector<e> a;
vector<pair<PLL, PLL>> q;

int cmp(e x, e y)
{
	return x.l < y.l;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> x;
	a.resize(n);
	FOR(i, 0, n)
		a[i].read();

	LL ans = INF;
	FOR(i, 0, n)
	{
		q.push_back(MP(MP(a[i].l, 0), MP(a[i].r, a[i].cost)));
		q.push_back(MP(MP(a[i].r, 1), MP(a[i].l, a[i].cost)));
	}

	sort(ALL(q));
	VLL best(2e5 + 1, INF);
	FOR(i, 0, SZ(q))
	{
		if (!q[i].X.Y)
		{
			int X = q[i].Y.X - q[i].X.X + 1;
			if (X <= x)
				ans = min(ans, q[i].Y.Y + best[x - X]);
		}
		else
		{			
			int X = q[i].X.X - q[i].Y.X + 1;
			best[X] = min(best[X], q[i].Y.Y);
		}
	}

	if (ans == INF)
		ans = -1;

	cout << ans;
	cin >> n;
	return 0;
}