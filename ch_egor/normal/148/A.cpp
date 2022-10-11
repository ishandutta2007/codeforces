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

	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;

	int cnt = 0;
	int kek = 0;
	for (int i = 1; i <= d; ++i)
	{
		bool f = false;
		if (i % k == 0) ++cnt, f = true;
		if (i % l == 0) ++cnt, f = true;
		if (i % m == 0) ++cnt, f = true;
		if (i % n == 0) ++cnt, f = true;

		kek += f;
	}
	
	return 0 * printf("%d\n", kek);

	return 0;
}