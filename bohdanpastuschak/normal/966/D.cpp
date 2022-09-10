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

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
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
const LL LINF = 1e13;
const LL mod = 1e9 + 7;
const LL MAX = 3e5 + 47;

int n;
set<int> g[MAX];
char used[MAX];
int d[MAX];
int p[MAX];
VI comp;
VI path;
int ans;
int edges;

int bfs()
{
	FILL(used, 0);
	FILL(p, -1);
	FILL(d, 0);
	queue<int> q;
	q.push(1);
	used[1] = 1;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (auto i : g[t])
		{
			if (used[i])
				continue;
			p[i] = t;
			used[i] = 1;
			q.push(i);
			d[i] = d[t] + 1;
		}
	}

	if (used[n] == 0)
		return INF;

	return d[n];
}

void dfs(int v)
{
	used[v] = 1;
	comp.push_back(v);
	for (auto i : g[v])
	{
		if (used[i] == 0)
			dfs(i);
	}
}

void check(int v)
{
	dfs(v);
	
	int vert = -1;
	for (auto i : comp)
	{
		if (SZ(g[i]) == SZ(comp) - 1)
			continue;

		if (ans <= 5)
			continue;

		vert = i;
		break;
	}

	if (vert == -1)
		return;

	for (auto i : comp)
		used[i] = 0;

	queue<int> q;
	q.push(vert);
	used[vert] = 1;
	d[vert] = 0;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (auto i : g[t])
		{
			if (used[i])
				continue;

			p[i] = t;
			used[i] = 1;
			q.push(i);
			d[i] = d[t] + 1;
		}
	}

	for (auto i : comp)
	{
		if (d[i] != 2)
			continue;

		ans = 5;
		path = { 1, vert, p[i], i, vert, n };
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int m;
	cin >> n >> m;
	int u, v;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}

	ans = bfs();
	if (ans == d[n])
	{
		int curr = n;
		while (curr != 1)
		{
			path.push_back(curr);
			curr = p[curr];
		}

		path.push_back(1);
		reverse(ALL(path));
	}

	FOR(i, 1, n + 1)
	{
		if (d[i] != 2)
			continue;

		if (ans <= 4)
			continue;

		ans = 4;
		path = { 1, p[i], i, 1, n };
	}

	if (ans > 5)
	{
		for (auto i : g[1])
			g[i].erase(1);
		g[1].clear();

		FILL(used, 0);
		FOR(i, 2, n + 1)
		{
			if (d[i] == 1)
			{
				check(i);
				comp.clear();
			}
		}
	}

	if (ans == INF)
	{
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;
	FOR(i, 0, SZ(path))
	{
		if (i)
			cout << " ";
		cout << path[i];
	}

	cin >> n;
	return 0;
}