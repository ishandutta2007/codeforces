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
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 123456789;
const LL MAX = 1e5 + 47;

int n;
VPLL g[MAX];
LL DP[MAX];
LL DP2[MAX];

void dfs(int v, int p = -1)
{
	if (SZ(g[v]) == 1 && v)
		return;

	for (auto i : g[v])
	{
		if (i.X == p)
			continue;

		dfs(i.X, v);
		DP[v] += DP[i.X] + 2 * i.Y;
	}

	int best = -1;
	FOR(i, 0, SZ(g[v]))
	{
		if (g[v][i].X == p)
			continue;

		if (best == -1)
			best = i;
		else
		{
			if (DP[g[v][i].X] - DP2[g[v][i].X] + g[v][i].Y > DP[g[v][best].X] - DP2[g[v][best].X] + g[v][best].Y)
				best = i;
		}
	}

	DP2[v] = DP[v] - (DP[g[v][best].X] - DP2[g[v][best].X] + g[v][best].Y);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	LL u, v, w;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v >> w;
		--u; --v;
		g[u].push_back(MP(v, w));
		g[v].push_back(MP(u, w));
	}

	dfs(0);
	cout << DP2[0];
	cin >> n;
	return 0;
}