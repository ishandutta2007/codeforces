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

const int MAX_N = 50005;

int n;
int64 arr[MAX_N];

int64 get(int64 x)
{
	if (x == 1)
	{
		return x;
	}
	if (x & 1)
	{
		return get((x - 1) / 2);
	}
}

map<int64, int64> to_ch;
vector<int64> ans;
bool check(int64 m)
{
	to_ch.clear();
	ans.clear();
	for (int i = 0; i < n; ++i)
	{
		++to_ch[arr[i]];
	}
	while (!to_ch.empty() && to_ch.rbegin()->first >= 2)
	{
		if (to_ch.rbegin()->second > 1)
		{
			++to_ch[to_ch.rbegin()->first / 2];
			--to_ch[to_ch.rbegin()->first];
		}
		else if (to_ch.rbegin()->second == 1)
		{
			if (to_ch.rbegin()->first > m)
			{
				++to_ch[to_ch.rbegin()->first / 2];
				//--to_ch[to_ch.rbegin()->first];
				to_ch.erase(--to_ch.end());
			}
			else
			{
				ans.push_back(to_ch.rbegin()->first);
				to_ch.erase(--to_ch.end());
			}
		}
	}

	if (to_ch.empty())
	{
		return true;
	}
	else if (to_ch.begin()->second > 1)
	{
		return false;
	}
	else
	{
		ans.push_back(1);
		return true;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    set<int> gg;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &arr[i]);
		gg.insert(arr[i]);
	}
    
	while (true)
	{
	    int x = *gg.rbegin();
		int y = x;
		while (gg.find(y) != gg.end()) y /= 2;
		if (y == 0) break;
	    gg.erase(x);
		gg.insert(y);
	}
	for (auto it = gg.begin(); it != gg.end(); ++it)
		printf("%d ", *it);

	fclose(stdin);
	fclose(stdout);

	return 0;
}