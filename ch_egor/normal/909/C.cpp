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

const int MAX_N = 5005;

int n;
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

	scanf("%d\n", &n);
	
	int ptr = 0;
	dp[0][0] = 1;
	char c;
	while (scanf("%c\n", &c) == 1)
	{
		int cnt = 0;
		while (c == 'f')
		{
			++cnt;
			scanf("%c\n", &c);
		}
		
		ll sum = 0;
		for (int i = MAX_N - 1; i >= 0; --i)
		{
			sum += dp[ptr][i];
			sum %= MOD;
			if (i + cnt < MAX_N)
			{
				dp[ptr + 1][i + cnt] += sum;
				dp[ptr + 1][i + cnt] %= MOD;
			}
		}
		++ptr;
	}
	

	ll ans = 0;
	for (int i = 0; i < MAX_N; ++i)
	{
		ans += dp[ptr][i];
		ans %= MOD;
	}
	
	printf("%lld\n", ans);

	return 0;
}