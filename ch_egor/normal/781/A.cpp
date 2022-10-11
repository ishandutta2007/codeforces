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

const int MAX_N = 200 * 1000 + 5;

int n;
vector<int> g[MAX_N];
int cl[MAX_N];

void dfs(int v, int p, int fr)
{
	if (p == -1)
	{
		cl[v] = 1;
		for (int i = 0; i < (int)g[v].size(); ++i)
		{
			cl[g[v][i]] = i + 2;
			dfs(g[v][i], v, -1);
		}
	}
	else
	{
		int ptr = 1;
		for (int i = 0; i < (int)g[v].size(); ++i)
		{
			int to = g[v][i];
			if (to != p)
			{
				while (ptr == cl[v] || ptr == cl[p]) ++ptr;
				cl[to] = ptr;
				++ptr;
				dfs(to, v, -1);
			}
		}
	}
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
		--v;
		--u;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	int max_of = 0;
	for (int i = 0; i < n; ++i)
	{
		if (g[i].size() > g[max_of].size())
			max_of = i;
	}
	
	dfs(max_of, -1, -1);
	
	printf("%d\n", (int)g[max_of].size() + 1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", cl[i]);
	}

	return 0;
}