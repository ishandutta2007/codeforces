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

const int MAX_N = 100 * 1000 + 228;


int n, m;
ll arr[MAX_N];
pair<ll, ll> gg[MAX_N];
vector<ll> ls;
multiset<ll> ff;

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

	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	for (int i = 0; i < m; ++i) scanf("%lld", &gg[i].first);
	for (int i = 0; i < m; ++i) scanf("%lld", &gg[i].second);
	
	sort(gg, gg + m);

	arr[n] = 0;
	ls.push_back(n);
	for (int i = n - 1; i >= 0; --i)
	{
		if (arr[i] > arr[ls.back()]) ls.push_back(i);
	}
	
	int ptr = m - 1;
	while (ptr >= 0 && gg[ptr].first > arr[ls.back()]) --ptr;
	
	ll now = 0;
	for (int i = 0; i < n; ++i)
	{
		now += arr[i];
		if (i != ls.back()) continue;
		ls.pop_back();

		while (ptr >= 0 && gg[ptr].first > arr[ls.back()])
		{
			ff.insert(gg[ptr].second);
			now -= gg[ptr].second;
			--ptr;
		}

		while (now < 0)
		{
			now += *ff.rbegin();
			ff.erase(--ff.end());
		}
	}
	
	printf("%d\n", (int)ff.size());

	return 0;
}