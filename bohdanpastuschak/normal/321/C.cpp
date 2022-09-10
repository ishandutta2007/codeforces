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
#include <bitset>
#include <complex>
#include <cassert>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<LD> VLD;
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
const LL INF = 1e9 + 47;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1e5 + 47;

int n;
VI g[MAX];
int sz[MAX];
char used[MAX];

void dfs(int v, int p)
{
	sz[v] = 1;
	for (auto i : g[v])
		if (i != p && used[i] == 0)
			dfs(i, v), sz[v] += sz[i];
}

void go(int v, char level, int par)
{
	dfs(v, par);
	int p = -1;
	int w;
	int all = sz[v];

	while (1)
	{
		w = -1;
		for (auto i : g[v])
			if (used[i] == 0 && i != p && sz[i] * 2 > all)
				w = i;

		if (w == -1)
			break;
	
		p = v;
		v = w;
	}

	used[v] = level;
	for (auto i : g[v])
		if (used[i] == 0)
			go(i, level + 1, v);
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
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0, -1);
	go(0, 'A', -1);
	FOR(i, 0, n)
	{
		if (i)
			cout << " ";
		cout << used[i];
	}

	return 0;
}