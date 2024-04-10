#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 5001;

int n, m, k;
vector<pair<int, int> > graph[MAX_N];
int prev_of[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif
    
    scanf("%d%d%d", &n, &m, &k);
    
	int v, u, t;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &v, &u, &t);
		graph[v - 1].push_back(make_pair(u - 1, t));
	}

	prev_of[0][0] = -1;
	dp[0][0] = 0;
	for (int i = 1; i < n; ++i)
	{
		dp[0][i] = INF;
	}
	
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j] = INF;
			prev_of[i][j] = -1;
		}

		for (int j = 0; j < n; ++j)
		{
			if (dp[i - 1][j] != INF)
			{
				for (int p = 0; p < graph[j].size(); ++p)
				{
					if (dp[i][graph[j][p].first] >= dp[i - 1][j] + graph[j][p].second)
					{
						prev_of[i][graph[j][p].first] = j;
					}
					dp[i][graph[j][p].first] = min(dp[i][graph[j][p].first], dp[i - 1][j] + graph[j][p].second);
				}
			}
		}
	}
	
	int ptr_ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (dp[i][n - 1] <= k)
		{
			ptr_ans = i;
		}
	}

	printf("%d\n", ptr_ans + 1);
	
	vector<int> ans;
	int vert = n - 1;
	while (ptr_ans > -1)
	{
		ans.push_back(vert);
		vert = prev_of[ptr_ans][vert];
		--ptr_ans;
	}

	for (int i = (int)ans.size() - 1; i >= 0; --i)
	{
		printf("%d ", ans[i] + 1);
	}

	return 0;
}