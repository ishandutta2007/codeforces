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

const int MAX_N = 3 * 1000 * 100 + 5;

int n;
ll arr[MAX_N];

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
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &arr[i]);
	}
	
	sort(arr, arr + n);
	ll ans = 0;
	ll sum = arr[0];
	ll mul = 2;
	for (int i = 1; i < n; ++i)
	{
		ans += (((((mul - 1) * arr[i]) - sum) % MOD) + MOD) % MOD;
		ans %= MOD;
		mul = (2 * mul) % MOD;
		sum = ((2 * sum) + arr[i]) % MOD;
	}

	printf("%lld\n", ans);

	return 0;
}