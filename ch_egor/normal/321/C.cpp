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

const int MAX_N = 1000 * 100 + 5;

int n;
vector<int> g[MAX_N];
int p[MAX_N];
int sz[MAX_N];
int mx[MAX_N];
bool used[MAX_N];
int at[MAX_N];

void dfs_sz(int v, int p)
{
	sz[v] = 1;
	mx[v] = 0;
	for (int i = 0; i < (int)g[v].size(); ++i)
	{
		int to = g[v][i];
		if (to == p || used[to]) continue;
		dfs_sz(to, v);
		sz[v] += sz[to];
		mx[v] = max(mx[v], sz[to]);
	}
}

int dfs_c(int v, int sz, int p)
{
	if ((sz - ::sz[v]) * 2 <= sz && mx[v] * 2 <= sz) return v;
	for (int i = 0; i < (int)g[v].size(); ++i)
	{
		int to = g[v][i];
		if (to == p || used[to]) continue;
		int now = dfs_c(to, sz, v);
		if (now != -1) return now;
	}

	return -1;
}

int solve(int v, int deep)
{
	dfs_sz(v, -1);
	int now = dfs_c(v, sz[v], -1);
	used[now] = true;
	at[now] = deep;
	
	for (int i = 0; i < (int)g[now].size(); ++i)
	{
		int to = g[now][i];
		if (used[to]) continue;
		solve(to, deep + 1);
	}

	return now;
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

	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		--v; --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	memset(used, 0, sizeof(used));
	solve(0, 0);
		
	for (int i = 0; i < n; ++i) printf("%c%c", at[i] + 'A', " \n"[i == n - 1]);

	return 0;
}