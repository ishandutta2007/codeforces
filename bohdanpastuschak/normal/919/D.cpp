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

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL MAX = 300;
const LL MAXN = 500001;
const LD EPS = 1e-9;

int n;
int m;
VVI g;
string s;

void bad()
{
	cout << -1;
	exit(0);
}

VCH used;

void dfs(int v)
{
	used[v] = 1;
	for (auto i : g[v])
		if (used[i] == 0)
			dfs(i);
		else
			if (used[i] == 1)
				bad();

	used[v] = 2;
}

int DP[MAXN][26];

void dfs2(int v)
{
	used[v] = 1;
	for (auto i : g[v])
	{
		if (used[i] == 0)
			dfs2(i);

		FOR(j, 0, 26)
			DP[v][j] = max(DP[v][j], DP[i][j]);
	}

	DP[v][s[v] - 'a']++;
	used[v] = 2;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	cin >> s;
	int u, v;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
	}

	used.assign(n, 0);
	FOR(i, 0, n)
		if (used[i] == 0)
			dfs(i);

	used.assign(n, 0);
	FOR(i, 0, n)
		if (used[i] == 0)
			dfs2(i);

	int ans = 0;
	FOR(i, 0, n)
		FOR(j, 0, 26)
		ans = max(ans, DP[i][j]);

	cout << ans;
	cin >> n;	
	return 0;
}