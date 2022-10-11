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

int n, k;
int arr[MAX_N];
int ans[MAX_N];

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

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		--arr[i];

		int lf = max(0, i - k);
		int rf = min(i + k, n - 1);

		if (arr[i] != -1)
		{
			lf = max(lf, min(arr[i] + k + 1, n));
			ans[i] += ans[arr[i]];
		}
		ans[i] += max(0, rf - lf + 1);
	}

	for (int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i == n - 1]);

	return 0;
}