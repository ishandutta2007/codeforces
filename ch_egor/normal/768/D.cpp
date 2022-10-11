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

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_K = 1005;
const int MAX_D = 8228;

#define double long double

const double eps = 1e-7;

int q, k;
double dp[MAX_D][MAX_K];
int ans[1228];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &k, &q);

	dp[0][0] = 2000;
	for (int i = 1; i < MAX_K; ++i)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i < MAX_D; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			dp[i][j] = dp[i - 1][j] * (double)j / k +dp[i - 1][j - 1] * (double)(k - j + 1) / k;
		}
	}

	for (int i = 1; i <= 1000; ++i)
	{
		double now = (double)i;
		for (int j = 0; j < MAX_D; ++j)
		{
			if (dp[j][k] + eps >= now)
			{
				ans[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < q; ++i)
	{
		int v;
		scanf("%d", &v);
		printf("%d\n", ans[v]);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}