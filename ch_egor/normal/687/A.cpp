#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1000 * 100 + 5;

int n, m;
vector<int> graph[MAX_N];
bool used[MAX_N];
int type_of[MAX_N];

void dfs(int v, int tp)
{
	used[v] = true;
	type_of[v] = tp;

	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (!used[graph[v][i]])
		{
			dfs(graph[v][i], tp ^ 1);
		}
		else
		{
			if (type_of[v] == type_of[graph[v][i]])
			{
				printf("-1\n");
				exit(0);
			}
		}
	}
}

vector<int> gg[2];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	int v1, v2;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; ++i)
	{
		if (!used[i])
		{
			dfs(i, 0);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		gg[type_of[i]].push_back(i);
	}

	for (int i = 0; i < 2; ++i)
	{
		printf("%d\n", (int)gg[i].size());
		for (int j = 0; j < gg[i].size(); ++j)
		{
			printf("%d ", gg[i][j]);
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}