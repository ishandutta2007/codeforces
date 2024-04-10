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
const LL MAX = 1 << 17;

int n;
VI g[MAX];
int d[MAX];

void bad()
{
	cout << "No" << endl;
	exit(0);
}

void dfs(int v, int p)
{
	for (auto i : g[v])
	{
		if (i == p)
			continue;

		d[i] = d[v] + 1;
		dfs(i, v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	int u, v;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int cnt = 0;
	FOR(i, 1, n + 1)
		if (SZ(g[i]) > 2)
			++cnt;

	if (cnt > 1)
		bad();

	if (cnt == 0)
	{
		u = v = -1;
		FOR(i, 1, n + 1)
		{
			if (SZ(g[i]) != 1)
				continue;

			if (u == -1)
				u = i;
			else
				v = i;
		}

		cout << "Yes" << endl;
		cout << 1 << endl;
		cout << u << " " << v << endl;
		return 0;
	}

	FOR(i, 1, n + 1)
		if (SZ(g[i]) > 2)
			u = i;

	dfs(u, -1);
	LL total = 0;
	FOR(i, 1, n + 1)
		if (SZ(g[i]) == 1)
			total += d[i];

	if (total >= n)
		bad();

	cout << "Yes" << endl;
	cnt = 0;
	FOR(i, 1, n + 1)
		if (SZ(g[i]) == 1)
			++cnt;

	cout << cnt << endl;
	FOR(i, 1, n + 1)
	{
		if (SZ(g[i]) > 1)
			continue;

		cout << u << " " << i << endl;
	}

	cin >> n;
	return 0;
}