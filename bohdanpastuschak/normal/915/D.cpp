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
const LL MAXN = 4e6 + 1;
const LL MAXS = 100 + 1;
const LL MAXT = 100 + 1;

int n;
int m;
VVI g;
VCH used;
VI p;

set<PII> E;

bool OK = 0;
bool IS;
void dfs2(int v)
{
	used[v] = 1;
	for (auto i : g[v])
		if (used[i] == 0)
			dfs2(i);
		else
			if (used[i] == 1)
				IS = 1;
	used[v] = 2;
}

void dfs(int v)
{
	if (OK)
		return;
	used[v] = 1;
	for (auto i : g[v])
	{
		if (OK)
			return;

		if (used[i] == 0)
			p[i] = v, dfs(i);
		else
			if (used[i] == 1)
			{
				int now = v;
				E.insert(MP(v, i));
				do
				{
					E.insert(MP(p[now], now));
					now = p[now];
				} while (now != i);
				OK = 1;
				return;
			}
	}

	used[v] = 2;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	int u, v;
	VPII e;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		--u; --v;
		e.push_back(MP(u, v));
		g[u].push_back(v);
	}

	used.assign(n, 0);
	p.assign(n, -1);

	FOR(i,0,n)
		if (used[i] == 0)
			dfs(i);

	if (SZ(E))
	{
		for (auto i : E)
		{
			g.assign(n, VI());
			for (auto j : e)
				if (j != i)
					g[j.X].push_back(j.Y);

			IS = 0;
			used.assign(n, 0);
			FOR(i, 0, n)
				if (used[i] == 0)
					dfs2(i);
			if (!IS)
			{
				cout << "YES";
				return 0;
			}
		}

		cout << "NO";
	}
	else
		cout << "YES";


	return 0;
}