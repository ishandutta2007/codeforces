#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <string.h>
#include <cstdio>
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
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 2097333;

int n, k;
VI g[MAX];
char ye[MAX];
int batya[MAX][21];

inline void dfs(int v, int p)
{
	batya[v][1] = p;
	FOR(i, 2, 21)
		batya[v][i] = batya[batya[v][i - 1]][i - 1];

	for (auto i : g[v])
	{
		if (i == p)
			continue;
		dfs(i, v);
	}
}

inline int get(int v, int len)
{
	RFOR(i, 21, 0)
	{
		if (len & (1 << i))
		{
			v = batya[v][i + 1];
			len ^= (1 << i);
		}
	}

	return v;
}

inline int get(int v)
{
	int L = 0, R = MAX, M;
	while (R - L > 1)
	{
		M = (L + R) >> 1;
		if (ye[get(v, M)] == 1)
			R = M;
		else
			L = M;
	}
	if (ye[get(v, L)] == 1)
		return L;

	return R;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> k;
	int u, v;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (k == n - 1)
	{
		FOR(i, 1, n)
			cout << i << " ";
		cin >> n;
		return 0;
	}

	dfs(n, 0);
	ye[n] = 1;
	ye[0] = 1;

	int she = n - k - 1;
	RFOR(i, n, 1)
	{
		if (!she)
			break;

		int dist = get(i);
		if (dist > she)
			continue;

		she -= dist;
		int t = i;
		while (ye[t] == 0)
		{
			ye[t] = 1;
			t = batya[t][1];
		}
	}

	FOR(i, 1, n + 1)
	{
		if (ye[i] == 0)
			cout << i << " ";
	}

	cin >> n;
	return 0;
}