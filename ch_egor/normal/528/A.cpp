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

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int w, h, n;
set < pair<int, int> > g1, g2;
set < pair<int, pair<int, int> > >  gg1, gg2;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d %d\n", &w, &h, &n);

	char c;
	int at;
	int l1, r1;
	g1.insert(make_pair(0, w)); g2.insert(make_pair(0, h));
	gg1.insert(make_pair(w, make_pair(0, w))); gg2.insert(make_pair(h, make_pair(0, h)));
	for (int i = 0; i < n; ++i)
	{
		scanf("%c %d\n", &c, &at);

		if (c == 'H')
		{
			auto t = g2.upper_bound(make_pair(at, INF));
			--t;
			l1 = t->first; r1 = t->second;
			g2.erase(make_pair(l1, r1));
			gg2.erase(make_pair(r1 - l1, make_pair(l1, r1)));

			g2.insert(make_pair(l1, at)); g2.insert(make_pair(at, r1));
			gg2.insert(make_pair(r1 - at, make_pair(at, r1)));
			gg2.insert(make_pair(at - l1, make_pair(l1, at)));
		}
		else
		{
			auto t = g1.upper_bound(make_pair(at, INF));
			--t;
			l1 = t->first; r1 = t->second;
			g1.erase(make_pair(l1, r1));
			gg1.erase(make_pair(r1 - l1, make_pair(l1, r1)));

			g1.insert(make_pair(l1, at)); g1.insert(make_pair(at, r1));
			gg1.insert(make_pair(r1 - at, make_pair(at, r1)));
			gg1.insert(make_pair(at - l1, make_pair(l1, at)));
		}

		printf("%lld\n", 1ll * gg1.rbegin()->first * gg2.rbegin()->first);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}