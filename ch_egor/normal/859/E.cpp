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

#define prev prev228

int n;
int prev[MAX_N];
int sz[MAX_N];
int lp_t[MAX_N];

int get(int v)
{
	return (v == prev[v]) ? v : (prev[v] = get(prev[v]));
}

void un(int v1, int v2)
{
	if (v1 == v2)
	{
		lp_t[get(v1)] = 1;
		return;
	}

	v1 = get(v1);
	v2 = get(v2);

	if (v1 != v2)
	{
		if (sz[v1] > sz[v2]) swap(v1, v2);

		sz[v2] += sz[v1];
		if (lp_t[v2] == 0)
		{
			lp_t[v2] = lp_t[v1];
		}
		else if (lp_t[v2] == 1)
		{
			//
		}
		else
		{
			if (lp_t[v1] == 1)
				lp_t[v2] = 1;
		}

		prev[v1] = v2;
	}
	else
	{
		if (lp_t[v1] == 0)
		{
			lp_t[v1] = 2;
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

	scanf("%d", &n);
	
	n <<= 1;
	for (int i = 0; i < n; ++i)
	{
		prev[i] = i;
		sz[i] = 1;
		lp_t[i] = 0;
	}

	int v1, v2;
	for (int i = 0; i < (n >> 1); ++i)
	{
		scanf("%d%d", &v1, &v2);
		--v1; --v2;
		un(v1, v2);
	}

	ll ans = 1;
	for (int i = 0; i < n; ++i)
	{
		if (prev[i] == i)
		{
			if (lp_t[i] == 0)
				ans = (ans * sz[i]) % MOD;
			else if (lp_t[i] == 2)
				ans = (ans * 2) % MOD;
		}
	}

	printf("%lld\n", ans);

	return 0;
}