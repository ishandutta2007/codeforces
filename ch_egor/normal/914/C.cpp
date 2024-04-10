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

const int MAX_N = 1000 + 228;

ll dp[MAX_N][MAX_N];
ll dist[MAX_N];

int n, k;
char st[MAX_N];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif
	
	dp[0][0] = 1;
	for (int i = 1; i < MAX_N; ++i)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= i; ++j) 
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			if (dp[i][j] >= MOD) dp[i][j] -= MOD;
		}
	}

	scanf("%s", st);
	n = strlen(st);
	scanf("%d", &k);
	
	if (k == 0) return 0 * printf("1\n");
	
	dist[1] = 1;
	for (int i = 2; i < MAX_N; ++i) dist[i] = dist[__builtin_popcount(i)] + 1;

	ll answer = 0;
	ll now = 0;
	for (int i = 0; i < n; ++i)
	{
		if (st[i] == '1')
		{
			for (int j = 0; j < n - i; ++j)
			{
				if (dist[now + j] == k)
				{
					answer += dp[n - i - 1][j];
					if (answer >= MOD) answer -= MOD;
				}
			}
		}
		now += (st[i] == '1');
	}
	
	answer += (dist[now] == k);
	if (answer >= MOD) answer -= MOD;
	if (k == 1) answer -= 1;
	if (answer < 0) answer += MOD;

	printf("%lld\n", answer);

	return 0;
}