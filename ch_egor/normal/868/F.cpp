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

const int MAX_N = 1000 * 100 + 228;
const int MAX_K = 22;

int n, k;
int arr[MAX_N];
ll dp[MAX_K][MAX_N];
int opt[MAX_K][MAX_N];
int cnt[MAX_N];
ll ans = 0;
int l = 0, r = 0;

void add(int x)
{
	ans += cnt[x];
	++cnt[x];
}

void del(int x)
{
	--cnt[x];
	ans -= cnt[x];
}

void go_to(int pl, int pr)
{
	while (r < pr)
	{
		++r;
		if (r > 0) add(arr[r - 1]);
	}
	while (pl < l)
	{
		--l;
		if (l > 0) add(arr[l - 1]);
	}
	while (pr < r)
	{
		if (r > 0) del(arr[r - 1]);
		--r;
	}
	while (l < pl)
	{
		if (l > 0) del(arr[l - 1]);
		++l;
	}
}

void go(int pt, int l, int r, int pl, int pr)
{
	if (l > r) return;
	int m = (l + r) >> 1;
	
	for (int i = pl; i < min(m, pr + 1); ++i)
	{
		go_to(i + 1, m);	
		if (dp[pt][m] > dp[pt - 1][i] + ans)
		{
			opt[pt][m] = i;
			dp[pt][m] = dp[pt - 1][i] + ans;
		}
	}
	
	go(pt, l, m - 1, pl, opt[pt][m]);
	go(pt, m + 1, r, opt[pt][m], pr);
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

	scanf("%d%d", &n, &k);

	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j] = LLINF;
		}
	}
	
	for (int i = 0; i <= n; ++i)
	{
		go_to(0, i);
		dp[0][i] = ans;
	}
	
	for (int i = 1; i < k; ++i)
	{
		go(i, 0, n, 0, n);
	}

	
/*	for (int i = 1; i < k; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (j > 0) add(arr[j - 1]);
			for (int k = j - 1; k >= 0; --k)
			{
				if (dp[i][j] > dp[i - 1][k] + ans)
				{
					dp[i][j] = dp[i - 1][k] + ans;
					opt[i][j] = k;
				}
				if (k > 0) add(arr[k - 1]);
			}
			if (j > 0) del(arr[j - 1]);
			for (int k = j - 1; k >= 0; --k)
				if (k > 0) del(arr[k - 1]);
		}
	}
	
	for (int i = 1; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			assert(opt[i][j] <= opt[i][j + 1]);
		}
	}
*/
/*	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
*/
	printf("%lld\n", dp[k - 1][n]);

	return 0;
}