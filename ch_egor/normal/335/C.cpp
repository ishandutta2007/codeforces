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

const int MAX_N = 105;

int r, n;
bool arr[MAX_N][2];
int dp[MAX_N][MAX_N][3][3];
int used[6 * MAX_N];
int iter = 0;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d%d", &r, &n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		arr[x][y] = true;
	}
	
	n = r;
	
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			for (int t1 = 0; t1 < 3; ++t1)
			{
				for (int t2 = 0; t2 < 3; ++t2)
				{
					++iter;
					
					for (int k = i; k < j; ++k)
					{
						for (int go = 0; go < 2; ++go)
						{
							if (arr[k][0] || arr[k][1]) continue;
							if (k == i && t1 - 1 == (go ^ 1)) continue;
							if (k != i && arr[k - 1][go ^ 1]) continue;
							if (k == j - 1 && t2 - 1 == (go ^ 1)) continue;
							if (k != j - 1 && arr[k + 1][go ^ 1]) continue;
							
							used[dp[i][k][t1][go + 1] ^ dp[k + 1][j][go + 1][t2]] = iter;
						}
					}

					for (int k = 0; true; ++k)
					{
						if (used[k] != iter)
						{
							dp[i][j][t1][t2] = k;
							break;
						}
					}
				}
			}
		}
	}

	if (dp[0][n][0][0]) printf("WIN\n");
	else printf("LOSE\n");

	return 0;
}