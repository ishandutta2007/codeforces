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

const int MAX_N = 1000 * 100 + 5;

int n;
int64 arr[MAX_N];
set<pair<int, pair<int, int64> > > gg;
multiset<int64> ans;
int64 sums[MAX_N];

int64 get(int l, int r)
{
	if (r <= 0)
	{
		return 0;
	}
	if (l <= 0)
	{
		return sums[r - 1];
	}
	else
	{
		return sums[r - 1] - sums[l - 1];
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &arr[i]);
	}

	sums[0] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		sums[i] = sums[i - 1] + arr[i];
	}

	int64 sum = 0;
	for (int i = 0; i < n; ++i)
		sum += arr[i];
	gg.insert(make_pair(0, make_pair(n, sum)));
	ans.insert(sum);
	int v;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v);
		--v;
		auto pt1 = gg.upper_bound(make_pair(v, make_pair(v, -LLINF)));

		if (pt1 == gg.end())
		{
			--pt1;
		}
		if (pt1->first > v)
		{
			--pt1;
		}

		auto pt = *pt1;
		gg.erase(pt1);
		ans.erase(ans.find(pt.second.second));
		//cerr << "GG" << endl;
		pair<int, pair<int, int64> > l = make_pair(pt.first, make_pair(v, get(pt.first, v)));
		pair<int, pair<int, int64> > r = make_pair(v + 1, make_pair(pt.second.first, get(v + 1, pt.second.first)));
		ans.insert(get(pt.first, v));
		ans.insert(get(v + 1, pt.second.first));
		gg.insert(l);
		gg.insert(r);

		//for (auto it = gg.begin(); it != gg.end(); ++it)
		//{
		//	cout << it->first << " " << it->second.first << " " << it->second.second << endl;
		//}

		printf("%lld\n", *ans.rbegin());
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}