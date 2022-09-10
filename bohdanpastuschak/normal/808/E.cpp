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
const LL INF = 1e18;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1 << 8;

int n, m;
VI a, b, c;
VLL x, y, z;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> m;
	int u, v;
	FOR(i, 0, n)
	{
		cin >> u >> v;
		if (u == 3)
			a.push_back(v);
		if (u == 2)
			b.push_back(v);
		if (u == 1)
			c.push_back(v);
	}

	sort(ALL(a));
	sort(ALL(b));
	sort(ALL(c));
	reverse(ALL(a));
	reverse(ALL(b));
	reverse(ALL(c));

	x.resize(SZ(a) + 1);
	y.resize(SZ(b) + 1);
	z.resize(SZ(c) + 1);

	FOR(i, 1, SZ(a) + 1)
		x[i] = x[i - 1] + a[i - 1];
	

	FOR(i, 1, SZ(b) + 1)
		y[i] = y[i - 1] + b[i - 1];
	

	FOR(i, 1, SZ(c) + 1)
		z[i] = z[i - 1] + c[i - 1];
	

	LL ans = 0;

	FOR(i, 0, SZ(a) + 1)
	{
		if (i * 3 > m)
			break;

		LL tut = x[i];
		int she = m - i * 3;

		LL best = 0;
		int L = 0, R = she >> 1, M1, M2;
		while (R - L > 2)
		{
			M1 = L + (R - L) / 3;
			M2 = R - (R - L) / 3;

			LL v1, v2;
			v1 = y[min(SZ(y) - 1, M1)] + z[min(SZ(z) - 1, (she - 2 * M1))];
			v2 = y[min(SZ(y) - 1, M2)] + z[min(SZ(z) - 1, (she - 2 * M2))];
			
			best = max(v1, v2);
			if (v1 > v2)
				R = M2;
			else
				L = M1;
		}

		FOR(j, L, R + 1)
			best = max(best, y[min(SZ(y) - 1, j)] + z[min(SZ(z) - 1, (she - 2 * j))]);

		ans = max(ans, tut + best);
	}

	cout << ans << endl;
	cin >> n;
	return 0;
}