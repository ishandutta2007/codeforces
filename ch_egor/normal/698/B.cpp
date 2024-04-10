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

int n;
vector<int> graph[MAX_N];
vector<int> rev_graph[MAX_N];
int arr[MAX_N];
int answer[MAX_N];
int answer_on = 0;
vector<int> order;
vector<vector<int> > cc;
bool used[MAX_N];

void dfs_or(int v)
{
	used[v] = true;
	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (!used[graph[v][i]]) dfs_or(graph[v][i]);
	}
	order.push_back(v);
}

void dfs_comp(int v)
{
	used[v] = true;
	cc.back().push_back(v);
	for (int i = 0; i < rev_graph[v].size(); ++i)
	{
		if (!used[rev_graph[v][i]]) dfs_comp(rev_graph[v][i]);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	int root = -1;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		graph[i].push_back(arr[i] - 1);
		rev_graph[arr[i] - 1].push_back(i);
		if (arr[i] - 1 == i) root = i;
		answer[i] = arr[i] - 1;
	}

	memset(used, 0, sizeof(used));

	for (int i = 0; i < n; ++i)
	{
		if (!used[i]) dfs_or(i);
	}
	memset(used, 0, sizeof(used));

	for (int i = (int)order.size() - 1; i >= 0; --i)
	{
		if (!used[order[i]])
		{
			cc.resize(cc.size() + 1);
			dfs_comp(order[i]);
		}
	}

	int answer_on = 0;
	if (root == -1)
	{
		++answer_on;
		for (int i = 0; i < cc.size(); ++i)
		{
			if (cc[i].size() > 1)
			{
				root = cc[i][0];
				answer[cc[i][0]] = cc[i][0];
				break;
			}
		}

		if (root == -1)
		{
			root = cc[0][0];
			answer[cc[0][0]] = cc[0][0];
		}
	}
	else
	{
		for (int i = 0; i < cc.size(); ++i)
		{
			for (int j = 0; j < cc[i].size(); ++j)
			{
				if (cc[i][j] == root)
				{
					if (i != 0) cc[0].swap(cc[i]);
					goto end;
				}
			}
		}

	end:;
	}

	//for (int i = 0; i < cc.size(); ++i)
	//{
	//	for (int j = 0; j < cc[i].size(); ++j)
	//	{
	//		cout << cc[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	answer_on += (int)cc.size() - 1;
	for (int i = 1; i < cc.size(); ++i)
	{
		if (cc[i].size() == 1)
		{
			//cout << cc[i][0] << endl;
			if (arr[cc[i][0]] - 1 == cc[i][0])
			{
				answer[cc[i][0]] = root;
			}
			else
			{
				--answer_on;
			}
			continue;
		}

		bool have_root = false;
		for (int j = 0; j < cc[i].size(); ++j)
		{
			if (arr[cc[i][j]] - 1 == cc[i][j])
			{
				have_root = true;
				answer[cc[i][j]] = root;
				break;
			}
		}
		if (!have_root)
		{
			answer[cc[i][0]] = root;
		}
	}

	answer_on = 0;
	for (int i = 0; i < n; ++i)
	{
		if (answer[i] + 1 != arr[i]) ++answer_on;
	}

	printf("%d\n", answer_on);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", answer[i] + 1);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}