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

const int MAX_N = 305;

int n, m, k;
int arr[MAX_N];
bool used[MAX_N];
bool used_d[MAX_N];
bool used_ed[MAX_N][MAX_N];
vector<pair<int, int> > answer;
vector<int> graph[MAX_N];

int v_m;

bool is_correct(int v1, int v2)
{
	if (used[v1] && used[v2])
	{
		if (v1 == v_m || v2 == v_m)
		{
			return false;
		}
		return true;
	}
	else
	{
		return true;
	}
}

void dfs(int v)
{
	used_d[v] = true;
	for (int i = 0; i < n; ++i)
	{
		if (is_correct(v, i) && !used_d[i])
		{
			printf("%d %d\n", v + 1, i + 1);
			used_ed[v][i] = true;
			used_ed[i][v] = true;
			dfs(i);
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &arr[i]);
		used[--arr[i]] = true;
	}

	if (n == k || ((n*(n - 1)) >> 1) - k + 1 < m || m < n - 1 || k == 1)
	{
		printf("-1");
		return 0;
	}

	v_m = arr[0];
	
	dfs(0);
	
	int cnt = n - 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (!used_ed[i][j] && is_correct(i, j) && cnt < m)
			{
				++cnt;
				printf("%d %d\n", i + 1, j + 1);
			}
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}