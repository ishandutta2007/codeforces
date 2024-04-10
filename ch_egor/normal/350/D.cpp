#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define x1 ___x1
#define y1 ___y1
#define x first
#define ft first
#define y second
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int N = 3000 * 100 + 5;
const int M = 2000 + 5;

struct line
{
	int A, B, C;
	line() {}

	line(int a, int b, int c)
	{
		A = a;
		B = b;
		C = c;
	}
};

bool operator < (line a, line b)
{
	if (a.A != b.A)
		return a.A < b.A;

	if (a.B != b.B)
		return a.B < b.B;

	return a.C < b.C;
}

int n, m;
int xF[N], yF[N], xS[N], yS[N];
int xC[M], yC[M], rC[M];
vector < pt > incOrder[N];
vector < pt > decOrder[N];

inline bool read()
{
	if (scanf("%d %d", &n, &m) != 2)
		return false;

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &xF[i], &yF[i], &xS[i], &yS[i]);

		if (mp(xF[i], yF[i]) > mp(xS[i], yS[i]))
			swap(xF[i], xS[i]), swap(yF[i], yS[i]);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &xC[i], &yC[i], &rC[i]);
	}

	return true;
}

inline int gcd(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a == 0 && b == 0)
		return b;
	return __gcd(a, b);
}

inline int dist(int x, int y, int X, int Y)
{
	return sqr(x - X) + sqr(y - Y);
}

line getnorm(int curA, int curB, int curC)
{
	int g = gcd(curA, gcd(curB, curC));

	curA /= g;
	curB /= g;
	curC /= g;

	if (curA != 0)
	{
		int sgn = 1;
		if (curA < 0)
			sgn *= -1;

		curA *= sgn, curB *= sgn, curC *= sgn;
	}
	else
	{
		if (curB == 0)
			throw;
		int sgn = 1;

		if (curB < 0)
			sgn *= -1;

		curA *= sgn, curB *= sgn, curC *= sgn;
	}

	return line(curA, curB, curC);
}

inline void solve()
{
	int tsz = 0;
	map<line, int> toId;
	for (int i = 0; i < n; i++)
	{
		int curA = yF[i] - yS[i];
		int curB = xS[i] - xF[i];
		int curC = xF[i] * yS[i] - xS[i] * yF[i];

		line current = getnorm(curA, curB, curC);
		int idx = -1;
		if (!toId.count(current))
			toId[current] = tsz++;
		idx = toId[current];

		incOrder[idx].push_back(mp(2 * xF[i], 2 * yF[i]));
		decOrder[idx].push_back(mp(2 * xS[i], 2 * yS[i]));
	}
	forn(i, tsz)
	{
		sort(all(incOrder[i]));
		sort(all(decOrder[i]));
	}
	li ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (rC[i] != rC[j])
				continue;

			if (dist(xC[i], yC[i], xC[j], yC[j]) <= 4 * sqr(rC[i]))
				continue;

			pt curBeet = mp(xC[i] + xC[j], yC[i] + yC[j]);
			int curA = xC[i] - xC[j];
			int curB = yC[i] - yC[j];
			int curC = -(curA * (xC[i] + xC[j]) + curB * (yC[i] + yC[j]));

			curA <<= 1;
			curB <<= 1;

			line currentL = getnorm(curA, curB, curC);

			if (!toId.count(currentL))
				continue;

			int current = toId[currentL];

			int curAdd = incOrder[current].size();
			curAdd -= int(incOrder[current].end() - upper_bound(all(incOrder[current]), curBeet));

			vector < pt > ::iterator it = lower_bound(all(decOrder[current]), curBeet);

			if (it != decOrder[current].begin())
			{
				it--;
				curAdd -= (int(it - decOrder[current].begin()) + 1);
			}

			ans += curAdd;
		}
	}

	cout << ans << endl;
}
int main()
{
	//   freopen("input.txt", "rt", stdin);
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;

	assert(read());
	solve();

	return 0;
}