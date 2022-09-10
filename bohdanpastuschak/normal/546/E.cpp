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
typedef vector<PII> VPII;
typedef vector<VI> VVI;
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
const LL INF = 1e18;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1 << 8;

int n, m;
int a[MAX];
int b[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
bool used[MAX];

bool dfs(int v)
{
	if (v == 2 * n + 1)
		return 1;
	
	used[v] = 1;
	FOR(i, 0, 2 * n + 2)
	{
		if (used[i])
			continue;
		if (f[v][i] == c[v][i])
			continue;

		if (dfs(i))
		{
			f[v][i]++;
			f[i][v]--;
			return 1;
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> m;
	FOR(i, 1, n + 1)
		cin >> a[i];
	FOR(i, 1, n + 1)
		cin >> b[i];
	
	int u, v;
	FOR(i, 1, n + 1)
		c[i][i + n] = MAX;

	FOR(i, 0, m)
	{
		cin >> u >> v;
		c[u][v + n] = c[v][u + n] = MAX;
	}

	FOR(i, 1, n + 1)
		c[0][i] = c[i][0] = a[i];
	FOR(i, 1, n + 1)
		c[n * 2 + 1][i + n] = c[i + n][n * 2 + 1] = b[i];

	int should = 0;
	FOR(i, 1, n + 1)
		should += a[i];
	int wtf = 0;
	FOR(i, 1, n + 1)
		wtf += b[i];
	
	int ye = 0;
	while (dfs(0))
	{
		FILL(used, 0);
		++ye;
	}

	if (ye != should || ye != wtf)
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	FOR(i, 1, n + 1)
	{
		FOR(j, 1, n + 1)
			cout << f[i][j + n] << " ";
		cout << endl;
	}

	return 0;
}