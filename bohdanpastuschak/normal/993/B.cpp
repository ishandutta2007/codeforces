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
const LL MAX = 20;

int n, m;
PII a[MAX];
PII b[MAX];

PII get(PII x, PII y)
{
	set<int> s;
	s.insert(x.X);
	s.insert(x.Y);
	s.insert(y.X);
	s.insert(y.Y);
	if (SZ(s) != 3)
		return MP(SZ(s), -1);

	int w;
	if (x.X == y.X || x.X == y.Y)
		w = x.X;
	else
		w = x.Y;

	return MP(3, w);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i].X >> a[i].Y;
	FOR(i, 0, m)
		cin >> b[i].X >> b[i].Y;

	set<int> maybe;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (get(a[i], b[j]).X != 3)
				continue;

			set<int> pe, dr;
			FOR(k, 0, m)
			{
				PII tut = get(a[i], b[k]);
				if (tut.X != 3)
					continue;

				pe.insert(tut.Y);
			}

			FOR(k, 0, n)
			{
				PII tut = get(a[k], b[j]);
				if (tut.X != 3)
					continue;

				dr.insert(tut.Y);
			}			

			if (SZ(pe) > 1 || SZ(dr) > 1)
			{
				cout << -1 << endl;
				return 0;
			}

			if (a[i].X == b[j].X || a[i].X == b[j].Y)
				maybe.insert(a[i].X);
			else
				maybe.insert(a[i].Y);
		}
	}

	if (SZ(maybe) == 1)
		cout << *maybe.begin();
	else
		cout << 0;

	cin >> n;
	return 0;
}