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
int arr[MAX_N];
int dp[MAX_N];
bool used[MAX_N];
vector<int> graph[MAX_N];
queue<int> look_at;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &arr[i]);
		graph[i].push_back(arr[i]);
		graph[i].push_back(i + 1);
		graph[i + 1].push_back(i);
		dp[i] = INF;
	}

	memset(used, 0, sizeof(used));
	dp[1] = 0;
	used[1] = true;
	look_at.push(1);
	int v;
	while (!look_at.empty())
	{
		v = look_at.front();
		look_at.pop();
		for (int i = 0; i < graph[v].size(); ++i)
		{
			if (!used[graph[v][i]])
			{
				dp[graph[v][i]] = dp[v] + 1;
				look_at.push(graph[v][i]);
				used[graph[v][i]] = true;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", dp[i]);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}