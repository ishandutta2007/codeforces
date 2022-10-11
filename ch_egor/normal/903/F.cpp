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

const int MAX_N = 1005;

int n;
int cs[5];
char gg[4][MAX_N];
ll bt[MAX_N];
int arr[4][MAX_N];
ll dp[MAX_N][(1 << 12) + 4];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d", &n);
	for (int i = 0; i < 4; ++i) scanf("%d", &cs[i]);
	for (int i = 0; i < 4; ++i) scanf("%s", gg[i]);
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (gg[j][i] == '*') bt[i] |= (1 << j);
		}
	}
	
	for (int i = 0; i <= n; ++i) for (int j = 0; j < (1 << 12); ++j) 
	{
		dp[i][j] = LLINF;
	}
	
	dp[0][bt[0] | (bt[1] << 4) | (bt[2] << 8)] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = (1 << 12) - 1; j >= 0; --j)
		{
			if (dp[i][j] == LLINF) continue;
			
			if (!(j & 15))
			{
				dp[i + 1][(j >> 4) | (bt[i + 3] << 8)] = min(
				dp[i + 1][(j >> 4) | (bt[i + 3] << 8)],
				dp[i][j]);
			}
			
			for (int k = 0; k < 4; ++k)
			{
				int ms = (1 << 12) - 1;

				ms ^= (1 << k);
				int gg = (j & ms);
				if (!(gg & 15))
				{
					dp[i + 1][(gg >> 4) | (bt[i + 3] << 8)] = min(
					dp[i + 1][(gg >> 4) | (bt[i + 3] << 8)],
					dp[i][j] + cs[0]);
				}
				dp[i][gg] = min(dp[i][gg], dp[i][j] + cs[0]);

				if (k < 3)
				{
					ms ^= (1 << (k + 1));
					ms ^= (1 << (k + 4));
					ms ^= (1 << (k + 5));

					gg = (ms & j);
					if (!(gg & 15))
					{
						dp[i + 1][(gg >> 4) | (bt[i + 3] << 8)] = min(
						dp[i + 1][(gg >> 4) | (bt[i + 3] << 8)],
						dp[i][j] + cs[1]);
					}
					dp[i][gg] = min(dp[i][gg], dp[i][j] + cs[1]);
				}

				if (k < 2)
				{
					ms ^= (1 << (k + 2));
					ms ^= (1 << (k + 6));
					ms ^= (1 << (k + 8));
					ms ^= (1 << (k + 9));
					ms ^= (1 << (k + 10));
				
					gg = (ms & j);
					if (!(gg & 15))
					{
						dp[i + 1][(gg >> 4) | (bt[i + 3] << 8)] = min(
						dp[i + 1][(gg >> 4) | (bt[i + 3] << 8)],
						dp[i][j] + cs[2]);
					}
					dp[i][gg] = min(dp[i][gg], dp[i][j] + cs[2]);

				}
			}

			dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + cs[3]);
		}
	}

	printf("%lld\n", dp[n][0]);

	return 0;
}