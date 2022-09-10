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
int k;
LL ans = 0;
VVI g;
VCH used;
VVI cnt;
VI t;

void dfs(int v)
{
	used[v] = 1;
	cnt[v][0] = 1;
	for (auto i : g[v])
		if (used[i] == 0)
		{
			dfs(i);
			FOR(j, 1, k + 1)
				cnt[v][j] += cnt[i][j - 1];
		}

	t.assign(k + 1, 0);
	for (auto i : g[v])
	{
		FOR(j, 1, k)
			ans += cnt[i][j - 1] * 1LL * t[k - j];

		FOR(j, 1, k)
			t[j] += cnt[i][j - 1];

		ans += cnt[i][k - 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	cin >> n >> k;
	g.resize(n);
	int u, v;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	used.assign(n, 0);
	cnt.assign(n, VI(k + 1, 0));
	dfs(0);
	ans /= 2LL;
	cout << ans;
	cin >> n;
	return 0;
}