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
const int MAX_N = 1000 * 100 + 5;

int n, m;
vector<int> graph[MAX_N];
vector<int> new_graph[MAX_N];
vector<int> answer;
bool odd[MAX_N];
bool used[MAX_N];

void dfs_odd(int v)
{
	used[v] = true;

	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (!used[graph[v][i]])
		{
			dfs_odd(graph[v][i]);
			new_graph[v].push_back(graph[v][i]);
		}
	}
}

void dfs_answer(int v)
{
	answer.push_back(v);
	odd[v] ^= 1;

	for (int i = 0; i < new_graph[v].size(); ++i)
	{
		dfs_answer(new_graph[v][i]);

		answer.push_back(v);
		odd[v] ^= 1;

		if (odd[new_graph[v][i]])
		{
			answer.push_back(new_graph[v][i]);
			answer.push_back(v);
			odd[v] ^= 1;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);
	
	int v1, v2;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	int now;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &now);
		odd[i] = (now == 1);
	}

	memset(used, 0, sizeof(used));

	int odd_node = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (odd[i])
		{
			dfs_odd(i);
			odd_node = i;
			break;
		}
	}

	if (odd_node == -1)
	{
		printf("0");
	}
	else
	{
		bool disconnect = false;
		for (int i = 1; i <= n; ++i)
		{
			if (odd[i] && !used[i])
			{
				disconnect = true;
			}
		}

		if (disconnect)
		{
			printf("-1");
		}
		else
		{
			dfs_answer(odd_node);

			if (odd[odd_node])
			{
				printf("%d\n", (int)answer.size() - 1);
				for (int i = 1; i < answer.size(); ++i)
				{
					printf("%d ", answer[i]);
				}
			}
			else
			{
				printf("%d\n", (int)answer.size());
				for (int i = 0; i < answer.size(); ++i)
				{
					printf("%d ", answer[i]);
				}
			}
		}
	}


	fclose(stdin);
	fclose(stdout);

	return 0;
}