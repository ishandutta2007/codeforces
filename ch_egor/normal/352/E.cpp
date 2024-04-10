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

const int INF = 2000000000 + 228;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 23;
const int MAGIC = 102;

int n, m;
int op[MAX_N];
int cl[MAX_N];
int dp[MAX_N*MAGIC][MAGIC + 5];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &op[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &cl[i]);
	}

	for (int i = 0; i < MAGIC; ++i) dp[0][i] = INF;
	dp[0][1] = op[0];

	for (int i = 1; i < min(n*m, n*MAGIC); ++i)
	{
		dp[i][0] = ((dp[i - 1][1] != INF) ? (dp[i - 1][1] + cl[i % n]) : INF);
		dp[i][MAGIC - 1] = ((dp[i - 1][MAGIC - 2] != INF) ? (dp[i - 1][MAGIC - 2] + op[i % n]) : INF);
		for (int j = 1; j < MAGIC - 1; ++j)
		{
			dp[i][j] = min(((dp[i - 1][j - 1] != INF) ? (dp[i - 1][j - 1] + op[i % n]) : INF),
						   ((dp[i - 1][j + 1] != INF) ? (dp[i - 1][j + 1] + cl[i % n]) : INF));
		}
		//for (int j = 0; j < MAGIC; ++j)
		//{
		//	cout << dp[i][j] << " ";
		//}
		//cout << endl;
	}

	//for (int i = 4*n - 1; i < m*n; i += 2*n)
	//{
	//	cout << dp[i][0] - dp[i - 2 * n][0] << endl;
	//}

	if (m <= MAGIC)
	{
		printf("%d\n", dp[n*m - 1][0]);
	}
	else
	{
		printf("%d\n", dp[n*MAGIC - 1][0] + (dp[n*MAGIC - 1][0] - dp[n*MAGIC - 1 - 2 * n][0]) * ((m - MAGIC) >> 1));
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}