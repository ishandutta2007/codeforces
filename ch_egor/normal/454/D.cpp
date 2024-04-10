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
const int MAX_P = 17;
const int MAX_NUMBER = 66;
const int MAX_N = 105;
const int prime[MAX_P] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };

int my_abs(int x)
{
	return (x > 0) ? x : -x;
}

int n;
int arr[MAX_N];
int can[MAX_NUMBER];
int dp[MAX_N][1 << MAX_P];
int answer[MAX_N][1 << MAX_P];
int res[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	memset(can, 0, sizeof(can));
	for (int i = 1; i < MAX_NUMBER; ++i)
	{
		for (int j = 0; j < MAX_P; ++j)
		{
			if (i%prime[j] == 0)
			{
				can[i] |= (1 << j);
			}
		}
	}
	
	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < (1 << MAX_P); ++j)
		{
			dp[i][j] = INF;
		}
	}

	dp[0][0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < (1 << MAX_P); ++j)
		{
			if (dp[i - 1][j] != INF)
			{
				for (int k = 1; k < MAX_NUMBER; ++k)
				{
					if (!(j&can[k]))
					{
						if (dp[i][j | can[k]] > dp[i - 1][j] + my_abs(arr[i] - k))
						{
							dp[i][j | can[k]] = dp[i - 1][j] + my_abs(arr[i] - k);
							answer[i][j | can[k]] = k;
						}
					}
				}
			}
		}
	}

	int ans = INF;
	int at = 0;

	for (int i = 0; i < (1 << MAX_P); ++i)
	{
		if (dp[n][i] < ans)
		{
			ans = dp[n][i];
			at = i;
		}
	}

	for (int i = n; i > 0; --i)
	{
		res[i] = answer[i][at];
		at ^= can[res[i]];
	}

	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", res[i]);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}