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
const int64 MAX_CAP = (1ll << 59);
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX_N = 55;
const int MAX_M = 505;

struct edge
{
	int v;
	int cap;
	int64 flow;

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
vector<int> graph[MAX_M];
edge edges[MAX_M*20];
queue<int> look_now;
int used[MAX_M];
int res[MAX_M];
int ptr[MAX_M];
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

bool bfs(int64 need, double80 dw)
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
				(int64)(edges[to].cap / dw) - edges[to].flow >= need)
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

int64 dfs(int v, int64 min_at_road, int64 need, double80 dw)
{
	if (v == t)
	{
		return min_at_road;
	}
	else
	{
		int64 push_all = 0;
		int64 push_road;
		int to;

		while (ptr[v] < graph[v].size())
		{
			to = graph[v][ptr[v]];

			if (res[v] + 1 == res[edges[to].v] &&
				floor(edges[to].cap / dw) - edges[to].flow >= need &&
				(push_road = dfs(edges[to].v, min(min_at_road, (int64)(edges[to].cap / dw) - edges[to].flow), need, dw)) > 0)
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

int x;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n, &m, &x);

	int v1, v2, cap;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &v1, &v2, &cap);
		add_edge(v1, v2, cap);
	}

	s = 1;
	t = n;

	int64 answer = 0;

	double80 l, r, m;
	l = 0.000001;
	r = INF;

	for (int j = 0; j < 180; ++j)
	{
		m = (l + r) / 2;
		answer = 0;
		memset(used, 0, sizeof(int)*(n + 5));
		iter = 0;
		for (int64 i = MAX_CAP; i > 0; i >>= 1)
		{
			while (bfs(i, m))
			{
				answer += dfs(s, LLINF, i, m);
			}
		}

		if (answer >= x)
		{
			l = m;
		}
		else
		{
			r = m;
		}

		for (int i = 0; i < cnt_edge; ++i)
		{
			edges[i].flow = 0;
		}
	}

	cout << fixed << setprecision(20);
	cout << l*x;

	fclose(stdin);
	fclose(stdout);

	return 0;
}