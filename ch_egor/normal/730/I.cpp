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

const int MAX_N = 228228;

#define x first
#define y second

int n, p, s;
pair<int, int> arr[MAX_N];
set<pair<int, int> > pp;
set<pair<int, int> > ss;
set<pair<int, int> > dd;
set<pair<int, int>> ans1;
set<pair<int, int>> ans2;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &p, &s);

	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i].x), pp.insert({arr[i].x, i});
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i].y), ss.insert({arr[i].y, i});

	int at;
	for (int i = 0; i < p; ++i)
	{
		ans1.insert(*(--pp.end()));
		at = (--pp.end())->y;
		dd.insert({arr[at].y - arr[at].x, at});
		pp.erase(--pp.end());
		ss.erase({arr[at].y, at});
	}

	int at1, at2;
	for (int i = 0; i < s; ++i)
	{
		if ((--pp.end())->x + (--dd.end())->x > (--ss.end())->x)
		{
			at1 = (--pp.end())->y;
			at2 = (--dd.end())->y;
			ans1.erase({arr[at2].x, at2});
			ans1.insert(*(--pp.end()));
			ans2.insert({arr[at2].y, at2});
			ss.erase({arr[at1].y, at1});
			ss.erase({arr[at2].y, at2});
			pp.erase(--pp.end());
			dd.erase(--dd.end());
			dd.insert({arr[at1].y - arr[at1].x, at1});
		}
		else
		{
			ans2.insert(*(--ss.end()));
			at = (--ss.end())->y;
			ss.erase(--ss.end());
			pp.erase({arr[at].x, at});
		}
	}

	int64 answer = 0;
	for (auto it = ans1.begin(); it != ans1.end(); ++it)
		answer += it->x;
	for (auto it = ans2.begin(); it != ans2.end(); ++it)
		answer += it->x;

	printf("%lld\n", answer);
	for (auto it = ans1.begin(); it != ans1.end(); ++it)
		printf("%d ", it->y + 1);
	printf("\n");
	for (auto it = ans2.begin(); it != ans2.end(); ++it)
		printf("%d ", it->y + 1);
	printf("\n");

	fclose(stdin);
	fclose(stdout);

	return 0;
}