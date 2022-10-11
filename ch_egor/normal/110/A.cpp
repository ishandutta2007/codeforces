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


int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	ll x;
	scanf("%lld", &x);

	int cnt = 0;
	while (x > 0)
	{
		ll ls = x % 10;
		if (ls == 4 || ls == 7) ++cnt;
		x /= 10;
	}

	if (cnt == 0) return 0 * printf("NO");
	while (cnt > 0)
	{
		int ls = cnt % 10;
		if (ls != 4 && ls != 7) return 0 * printf("NO");
		cnt /= 10;
	}
	printf("YES");

	return 0;
}