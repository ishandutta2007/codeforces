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

const int MAX_N = 18;

ll n, k;
ll mt[MAX_N][MAX_N];
ll buff[MAX_N][MAX_N];
ll now[MAX_N][MAX_N];
ll dp[MAX_N];
ll cdp[MAX_N];

void pw2(ll a[MAX_N][MAX_N], ll b[MAX_N][MAX_N], ll c[MAX_N][MAX_N])
{
	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < MAX_N; ++j)
		{
			buff[i][j] = 0;
			for (int k = 0; k < MAX_N; ++k)
			{
				buff[i][j] = (buff[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}

	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < MAX_N; ++j)
		{
			c[i][j] = buff[i][j];
		}
	}
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

	scanf("%lld%lld", &n, &k);
	
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	memset(mt, 0, sizeof(mt));
	for (int i = 0; i < n; ++i)
	{
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (b > k) b = k;

		memset(mt, 0, sizeof(mt));
		for (int i = 0; i <= c; ++i)
		{
			if (i - 1 >= 0) mt[i][i - 1] = 1;
			mt[i][i] = 1;
			if (i + 1 <= c) mt[i][i + 1] = 1;
		}
		memset(now, 0, sizeof(now));
		for (int i = 0; i < MAX_N; ++i)
			now[i][i] = 1;

		b = b - a;
		while (b)
		{
			if (b&1) pw2(now, mt, now);
			pw2(mt, mt, mt);
			b >>= 1;
		}

		for (int i = 0; i < MAX_N; ++i)
		{
			cdp[i] = 0;
			for (int j = 0; j < MAX_N; ++j)
			{
				cdp[i] = (cdp[i] + now[i][j] * dp[j] % MOD) % MOD;
			}
		}
		memcpy(dp, cdp, sizeof(cdp));
	}
	
	printf("%lld\n", dp[0]);

	return 0;
}