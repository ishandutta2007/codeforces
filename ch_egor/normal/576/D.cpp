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

const int INF = (1 << 30);
const int MAX_N = 155;
const int MAX_M = 155;

struct edge
{
	int v1;
	int v2;
	int time;
};

int n, m;
bitset<MAX_N> dp;
bitset<MAX_N> graph[MAX_N];
bitset<MAX_N> new_graph[MAX_N];
bitset<MAX_N> new_dp;
edge arr[MAX_M];
bitset<MAX_N> buff1;
bitset<MAX_N> buff2[MAX_N];
bitset<MAX_N> trans[MAX_N];

void mult1(bitset<MAX_N> b[MAX_N], bitset<MAX_N> a, bitset<MAX_N> &c)
{
	for (int i = 1; i <= n; ++i)
	{
		buff1[i] = (a & b[i]).any();
	}

	for (int i = 1; i <= n; ++i)
	{
		c[i] = buff1[i];
	}
}

void mult2(bitset<MAX_N> a[MAX_N], bitset<MAX_N> b[MAX_N], bitset<MAX_N> c[MAX_N])
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			trans[i][j] = b[j][i];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			buff2[i][j] = (a[i] & trans[j]).any();
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			c[i][j] = buff2[i][j];
		}
	}
}

bool check(int mid)
{
	for (int i = 1; i <= n; ++i)
	{
		new_dp[i] = dp[i];
		for (int j = 1; j <= n; ++j)
		{
			new_graph[i][j] = graph[i][j];
		}
	}

	while (mid != 0)
	{
		if (mid & 1)
		{
			mult1(new_graph, new_dp, new_dp);
			--mid;
		}

		mult2(new_graph, new_graph, new_graph);
		mid >>= 1;
	}

	return new_dp[n];
}

bool cmp(const edge &a, const edge &b)
{
	return a.time < b.time;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &arr[i].v1, &arr[i].v2, &arr[i].time);
	}

	for (int i = 1; i <= n; ++i)
	{
		dp.reset(i);
		for (int j = 1; j <= n; ++j)
		{
			graph[i].reset(j);
		}
	}

	graph[n].set(n);
	dp.set(1);
	sort(arr, arr + m, cmp);

	int timer = 0;
	int delta_time;

	for (int i = 0; i < m; ++i)
	{
		while (i < m && arr[i].time <= timer)
		{
			graph[arr[i].v2].set(arr[i].v1);
			++i;
		}
		if (i < m)
		{
			delta_time = arr[i].time - timer;
			--i;
		}

		for (int k = 1; k <= n; ++k)
		{
			new_dp[k] = dp[k];
			for (int t = 1; t <= n; ++t)
			{
				new_graph[k][t] = graph[k][t];
			}
		}

		if (i == m)
		{
			break;
		}

		while (delta_time != 0)
		{
			if (delta_time & 1)
			{
				mult1(new_graph, new_dp, new_dp);
				--delta_time;
			}

			mult2(new_graph, new_graph, new_graph);
			delta_time >>= 1;
		}

		if (new_dp[n])
		{
			break;
		}

		for (int k = 1; k <= n; ++k)
		{
			dp[k] = new_dp[k];
		}


		if (i + 1 < m)
		{
			timer = arr[i + 1].time;
		}
	}

	if (check(INF))
	{
		int left = timer;
		int right = INF;
		int mid;

		while (right - left > 1)
		{
			mid = ((left + right) >> 1);

			if (check(mid - timer))
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}

		printf("%d", right);
	}
	else
	{
		printf("Impossible");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}