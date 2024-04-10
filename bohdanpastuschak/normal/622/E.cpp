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
#include <unordered_map>
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
#define SZ(a) (LL)((a).size())

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e9;
const LL MAX = 2e5 + 7;
const LL MAXN = 5e5 + 1;

int n;
VI g[MAXN];
int lvl[MAXN];
int a[MAXN];
int t[MAXN];
int cnt;

inline void dfs(int v, int p = 0, int depth = 0)
{
	if (SZ(g[v]) == 1)
		a[cnt++] = depth;

	for (auto i : g[v])
		if (i != p)
			 dfs(i, v, depth + 1);
}

int solve(int v)
{
	cnt = 0;
	dfs(v);
	sort(a, a + cnt);
	t[0] = a[0];
	FOR(i, 1, cnt)
		t[i] = max(a[i], t[i - 1] + 1);

	return t[cnt - 1];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	int u, v;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		--v; --u;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int res = 0;

	for (auto i : g[0])
		res = max(res, solve(i));

	++res;
	cout << res;
	cin >> n;
	return 0;
}