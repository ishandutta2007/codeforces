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

const int MAX_N = 200 * 1000 + 228;

int n, k, m;
ll t;
int a, b;
int arr[MAX_N];
set<pair<int, pair<ll, int>>> now;
set<pair<ll, pair<int, pair<ll, int>>>> gg;


void upd(set<pair<int, pair<ll, int>>>::iterator &k)
{
	pair<int, pair<ll, int>> nx;
	nx = *k;
	now.erase(k);
	printf("%d %lld\n", nx.second.second + 1, max(0ll, nx.second.first - t) + abs(nx.first - a));
	nx.second.first = max(nx.second.first, t) + abs(nx.first - a) + abs(b - a);
	nx.first = b;
	gg.insert({nx.second.first, nx});
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

	scanf("%d%d%d", &n, &k, &m);

	for (int i = 0; i < k; ++i) 
	{
		scanf("%d", &arr[i]);
		now.insert({arr[i], {0, i}});
	}

	while (m--)
	{
		scanf("%lld%d%d", &t, &a, &b);
		
		while (!gg.empty() && gg.begin()->first <= t)
		{
			now.insert(gg.begin()->second);
			gg.erase(gg.begin());
		}
		
		if (now.empty())
		{
			ll ff = gg.begin()->first;
			while (!gg.empty() && gg.begin()->first <= ff)
			{
				now.insert(gg.begin()->second);
				gg.erase(gg.begin());
			}
		}
		
		auto it = now.lower_bound({a, {-1, -1}});
		int on_it = ((it == now.end()) ? INF : it->first);
		int on_last = -INF;
		auto lla = it;

		if (it != now.begin())
		{
			auto prev = it;
			--prev;
			
			on_last = prev->first;
			lla = now.lower_bound({on_last, {-1, -1}});
		}
		
		if (on_last != -INF && on_it != INF && abs(on_last - a) == abs(on_it - a))
		{
			if (lla->second < it->second)
			{
				upd(lla);
			}
			else
			{
				upd(it);
			}
		}
		else if (abs(on_last - a) <= abs(on_it - a))
		{
			upd(lla);
		}
		else
		{
			upd(it);
		}
	}

	return 0;
}