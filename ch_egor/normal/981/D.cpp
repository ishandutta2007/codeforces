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

const int MAX_N = 61;

int n, k;
ll arr[MAX_N];
bitset<MAX_N> dp[MAX_N];

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
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);

	ll ans = 0;
	for (ll i = 61; i >= 0; --i)
	{
		ll now = (ans | (1ll << i));
		dp[0][0] = true;
	
		for (int i = 1; i <= n; ++i)
		{
			dp[i].reset();
			
			ll cur_sum = arr[i - 1];
			for (int j = i - 1; j >= 0; --j)
			{
				if ((cur_sum & now) == now) dp[i] |= (dp[j] << 1);
				if (j) cur_sum += arr[j - 1];
			}
		}

		if (dp[n][k]) ans = now;
	}

	printf("%lld\n", ans);

	return 0;
}