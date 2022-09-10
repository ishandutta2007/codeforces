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

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1000000007;
const LL MAXN = 1e5 + 7;

int n;
int m;
int h;
int a[MAXN];
VI g[MAXN];
VI gr[MAXN];
VCH used;
VI comp;
VVI all;
VI order;
int color[MAXN];
int cnt_color[MAXN];
VPII e;
int timer = 0;

vector<set<int>> graph;

void dfs1(int v)
{
	used[v] = 1;
	for (auto i : g[v])
		if (used[i] == 0)
			dfs1(i);

	order.push_back(v);
}

void dfs2(int v)
{
	used[v] = 1;
	comp.push_back(v);
	for (auto i : gr[v])
		if (used[i] == 0)
			dfs2(i);
}

void find()
{
	used.assign(n, 0);
	FOR(i, 0, n)
		if (used[i] == 0)
			dfs1(i);

	used.assign(n, 0);
	FOR(i, 0, n)
	{
		int v = order[n - 1 - i];
		if (used[v] == 0)
		{
			dfs2(v);
			for (auto j : comp)
				color[j] = timer;

			++timer;
			all.push_back(comp);
			comp.clear();
		}
	}
}

void shukaj(int v)
{
	used[v] = 1;
	for (auto i : g[v])
		if (used[i] == 0)
			shukaj(i);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> m >> h;
	FOR(i, 0, n)
		cin >> a[i];

	int u, v;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		--u;
		--v;

		if ((a[u] + 1) % h == a[v])
		{
			g[u].push_back(v);
			e.push_back(MP(u, v));
			gr[v].PB(u);
		}

		if ((a[v] + 1) % h == a[u])
		{
			g[v].push_back(u);
			e.push_back(MP(v, u));
			gr[u].PB(v);
		}
	}

	timer = 1;
	find();
	graph.resize(timer);
	FOR(i, 0, n)
		cnt_color[color[i]]++;

	for (auto i : e)
	{
		u = i.X;
		v = i.Y;
		if (color[u] != color[v])
			graph[color[u]].insert(color[v]);
	}

	int ans = n;
	int best = 1;
	FOR(i, 1, timer)
		if (SZ(all[i - 1]) < ans && graph[i].size() == 0)
		{
			ans = SZ(all[i - 1]);
			best = i;
		}

	cout << ans << endl;
	used.assign(n, 0);
	int start = all[best - 1][0];
	shukaj(start);
	FOR(i, 0, n)
		if (used[i])
			cout << i + 1 << " ";

	cin >> n;
	return 0;
}