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
int64 cnt[MAX_N];
int64 dp[MAX_N];
int64 answer = 0;

int64 gcd(int64 a, int64 b)
{
	return ((b) ? gcd(b, a % b) : a);
}

void dfs(int v, int p)
{
	int64 min_of = LLINF;

	dp[v] = 1;
	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (graph[v][i] != p)
		{
			dfs(graph[v][i], v);
			dp[v] = (dp[v] / gcd(dp[v], dp[graph[v][i]])) * dp[graph[v][i]];
			cnt[v] += cnt[graph[v][i]];
			min_of = min(min_of, cnt[graph[v][i]]);
		}
	}

	if (min_of != LLINF)
	{
		answer += cnt[v] - (min_of - min_of % dp[v]) * ((int64)graph[v].size() - ((v == 0) ? 0 : 1));
		cnt[v] = (min_of - min_of % dp[v]) * ((int64)graph[v].size() - ((v == 0) ? 0 : 1));
	}

	if (((int64)graph[v].size() - ((v == 0) ? 0 : 1)) != 0)
	{
		dp[v] *= ((int64)graph[v].size() - ((v == 0) ? 0 : 1));
	}

	if (dp[v] == 0)
	{
		dp[v] = 1;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &cnt[i]);
	}
	
	int v1, v2;
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d%d", &v1, &v2);
		--v1; --v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	dfs(0, -1);

	printf("%lld", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}