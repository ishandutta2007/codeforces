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

const int MAX_N = 200 * 1000 + 228;

int n;
int s[MAX_N];
int g[MAX_N];
int l[MAX_N];
int r[MAX_N];
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
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &s[i], &g[i]);
	}
	
	for (int i = 0; i < n; ++i)
	{
		l[i] = s[i];
		r[i] = s[i] + g[i];

		if (i != 0)
		{
			int ll = max(l[i - 1] - 1, 0);
			int rr = r[i - 1] + 1;

			if (rr < l[i] || r[i] < ll) return 0 * printf("-1\n");
		
			l[i] = max(l[i], ll);
			r[i] = min(r[i], rr);
		}
	}
	
	for (int i = n - 1; i >= 0; --i)
	{
		ans[i] = r[i];
		if (i != n - 1)
		{
			ans[i] = min(r[i], ans[i + 1] + 1);
		}
	}

	ll answer = 0;
	for (int i = 0; i < n; ++i) answer += ans[i] - s[i];
	
	printf("%lld\n", answer);
	for (int i = 0; i < n; ++i) printf("%d ", ans[i]);

	return 0;
}