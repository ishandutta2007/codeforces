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

const int MAX_N = 2000 * 100 + 5;

int n;
int arr[MAX_N];
int prev_of[MAX_N];
int cnt[MAX_N];
int answer[MAX_N];

int dfs(int v, bool ff)
{
	if (answer[v] != -1) return answer[v];

	if (!ff && (arr[v] == 1 || cnt[v] > 1))
	{
		answer[v] = 0;
		return 0;
	}
	else
	{
		if (prev_of[v] == -1)
		{
			answer[v] = 1;
			return answer[v];
		}
		else
		{
			answer[v] = 1 + dfs(prev_of[v], false);
			return answer[v];
		}
	}
}

vector<int> answer1;

int dfs1(int v, bool ff)
{
	if (!ff && (arr[v] == 1 || cnt[v] > 1))
	{
		answer[v] = 0;
		return 0;
	}
	else
	{
		if (prev_of[v] == -1)
		{
			answer[v] = 1;
			answer1.push_back(v);
			return answer[v];
		}
		else
		{
			answer[v] = 1 + dfs1(prev_of[v], false);
			answer1.push_back(v);
			return answer[v];
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &prev_of[i]);
		--prev_of[i];
		++cnt[prev_of[i]];
	}

	for (int i = 0; i < n; ++i)
	{
		answer[i] = -1;
	}

	int answer_at = 0;
	int ans = -1;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 1)
		{
			answer[i] = dfs(i, true);
			if (answer[i] > ans)
			{
				ans = answer[i];
				answer_at = i;
			}
		}
	}

	printf("%d\n", ans);
	dfs1(answer_at, true);
	for (int i = 0; i < answer1.size(); ++i) printf("%d ", answer1[i] + 1);

	fclose(stdin);
	fclose(stdout);

	return 0;
}