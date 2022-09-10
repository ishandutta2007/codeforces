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
const int MAX = 1 << 19;

int n, x, y;
VI g[MAX];
char used[MAX];
int cnt[MAX];
int p[MAX];

void dfs(int v)
{
	used[v] = 1;
	cnt[v] = 1;
	for (auto i : g[v])
	{
		if (used[i])
			continue;

		p[i] = v;
		dfs(i);
		cnt[v] += cnt[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> x >> y;
	--x; --y;
	swap(x, y);
	int u, v;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	LL ans = n * 1LL * (n - 1);

	dfs(y);
	LL val = cnt[x];
	LL she = 0;
	int t = x;
	while (p[t] != y)
		t = p[t];

	she = n - cnt[t];
	
	ans -= she * val;
	cout << ans << endl;
	cin >> n;
	return 0;
}