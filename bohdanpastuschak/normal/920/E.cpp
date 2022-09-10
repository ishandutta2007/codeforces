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
typedef unsigned long long LL;
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
const LD EPS = 1e-9;
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e15;
const LL MAX = 3e5 + 7;
const LL MAXN = 1e6 + 1;

int n;
int m;
vector<set<int>> g;
set<int> unused;
VI ans;
int cnt = 0;

void dfs(int v)
{
	unused.erase(v);
	++cnt;

	int go = -1;
	while (1)
	{
		auto it = unused.upper_bound(go);
		if (it == unused.end())
			return;

		go = *it;
		if (!g[v].count(go))
			dfs(go);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	int u, v;
	g.resize(n);
	FOR(i, 0, m)
	{
		cin >> u >> v;
		--u; --v;
		g[v].insert(u);
		g[u].insert(v);
	}

	FOR(i, 0, n)
		unused.insert(i);

	FOR(i, 0, n)
	{
		if (unused.count(i))
		{
			dfs(i);
			ans.push_back(cnt);
			cnt = 0;
		}
	}


	sort(ALL(ans));
	cout << SZ(ans) << endl;
	for (auto i : ans)
		cout << i << " ";

	cin >> n;
	return 0;
}