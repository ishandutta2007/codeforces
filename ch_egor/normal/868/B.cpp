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

const int MAX_N = 3600 * 12 + 228;
const int ADD = 3600 * 12;

bool gg[MAX_N * 5];

ll h, m, s, t1, t2;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	cin >> h >> m >> s >> t1 >> t2;
	h = (h % 12) * 3600 + m * 60 + s;
	t1 = (t1 % 12) * 3600;
	t2 = (t2 % 12) * 3600;
	m = (m * 60 + s) * 12;
	s *= 60 * 12;

	for (int i = 0; i < 3; ++i)
	{
		gg[h + i * ADD] = true;
		gg[m + i * ADD] = true;
		gg[s + i * ADD] = true;
	}
	
	for (int i = t1 + ADD; i < 3 * ADD; ++i)
	{
		if (i == t2 || i == t2 + ADD || i == t2 + 2 * ADD)
			return 0 * printf("YES\n");
		if (gg[i])
			break;
	}

	for (int i = t1 + ADD; i >= 0; --i)
	{
		if (i == t2 || i == t2 + ADD || i == t2 + 2 * ADD)
			return 0 * printf("YES\n");
		if (gg[i])
			break;
	}
	
	printf("NO\n");

	return 0;
}