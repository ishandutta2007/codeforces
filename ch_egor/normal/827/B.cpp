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

int n, m;

#define ends ksjfsdk22234

vector<pair<int, int>> ans;
vector<int> ends;

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
	
	int root = 1;
	
	int per1 = (n - 1) / m;
	int ptr = 2;
	int ost = n - 1 - m * per1;
	for (int i = 0; i < m; ++i)
	{
		ans.push_back({root, ptr});
		++ptr;
		for (int j = 1; j < per1; ++j)
		{
			ans.push_back({ptr - 1, ptr});
			++ptr;
		}
		ends.push_back(ptr - 1);
	}

	
	if (ost)
	{
		for (int i = 0; i < ost; ++i)
		{
			ans.push_back({ends[i], ptr});
			++ptr;
		}
	}
	
	if (ost == 0)
	{
		printf("%d\n", 2 * per1);
	}
	else if (ost == 1)
	{
		printf("%d\n", 2 * per1 + 1);
	}
	else
	{
		printf("%d\n", 2 * per1 + 2);
	}
	
	for (int i = 0; i < (int)ans.size(); ++i)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}	

	return 0;
}