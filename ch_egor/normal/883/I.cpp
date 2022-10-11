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

const int MAX_N = 300 * 1000 + 228;

int n, k;
ll arr[MAX_N];
ll dp[MAX_N];

bool check(ll m)
{
	if (arr[k - 1] - arr[0] > m) return false;
	for (int i = 0; i < n; ++i) dp[i] = -1;
	for (int i = k - 1; i < n; ++i)
	{
		dp[i] = dp[i - 1];
		if (arr[i] - arr[dp[i - k] + 1] <= m)
			dp[i] = i;
	}

	return dp[n - 1] == n - 1;
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	if (k == 1) return 0 * printf("0\n");

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	ll l = -1;
	ll r = LLINF;

	while (r - l > 1)
	{
		ll m = (l + r) >> 1;

		if (check(m))
			r = m;
		else
			l = m;
	}

	printf("%lld\n", r);

	return 0;
}