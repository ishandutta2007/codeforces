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
const LL INF = 1e6;
const LL LINF = 1e12;
const LL MAXN = 2e5 + 1;
const LD EPS = 1e-6;

int n;
VI g[MAXN];
int a[MAXN];
int ans[MAXN];
int hel[MAXN];
int dist[MAXN];

inline int gcd(int x, int y)
{
	if (!y)
		return x;
	return gcd(y, x%y);
}

inline VI div(int x)
{
	VI res;
	for (int i = 1; i*i <= x; ++i)
		if (x%i == 0)
		{
			res.push_back(i);
			if (i*i < x)
				res.push_back(x / i);
		}
	sort(ALL(res));
	return res;
}

VI D;
VVI res;

inline void dfs2(int v, int par = -1)
{
	if (v)
	{
		FOR(i, 0, SZ(D))
			res[v][i] = res[par][i] + (a[v] % D[i] == 0);
	}
	else
	{
		FOR(i, 0, SZ(D))
			res[v][i] = (a[v] % D[i] == 0);
	}

	FOR(x, 0, SZ(g[v]))
		if (par != g[v][x])
			dfs2(g[v][x], v);
}

inline void dfs(int v, int all, int p = -1)
{
	if (v)
		all = gcd(all, a[v]), ans[v] = all;

	FOR(x, 0, SZ(g[v]))
		if (p != g[v][x])
			dist[g[v][x]] = dist[v] + 1, dfs(g[v][x], all, v);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n;
	int u, v;
	FOR(i, 0, n)
		cin >> a[i];

	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	ans[0] = a[0];
	dfs(0, 0);

	D = div(a[0]);
	res.assign(n, VI(SZ(D), 0));
	
	dfs2(0);
	FOR(i, 1, n)
		RFOR(j, SZ(D), 0)
		if (res[i][j] >= dist[i])
		{
			ans[i] = max(ans[i], D[j]);
			break;
		}

	FOR(i, 0, n)
		cout << ans[i] << " ";

	cin >> n;
	return 0;
}