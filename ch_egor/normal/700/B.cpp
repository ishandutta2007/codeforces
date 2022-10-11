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

const int MAX_N = 200 * 1000 + 5;
const int MAX_LOG = 18;

int n, k;
int arr[MAX_N];
vector<int> graph[MAX_N];
int dp[MAX_N][MAX_LOG];
int tin[MAX_N];
int tout[MAX_N];
int deep_of[MAX_N];
int timenow = 0;

void dfs(int v, int p, int deep)
{
	deep_of[v] = deep;
	tin[v] = timenow;
	++timenow;

	dp[v][0] = p;
	for (int i = 1; i < MAX_LOG; ++i)
	{
		dp[v][i] = dp[dp[v][i - 1]][i - 1];
	}

	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (graph[v][i] != p)
		{
			dfs(graph[v][i], v, deep + 1);
		}
	}

	tout[v] = timenow;
	++timenow;
}

bool father(int v1, int v2)
{
	return tin[v1] <= tin[v2] && tout[v2] <= tout[v1];
}

int lca(int v1, int v2)
{
	if (father(v1, v2))
	{
		return v1;
	}
	if (father(v2, v1))
	{
		return v2;
	}

	for (int i = MAX_LOG - 1; i >= 0; --i)
	{
		if (!father(dp[v1][i], v2))
		{
			v1 = dp[v1][i];
		}
	}

	return dp[v1][0];
}

int dist(int v1, int v2)
{
	int lc = lca(v1, v2);

	return deep_of[v1] + deep_of[v2] - 2*deep_of[lc];
}

bool cmp(int a, int b)
{
	return tin[a] < tin[b];
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &k);

	k *= 2;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &arr[i]);
	}

	int v1, v2;
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	dfs(1, 1, 0);

	sort(arr, arr + k, cmp);

	int64 answer = 0;
	for (int i = 0; i < k / 2; ++i)
	{
		answer += dist(arr[i], arr[i + k / 2]);
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}