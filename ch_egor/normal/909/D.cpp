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

const int MAX_N = 1000 * 1000 + 228;

int n;
char st[MAX_N];
vector<pair<int, int>> gg;
vector<pair<int, int>> gg2;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%s", st);
	n = strlen(st);

	gg.push_back({st[0], 1});

	for (int i = 1; i < n; ++i)
	{
		if (st[i] == gg.back().first) ++gg.back().second;
		else gg.push_back({st[i], 1});
	}
	
	int ans = 0;
	while (gg.size() > 1)
	{
		++ans;
		for (int i = 0; i < (int)gg.size(); ++i)
		{
			auto now = gg[i];
			if (i == 0 || i == (int)gg.size() - 1) --now.second;
			else now.second -= 2;

			if (now.second > 0 && gg2.size() && gg2.back().first == now.first) gg2.back().second += now.second;
			else if (now.second > 0) gg2.push_back(now);
			
		}
		gg.clear();
		gg2.swap(gg);
	}

	printf("%d\n", ans);

	return 0;
}