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

const int MAX_N = 55;

int n;
ll arr[MAX_N];
ll sum[MAX_N];
ll dp[MAX_N][2];

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
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	reverse(arr, arr + n);
	
	sum[0] = arr[0];
	for (int i = 1; i < n; ++i) sum[i] = sum[i - 1] + arr[i];
	
	dp[0][0] = arr[0];
	dp[0][1] = arr[0];

	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = max(dp[i - 1][0], arr[i] + sum[i - 1] - dp[i - 1][1]);
		dp[i][1] = max(dp[i - 1][1], arr[i] + sum[i - 1] - dp[i - 1][0]);
	}

	printf("%lld %lld\n", sum[n - 1] - dp[n - 1][0], dp[n - 1][0]);

	return 0;
}