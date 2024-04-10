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

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int MAX_N = 105;
const int MAX_M = 205;
const int INF = (1 << 30);
const int MAX_CAP = (1 << 30);

struct edge
{
	int v;
	int cap;
	int flow;

	edge(int _v, int _cap)
	{
		v = _v;
		cap = _cap;
		flow = 0;
	}

	edge()
	{
		v = 0;
		cap = 0;
		flow = 0;
	}
};

int n, m;
int s, t;
int start_m[MAX_N*2];
int end_m[MAX_N*2];
int answer[MAX_N][MAX_N];
vector<int> graph[MAX_N*2];
edge edges[MAX_M*16];
queue<int> look_now;
int used[MAX_N*2];
int res[MAX_N*2];
int ptr[MAX_N*2];
int iter = 0;
int cnt_edge = 0;

void add_edge(int v1, int v2, int cap)
{
	edges[cnt_edge] = edge(v2, cap);
	edges[cnt_edge ^ 1] = edge(v1, 0);

	graph[v1].push_back(cnt_edge);
	graph[v2].push_back(cnt_edge ^ 1);

	cnt_edge += 2;
}

bool bfs(int need)
{
	++iter;

	look_now.push(s);
	used[s] = iter;
	res[s] = 0;
	ptr[s] = 0;

	int v, to;
	while (!look_now.empty())
	{
		v = look_now.front();
		look_now.pop();

		for (int i = 0; i < graph[v].size(); ++i)
		{
			to = graph[v][i];
			if (used[edges[to].v] < iter &&
				edges[to].cap - edges[to].flow >= need)
			{
				used[edges[to].v] = iter;
				res[edges[to].v] = res[v] + 1;
				ptr[edges[to].v] = 0;
				look_now.push(edges[to].v);
			}
		}
	}

	return used[t] == iter;
}

int dfs(int v, int min_at_road, int need)
{
	if (v == t)
	{
		return min_at_road;
	}
	else
	{
		int push_all = 0;
		int push_road;
		int to;

		while (ptr[v] < graph[v].size())
		{
			to = graph[v][ptr[v]];

			if (res[v] + 1 == res[edges[to].v] &&
				edges[to].cap - edges[to].flow >= need &&
				(push_road = dfs(edges[to].v, min(min_at_road, edges[to].cap - edges[to].flow), need)) > 0)
			{
				push_all += push_road;

				edges[to].flow += push_road;
				edges[to ^ 1].flow -= push_road;

				min_at_road -= push_road;
			}

			if (min_at_road < need)
			{
				return push_all;
			}

			++ptr[v];
		}

		return push_all;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);
	s = n*2 + 1;
	t = n*2 + 2;

	int sum_start = 0;
	int sum_end = 0;

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &start_m[i]);
		sum_start += start_m[i];
		add_edge(s, i, start_m[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &end_m[i]);
		sum_end += end_m[i];
		add_edge(i + n, t, end_m[i]);
	}

	int v1, v2;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &v1, &v2);
		add_edge(v1, v2 + n, INF);
		add_edge(v2, v1 + n, INF);
	}

	for (int i = 1; i <= n; ++i)
	{
		add_edge(i, i + n, INF);
	}

	int flow = 0;

	memset(used, 0, (n*2 + 4)*sizeof(int));
	for (int i = MAX_CAP; i > 0; i >>= 1)
	{
		while (bfs(i))
		{
			flow += dfs(s, INF, i);
		}
	}

	int to;
	if (sum_start == sum_end && sum_start == flow)
	{
		printf("YES\n");

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				answer[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < graph[i].size(); ++j)
			{
				to = graph[i][j];
				if (edges[to].v - n > 0)
				{
					answer[i][edges[to].v - n] = edges[to].flow;
				}
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				printf("%d ", answer[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("NO");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}