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

struct ev
{
	ll x;
	int type;
};

bool operator<(const ev &a, const ev &b)
{
	return a.x < b.x;
}

int n;
ll ds;
ll arr1[MAX_N];
ll arr2[MAX_N];
vector<ev> now;

bool check(ll m)
{
	if (n == 1) 
	{
		int fr = arr1[0];
		int sc = arr2[0];
		if (abs(fr - sc) <= m || ds - abs(fr - sc) <= m) return true;
		else return false;
	}

	now.clear();
	int bl = 0;

	for (int i = 0; i < n; ++i)
	{
		ll l = (arr1[i] - m + ds) % ds;
		ll r = (arr1[i] + m) % ds;
		if (l <= r && l <= arr2[0] && arr2[n - 1] <= r)
		{
			++bl;
			continue;
		}
		if (l > r)
		{
			ll kek = upper_bound(arr2, arr2 + n, r) - arr2;
			if (kek == n || arr2[kek] >= l)
			{
				++bl;
				continue;
			}
		}
		
		ll lp = lower_bound(arr2, arr2 + n, l) - arr2;
		ll rp = upper_bound(arr2, arr2 + n, r) - arr2;
		if (lp == n) lp = 0;
		if (rp == n) rp = 0;

		if (l <= r && (arr2[lp] < l || arr2[lp] > r)) return false;
		else if (l > r && (l < arr2[lp] && arr2[lp] < r)) return false;
		
		lp = (lp - i + n) % n;
		rp = (rp - i + n) % n;
		if (rp < lp) ++bl;
		
		now.push_back({lp, 1});
		now.push_back({rp, -1});
	}
	
	sort(now.begin(), now.end());
	if (now[0].x != 0 && bl == n) return true;
	for (int i = 0; i < (int)now.size(); ++i)
	{
		bl += now[i].type;
		while (i < (int)now.size() - 1 && now[i + 1].x == now[i].x)
		{
			++i;
			bl += now[i].type;
		}

		if (bl == n) return true;
	}

	return false;
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

	scanf("%d%lld", &n, &ds);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr1[i]);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr2[i]);

	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);
	
	ll l = -1;
	ll r = ds / 2;

	while (r - l > 1)
	{
		ll m = (l + r) >> 1;
		if (check(m)) r = m;
		else l = m;
	}

	printf("%lld\n", r);

	return 0;
}