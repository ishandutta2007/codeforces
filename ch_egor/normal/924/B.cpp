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
ll ds;
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

	scanf("%d%lld", &n, &ds);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);

	int ans1 = 0;
	int ans2 = 0;
	for (int l = 0, r = 0; l < n; ++l)
	{
		while (r < n && arr[r] - arr[l] <= ds) ++r;

		if (r - l >= 3)
		{
			--r;
			if (ans2 == 0 || 
				(arr[ans2] - arr[ans1 + 1]) * (arr[r] - arr[l]) <
				(arr[r] - arr[l + 1]) * (arr[ans2] - arr[ans1]))
			{
				ans1 = l;
				ans2 = r;
			}
			++r;
		}
	}

	if (ans2 == 0) printf("-1\n");
	else printf("%.20lf\n", ((double)arr[ans2] - arr[ans1 + 1]) /
		                    ((double)arr[ans2] - arr[ans1]));

	return 0;
}