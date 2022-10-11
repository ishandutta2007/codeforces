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

const int MAX_N = 505;

void no_exit()
{
	printf("No");
	exit(0);
}

int n, m;
bool graph[MAX_N][MAX_N];
bool graph2[MAX_N][MAX_N];
int cnt1[MAX_N];
bool used[MAX_N];
int st[MAX_N];
int timer = 5;

void dfs(int v, int number)
{
	used[v] = true;
	st[v] = number;
	for (int i = 1; i <= n; ++i)
	{
		if (v != i)
		{
			if (!graph[v][i])
			{
				if (used[i])
				{
					if (st[i] == st[v])
					{
						no_exit();
					}
				}
				else
				{
					if (number == 1)
					{
						dfs(i, 2);
					}
					else
					{
						dfs(i, 1);
					}
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	memset(cnt1, 0, sizeof(cnt1));
	memset(st, 0, sizeof(st));
	memset(graph, 0, sizeof(graph));
	memset(graph2, 0, sizeof(graph2));
	memset(used, 0, sizeof(used));

	int v1, v2;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = true;
		graph[v2][v1] = true;
		++cnt1[v1];
		++cnt1[v2];
	}

	//for (int i = 1; i <= n; ++i)
	//{
	//	for (int j = 1; j <= n; ++j)
	//	{
	//		if (!graph[i][j] && i != j)
	//		{
	//			if (st[i] == 0 && st[j] == 0)
	//			{
	//				st[i] = 1; st[j] = 2;
	//			}
	//			else if (st[i] == 0)
	//			{
	//				if (st[j] == 1)
	//				{
	//					st[i] = 2;
	//				}
	//				else
	//				{
	//					st[i] = 1;
	//				}
	//			}
	//			else if (st[j] == 0)
	//			{
	//				if (st[i] == 1)
	//				{
	//					st[j] = 2;
	//				}
	//				else
	//				{
	//					st[j] = 1;
	//				}
	//			}
	//			else if (st[i] == st[j])
	//			{
	//				for (int k = 1; k <= n; ++k)
	//				{
	//					if (!graph[j][k])
	//					{
	//						if (graph[i][k])
	//					}
	//				}
	//			}
	//			else
	//			{
	//				no_exit();
	//			}
	//		}
	//	}
	//}

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!used[i])
		{
			if (cnt1[i] == n - 1)
			{
				st[i] = 3;
			}
			else
			{
				dfs(i, 1);
				++cnt;
			}
		}
	}


	if (cnt > 1)
	{
		no_exit();
	}

	//for (int i = 1; i <= n; ++i)
	//{
	//	if (st[i] != 0)
	//	{
	//		st[i] = 3;
	//	}
	//}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i != j)
			{
				if (st[i] == 1 && st[j] == 2)
				{
					graph2[i][j] = false;
				}
				else if (st[i] == 2 && st[j] == 1)
				{
					graph2[i][j] = false;
				}
				else
				{
					graph2[i][j] = true;
				}

				if (graph[i][j] != graph2[i][j])
				{
					no_exit();
				}
			}
		}
	}

	printf("Yes\n");
	for (int i = 1; i <= n; ++i)
	{
		if (st[i] == 1)
		{
			printf("a");
		}
		else if (st[i] == 2)
		{
			printf("c");
		}
		else
		{
			printf("b");
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}

//if (graph[i][j] && graph[i][q] && graph[j][q])
//{
//	if (st[i] == 0 && st[j] == 0 && st[q] == 0)
//	{
//		st[i] = st[j] = st[q] = timer;
//		++timer;
//	}
//	else if (st[i] == 0 && st[j] == 0)
//	{
//		st[i] = st[q]; st[j] = st[q];
//	}
//	else if (st[i] == 0 && st[q] == 0)
//	{
//		st[i] = st[j]; st[q] = st[j];
//	}
//	else if (st[j] == 0 && st[q] == 0)
//	{
//		st[j] = st[i], st[q] = st[i];
//	}
//	else if (st[i] == 0)
//	{
//		if (st[j] != st[q])
//		{
//			no_exit();
//		}
//		else
//		{
//			st[i] = st[j];
//		}
//	}
//	else if (st[j] == 0)
//	{
//		if (st[i] != st[q])
//		{
//			no_exit();
//		}
//		else
//		{
//			st[j] = st[i];
//		}
//	}
//	else if (st[q] == 0)
//	{
//		if (st[i] != st[j])
//		{
//			no_exit();
//		}
//		else
//		{
//			st[q] = st[i];
//		}
//	}
//	if (st[i] == st[j] && st[j] == st[q])
//	{
//		continue;
//	}
//	else
//	{
//		no_exit();
//	}
//}