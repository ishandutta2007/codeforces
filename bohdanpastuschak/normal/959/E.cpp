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

#define FOR(i, a, b) for(LL i = (a); i < (b); ++i)
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

vector<pair<LL, PII>> e;

int p[MAX];

int find(int v)
{
	if (v == p[v])
		return v;
	return p[v] = find(p[v]);
}

void unite(int i, int j)
{
	i = find(i);
	j = find(j);
	if (i != j)
		p[j] = i;
}

void brute()
{
	int N;
	cin >> N;
	FOR(n, 2, N + 1)
	{
		e.clear();
		FOR(i, 0, n)
			FOR(j, i + 1, n)
			e.push_back(MP(i^j, MP(i, j)));

		FOR(i, 0, n)
			p[i] = i;

		LL ans = 0;
		sort(ALL(e));
		FOR(i, 0, SZ(e))
		{
			int x = e[i].Y.X;
			int y = e[i].Y.Y;
			if (find(x) != find(y))
			{
				unite(x, y);
				ans += e[i].X;
			}
		}

		cout << ans << endl;
	}

	cin >> N;
}

LL get(LL n)
{
	if (n == 1)
		return 1;

	if (n & 1)
		return 2 * get(n / 2) + n / 2 + 1;
	else
		return 2 * get(n / 2) + n / 2;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	LL n;
	cin >> n;
	cout << get(n - 1) << endl;
	cin >> n;	
	return 0;
}