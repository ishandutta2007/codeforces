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
typedef unsigned long long int ull;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1000 * 100 + 5;
const int MAGIC = 56;

const string st = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string bg = "What are you doing while sending \"";
const string md = "\"? Are you busy? Will you send \"";
const string ed = "\"?";

ull sz[MAX_N];

char ya_ebal_overflow(ull n, ull k)
{
	if (n > MAGIC)
	{
		ull at_bg = (n - MAGIC) * (ull)bg.size();

		if (k > at_bg)
		{
			return ya_ebal_overflow(MAGIC, k - at_bg);
		}
		else
		{
			return bg[(k - 1) % bg.size()];
		}
	}
	else
	{
		if (k > sz[n]) return '.';
		if (n == 0) return st[k - 1];
		
		if (k <= bg.size())
		{
			return bg[k - 1];
		}
		else if (k <= bg.size() + sz[n - 1])
		{
			return ya_ebal_overflow(n - 1, k - bg.size());
		}
		else if (k <= bg.size() + sz[n - 1] + md.size())
		{
			return md[k - 1 - bg.size() - sz[n - 1]];
		}
		else if (k <= bg.size() + sz[n - 1] + md.size() + sz[n - 1])
		{
			return ya_ebal_overflow(n - 1, k - bg.size() - sz[n - 1] - md.size());
		}
		else
		{
			return ed[k - 1 - 2ull * sz[n - 1] - bg.size() - md.size()];
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

	sz[0] = st.size();

	for (int i = 1; i < MAX_N; ++i)
	{
		sz[i] = sz[i - 1] * 2ull + bg.size() + md.size() + ed.size();
	}

	/*for (int i = 0; i < MAX_N; ++i)
	{
		if (sz[i] > 1e18)
		{
			printf("%d\n", i);
			break;
		}
	}*/
	
	int t;
	scanf("%d", &t);

	while (t--)
	{
		ull n, k;
		scanf("%llu%llu", &n, &k);
		printf("%c", ya_ebal_overflow(n, k));
	}

	return 0;
}