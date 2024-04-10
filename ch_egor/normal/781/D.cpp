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

const int MAX_N = 505;

int n, m;
bitset<MAX_N> g[2][MAX_N];
bitset<MAX_N> mt[2][64][MAX_N];
bitset<MAX_N> buff[MAX_N];
bitset<MAX_N> trans[MAX_N];

void mul(bitset<MAX_N> a[MAX_N], bitset<MAX_N> b[MAX_N], bitset<MAX_N> c[MAX_N])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			trans[i][j] = b[j][i];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			buff[i][j] = (a[i] & trans[j]).any();
		}
	}

	for (int i = 0; i < n; ++i)
	{
		c[i] = buff[i];
	}
}

bitset<MAX_N> now[2][MAX_N];
bitset<MAX_N> next[MAX_N];

bool get(ll x)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			now[i][j] = 0;
		}
	}
	now[0][0] = 1;
	
	int	ptr = 0;
	for (int i = 61; i >= 0; --i)
	{
		if ((1ll << i) <= x)
		{
		//	mul(now, mt[ptr][i], now);
			x -= (1ll << i);
			ptr ^= 1;
		}
	}

	bool good = false;
	for (int i = 0; i < n; ++i)
	{
//		good |= (now[i].any());
	}

	return good;
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

	scanf("%d%d", &n, &m);

	int v, u, t;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &v, &u, &t);
		--v;
		--u;
		mt[t][0][v][u] = 1;
	}

	for (int i = 1; i < 62; ++i)
	{
		mul(mt[0][i - 1], mt[1][i - 1], mt[0][i]);
		mul(mt[1][i - 1], mt[0][i - 1], mt[1][i]);
	}
	
	ll l = 0;
	ll r = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll + 228;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			now[0][i][j] = 0;
		}
	}
	now[0][0][0] = 1;

	int	ptr = 0;
	for (int k = 61; k >= 0; --k)
	{

		mul(now[ptr], mt[ptr][k], now[ptr ^ 1]);
		bool good = false;
		for (int i = 0; i < n; ++i)
		{
			good |= (now[ptr ^ 1][i].any());
		}
		if (good)
		{
			l += (1ll << k);
			ptr ^= 1;
		}
		if (l > 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll)
		{
			break;
		}
	}



//	while (r - l > 1)
//	{
//		ll m = ((l + r) >> 1);
//		if (get(m))
//			l = m;
//		else
//			r = m;
//	}
	
	if (l > 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll)
		printf("-1\n");
	else
		printf("%lld\n", l);

	return 0;
}