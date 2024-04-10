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

const int MAX_N = 300 * 1000 + 228;

int n;
ll arr[MAX_N];
ll kk[MAX_N];

struct node
{
	int cnt;
	int bs;
	int go[2];
};

node br[MAX_N * 33];
int cnt = 0;

int new_node()
{
	br[cnt].go[0] = br[cnt].go[1] = -1;
	br[cnt].cnt = 0;
	br[cnt].bs = 0;
	return cnt++;
}

inline void calc(int v)
{
	br[v].bs = br[v].cnt;
	if (br[v].go[0] != -1) br[v].bs += br[br[v].go[0]].bs;
	if (br[v].go[1] != -1) br[v].bs += br[br[v].go[1]].bs;
}

void add(ll x, int now, int i)
{
	if (i == -1)
	{
		++br[now].cnt;
	}
	else
	{
		ll next = ((x >> i) & 1);
		if (br[now].go[next] == -1) br[now].go[next] = new_node();
		add(x, br[now].go[next], i - 1);
	}

	calc(now);
}

ll get_near(ll x, int now, int i)
{
	if (i == -1) 
	{
		--br[now].cnt;
		calc(now);
		return 0ll;
	}
	else
	{
		ll next = ((x >> i) & 1);
		if (br[now].go[next] == -1 || br[br[now].go[next]].bs == 0)
		{
			next ^= 1;
		}

		ll mem = get_near(x, br[now].go[next], i - 1);
		calc(now);

		if (next) mem ^= (1ll << i);
		
		return mem;
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

	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	for (int i = 0; i < n; ++i) scanf("%lld", &kk[i]);

	new_node();
	for (int i = 0; i < n; ++i) add(kk[i], 0, 30);

	for (int i = 0; i < n; ++i)
	{
		ll now = get_near(arr[i], 0, 30);
		printf("%lld ", (now ^ arr[i]));
	}

	return 0;
}