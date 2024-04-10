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
const int MOD = 998244353;

const int MAX_N = 5005;

ll dp[MAX_N][MAX_N];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	for (int i = 0; i < MAX_N; ++i)
		dp[i][0] = dp[0][i] = 1;
	for (int i = 1; i < MAX_N; ++i)
	{
		for (int j = 1; j < MAX_N; ++j)
		{
			dp[i][j] = (dp[i - 1][j] + j * dp[i - 1][j - 1]) % MOD;
		}
	}

	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	printf("%lld\n", (dp[a][b] * dp[b][c] % MOD * dp[c][a]) % MOD);

	return 0;
}