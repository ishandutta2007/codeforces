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
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

#define FOR(i,a,b) for(LL i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(LL i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL MAXN = 1e5 + 1;
const LD EPS = 1e-6;

int n;
VVI g;
VI a;
VCH used;

bool dfs(int v, int cl)
{
	used[v] = 1;
	if (a[v] != cl)
		return 0;
	
	for (auto i : g[v])
		if (used[i] == 0)
		{
			if (!dfs(i, cl))
				return 0;
		}

	return 1;
}

bool check(int v)
{
	used.assign(n, 0);
	used[v] = 1;
	for(auto i: g[v])
		if (used[i] == 0)
			if (!dfs(i, a[i]))
				return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	a.resize(n);
	g.resize(n);
	int u, v;
	VPII e;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		--u; --v;
		e.push_back(MP(u, v));
		g[u].push_back(v);
		g[v].push_back(u);
	}

	FOR(i, 0, n)
		cin >> a[i];
	

	FOR(i, 0, SZ(e))
	{
		if (a[e[i].X] != a[e[i].Y])
		{
			if (check(e[i].X))
				cout << "YES" << endl << e[i].X + 1;
			else
				if (check(e[i].Y))
					cout << "YES" << endl << e[i].Y + 1;
				else
					cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl << 1;

	return 0;
}