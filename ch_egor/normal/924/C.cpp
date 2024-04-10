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

const int MAX_N = 100 * 1000 + 228;

int n;
ll arr[MAX_N];
ll at[MAX_N];
vector<ll> now;

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

	ll cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		now.push_back(i);
		while (cnt <= arr[i])
		{
			++cnt;
			++at[now.back()];
			now.pop_back();
		}
	}

	for (int i = 1; i < n; ++i) at[i] += at[i - 1];

	ll ans = 0;
	for (int i = 0; i < n; ++i) ans += at[i] - arr[i] - 1;

	printf("%lld\n", ans);

	return 0;
}