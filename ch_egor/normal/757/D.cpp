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

const int MAX_B = 20;
const int MAX_N = 77;
#define next next228

int n;
int dp[MAX_N][1 << MAX_B];
int po[MAX_N][MAX_N];
int next[MAX_N];
char st[MAX_N];
int go[MAX_N][MAX_B];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", st);

	for (int i = 0; i < n; ++i)
	{
		po[i][i] = st[i] - '0';
		for (int j = i + 1; j < n; ++j)
		{
			po[i][j] = po[i][j - 1] * 2 + st[j] - '0';
			if (po[i][j] > MAX_B) po[i][j] = INF;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		po[i][n] = INF;
	}

	for (int i = 0; i < n; ++i)
	{
		if (st[i] == '1')
		{
			next[i] = i;
		}
		else
		{
			next[i] = n;
			for (int j = i; j < n; ++j)
			{
				if (st[j] == '1')
				{
					next[i] = j;
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = next[i]; j < min(next[i] + 6, n); ++j)
		{
			if (po[i][j] != 0 && po[i][j] < MAX_B)
			{
				++dp[j][(1 << (po[i][j] - 1))];
				dp[j][(1 << (po[i][j] - 1))] %= MOD;
			}
		}

	}
	
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < (1 << MAX_B); ++j)
		{
			for (int k = next[i]; k < (min(next[i] + 6, n)); ++k)
			{
				if (po[i][k] != 0 && po[i][k] < MAX_B)
				{
					dp[k][(1 << (po[i][k] - 1)) | j] += dp[i - 1][j];
					dp[k][(1 << (po[i][k] - 1)) | j] %= MOD;
				}
			}
		}
	}

	int64 ans = 0;
	int ms = 0;
	for (int i = 0; i < n; ++i)
	{
		ms = 0;
		for (int j = 0; j < MAX_B; ++j)
		{
			ms |= (1 << j);
			ans += dp[i][ms];
			ans %= MOD;
		}
	}

	cout << ans;

	fclose(stdin);
	fclose(stdout);

	return 0;
}