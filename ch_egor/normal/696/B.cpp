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

int n;
vector<int> graph[MAX_N];
int size_of[MAX_N];
double80 answer[MAX_N];

void dfs(int v)
{
	size_of[v] = 1;

	for (int i = 0; i < graph[v].size(); ++i)
	{
		dfs(graph[v][i]);
		size_of[v] += size_of[graph[v][i]];
	}
}

void dfs2(int v)
{
	answer[v] += 1;
	int sum = 0;

	for (int i = 0; i < graph[v].size(); ++i)
	{
		sum += size_of[graph[v][i]];
		answer[graph[v][i]] += answer[v];
	}

	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (graph[v].size() != 1)
		{
			answer[graph[v][i]] += (double80)(sum - size_of[graph[v][i]]) / 2;
		}
		dfs2(graph[v][i]);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	int v;
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d", &v);
		graph[v - 1].push_back(i + 1);
	}


	for (int i = 0; i < n; ++i)
	{
		answer[i] = 0;
	}

	dfs(0);
	dfs2(0);

	cout << fixed << setprecision(20);
	for (int i = 0; i < n; ++i)
	{
		cout << answer[i] << " ";
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}