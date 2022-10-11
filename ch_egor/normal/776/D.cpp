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

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, m;
int arr[228228];
vector<int> gg[228228];
bool used[228228];
int cl[228228];
vector<pair<int, int> > g[228228];

void dfs(int v, int c)
{
	used[v] = true;
	cl[v] = c;
	for (int i = 0; i < g[v].size(); ++i)
	{
		int to = g[v][i].first;
		if (!used[to])
		{
			dfs(to, c ^ g[v][i].second);
		}
		else
		{
			if ((c ^ g[v][i].second) != cl[to])
			{
				printf("NO\n");
				exit(0);
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < m; ++i)
	{
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; ++j)
		{
			int k;
			scanf("%d", &k);
			gg[k - 1].push_back(i);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (arr[i])
		{
			g[gg[i][0]].push_back({ gg[i][1], 0 });
			g[gg[i][1]].push_back({ gg[i][0], 0 });
		}
		else
		{
			g[gg[i][0]].push_back({ gg[i][1], 1 });
			g[gg[i][1]].push_back({ gg[i][0], 1 });
		}
	}

	memset(used, 0, sizeof(used));
	memset(cl, 0, sizeof(cl));
	for (int i = 0; i < m; ++i)
	{
		if (!used[i])
		{
			dfs(i, 0);
		}
	}

	printf("YES\n");

	fclose(stdin);
	fclose(stdout);

	return 0;
}