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

int arr[2228];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &arr[i]);
	sort(arr, arr + m);
	int ans = INF;
	for (int i = 0; i < m - n + 1; ++i)
	{
		ans = min(ans, arr[i + n - 1] - arr[i]);
	}

	cout << ans;

	return 0;
}