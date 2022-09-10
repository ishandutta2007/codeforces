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

typedef long double LD;
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
const LL MAXN = 2e5 + 1;

int n;
int m;
VVI g;
VVI h;
VCH used_g;
VCH used_h;

void dfs(int v, int type = 0)
{
	if (type)
	{
		used_h[v] = 1;
		for (auto i : h[v])
			if (used_g[i] == 0)
				dfs(i, 0);
	}
	else
	{
		used_g[v] = 1;
		for (auto i : g[v])
			if (used_h[i] == 0)
				dfs(i, 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	h.resize(m);
	used_g.assign(n, 0);
	used_h.assign(m, 0);
	int k, x;
	FOR(i, 0, n)
	{
		cin >> k;
		FOR(j, 0, k)
		{
			cin >> x;
			--x;
			g[i].push_back(x);
			h[x].push_back(i);
		}
	}

	int counter = 0;
	FOR(i, 0, n)
		counter += SZ(g[i]);

	if (!counter)
	{
		cout << n;
		return 0;
	}

	counter = 0;
	FOR(i,0,n)
		if (used_g[i] == 0)
		{
			++counter;
			dfs(i);
		}

	cout << counter - 1;
	return 0;
}