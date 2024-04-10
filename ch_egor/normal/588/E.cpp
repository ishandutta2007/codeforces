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
const int64 LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_LOG = 19;
const int MAX_N = 1000 * 100 + 5;
const int MAX_AT = 10;

int n, m, q;
vector<int> at_node[MAX_N];
vector<int> graph[MAX_N];
int dp[MAX_N][MAX_LOG];
vector<int> at_dp[MAX_N][MAX_LOG];
vector<int> answer;
int tin[MAX_N];
int tout[MAX_N];
int timenow = 0;

void add_to(vector<int> &to, vector<int> &out)
{
	for (int i = 0; i < min((int)out.size(), MAX_AT); ++i)
	{
		to.push_back(out[i]);
	}
	sort(to.begin(), to.end());
	while (to.size() > MAX_AT) to.pop_back();
}

void dfs_build(int v, int p)
{
	tin[v] = timenow;
	++timenow;

	bool have_one = false;
	if (v == 1) have_one = true;
	dp[v][0] = p;
	add_to(at_dp[v][0], at_node[v]);
	for (int i = 1; i < MAX_LOG; ++i)
	{
		dp[v][i] = dp[dp[v][i - 1]][i - 1];
		add_to(at_dp[v][i], at_dp[v][i - 1]);
		if (dp[v][i - 1] != 1 || !have_one)
			add_to(at_dp[v][i], at_dp[dp[v][i - 1]][i - 1]);
		if (dp[v][i - 1] == 1) have_one = true;
	}

	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (graph[v][i] != p)
		{
			dfs_build(graph[v][i], v);
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

void lca_answer(int v1, int v2)
{
	int cv1 = v1;
	int cv2 = v2;
	int lc = lca(v1, v2);
	answer.clear();

	for (int i = MAX_LOG - 1; i >= 0; --i)
	{
		if (!father(dp[v1][i], v2))
		{
			add_to(answer, at_dp[v1][i]);
			v1 = dp[v1][i];
		}
	}

	if (cv1 != lc)
		add_to(answer, at_dp[v1][0]);

	for (int i = MAX_LOG - 1; i >= 0; --i)
	{
		if (!father(dp[v2][i], v1))
		{
			add_to(answer, at_dp[v2][i]);
			v2 = dp[v2][i];
		}
	}

	if (cv2 != lc)
		add_to(answer, at_dp[v2][0]);

	add_to(answer, at_node[lc]);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n, &m, &q);

	int v1, v2;
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	int people;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &people);
		at_node[people].push_back(i + 1);
	}

	for (int i = 1; i <= n; ++i)
	{
		sort(at_node[i].begin(), at_node[i].end());
	}

	dfs_build(1, 1);

	int a;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d %d %d", &v1, &v2, &a);

		lca_answer(v1, v2);

		printf("%d ", min((int)answer.size(), a));
		for (int j = 0; j < min((int)answer.size(), a); ++j)
		{
			printf("%d ", answer[j]);
		}
		printf("\n");
	}

	//for (int i = 1; i <= n; ++i)
	//{
	//	printf("!!!!!!!%d\n", i);
	//	for (int j = 0; j < 4; ++j)
	//	{
	//		printf("--!!--%d\n", j);
	//		for (int k = 0; k < at_dp[i][j].size(); ++k)
	//		{
	//			printf("%d ", at_dp[i][j][k]);
	//		}
	//		printf("\n");
	//	}
	//}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}