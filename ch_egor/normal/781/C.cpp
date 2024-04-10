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

int n, m, k;
vector<int> g[MAX_N];
int dist[MAX_N];
int len;
bool used[MAX_N];
vector<vector<int>> roads;

void add(int v)
{
	if (roads.back().size() == len)
	{
		roads.resize(roads.size() + 1);
	}
	roads.back().push_back(v);
}

void dfs(int v)
{
	used[v] = true;
	add(v);
	for (int i = 0; i < (int)g[v].size(); ++i)
	{
		int to = g[v][i];
		if (!used[to])
		{
			dfs(to);
			add(v);
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

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		--v; --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	roads.resize(1);
	len = (2*n + k - 1) / k;	
	
	for (int i = 0; i < n; ++i)
	{
		dist[i] = INF;
	}
	
	dfs(0);
	
	for (int i = 0; i < k; ++i)
	{
		if (i >= roads.size())
		{
			printf("1 1\n");
		}
		else
		{
			printf("%d ", (int)roads[i].size());
			for (int j = 0; j < (int)roads[i].size(); ++j)
			{
				printf("%d ", roads[i][j] + 1);
			}
			printf("\n");
		}
	}

	return 0;
}