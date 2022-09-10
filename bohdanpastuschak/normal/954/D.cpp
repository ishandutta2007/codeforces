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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1007;

int n;
int m;
int start;
int finish;
VI g[MAX];
char used[MAX];
char ye[MAX][MAX];
int d[MAX];
int ds[MAX];
int df[MAX];

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	used[v] = 1;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (auto i : g[t])
			if (used[i] == 0)
			{
				d[i] = d[t] + 1;
				q.push(i);
				used[i] = 1;
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n >> m >> start >> finish;
	int u, v;
	FOR(i, 0, m)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		ye[u][v] = ye[v][u] =  1;
	}

	bfs(start);
	FOR(i, 0, MAX)
		ds[i] = d[i];

	FILL(d, 0);
	FILL(used, 0);
	bfs(finish);
	FOR(i, 0, MAX)
		df[i] = d[i];
	
	int st = df[start];
	int ans = 0;
	FOR(i, 1, n + 1)
		FOR(j, i + 1, n + 1)
	{
		if (ye[i][j])
			continue;

		u = df[i] + ds[j];
		if (u + 1 < st)
			continue;

		u = ds[i] + df[j];
		if (u + 1 < st)
			continue;
		
		++ans;
	}

	cout << ans;
	cin >> n;
	return 0;
}