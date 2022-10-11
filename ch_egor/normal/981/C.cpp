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

int n;
int cnt[MAX_N];
vector<pair<int, int>> ans;

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

	for (int i = 0; i < n - 1; ++i)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		--v; --u;
		++cnt[v];
		++cnt[u];
	}

	int start = 0;
	int cnt_f = 0;
	for (int i = 0; i < n; ++i)
	{
		if (cnt[i] > 2)
		{
			++cnt_f;
			start = i;
		}
	}
	
	if (cnt_f > 1) return 0 * printf("No\n");
	
	for (int i = 0; i < n; ++i)
	{
		if (i == start) continue;
		if (cnt[i] == 1) ans.emplace_back(start, i);
	}
	
	printf("Yes\n");
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i)
	{
		printf("%d %d\n", ++ans[i].first, ++ans[i].second);
	}

	return 0;
}