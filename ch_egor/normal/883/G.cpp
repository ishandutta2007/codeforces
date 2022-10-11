#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 300 * 1000 + 228;

int n, m, s;
vector<pair<int, int>> g[MAX_N];
char ans[MAX_N];
bool used[MAX_N];

int dfs1(int v)
{
	used[v] = true;
	int ans = 1;
	for (int i = 0; i < (int)g[v].size(); ++i)
	{
		int to = g[v][i].first;
		if (!used[to])
		{
			if (g[v][i].second != INF)
			{
				::ans[abs(g[v][i].second) - 1] = g[v][i].second > 0 ? '+' : '-';
			}
			ans += dfs1(to);
		}
	}

	return ans;
}

int dfs2(int v)
{
	used[v] = true;
	int ans = 1;
	for (int i = 0; i < (int)g[v].size(); ++i)
	{
		int to = g[v][i].first;
		if (!used[to])
		{
			if (g[v][i].second != INF)
			{
				::ans[abs(g[v][i].second) - 1] = g[v][i].second > 0 ? '-' : '+';
			}
			else
			{
				ans += dfs2(to);
			}
		}
	}

	return ans;
}
int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d%d%d", &n, &m, &s);
	--s;
	int cnt = 1;
	for (int i = 0; i < m; ++i)
	{
		int v, u, t;
		scanf("%d%d%d", &t, &v, &u);
		--v; --u;
		if (t == 1)
		{
			g[v].push_back({u, INF});
		}
		else
		{
			g[v].push_back({u, cnt});
			g[u].push_back({v, -cnt});
			++cnt;
		}
	}
	--cnt;
	memset(ans, '-', sizeof(ans));
	ans[cnt] = 0;
	memset(used, 0, sizeof(used));
	printf("%d\n", dfs1(s));
	printf("%s\n", ans);
	memset(used, 0, sizeof(used));
	printf("%d\n", dfs2(s));
	printf("%s\n", ans);

	return 0;
}