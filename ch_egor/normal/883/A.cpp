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

ll n, m, a, d;
ll arr[MAX_N];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif
	
	scanf("%lld%lld%lld%lld", &n, &m, &a, &d);

	for (int i = 0; i < m; ++i)
	{
		scanf("%lld", &arr[i]);
	}
	
	arr[m] = 6e18;
	++m;
	sort(arr, arr + m);

	int ptr = 0;
	ll a_ptr = 1;

	ll last_cl = 0;
	ll ans = 0;
	while (ptr < m && a_ptr <= n)
	{
		if (arr[ptr] <= a_ptr * a)
		{
			if (ptr == m) break;
			if (last_cl < arr[ptr])
			{
				++ans;
				last_cl = arr[ptr] + d;
			}
			++ptr;
		}
		else
		{
			if (last_cl < a * a_ptr)
			{
				
				ll pt_ps = min(n, arr[ptr] / a);
				
				ll block = (d + 1 + a - 1) / a;
				
				if (block != 0)
				{
					ll df = pt_ps - a_ptr + 1;
					ll cnt = (df + block - 1) / block;
					ans += cnt;
					a_ptr += (cnt - 1) * block;
					last_cl = a * a_ptr + d; 
				}
				else
				{
					ans += pt_ps - a_ptr + 1;
					last_cl = pt_ps * a + d;
				}
				a_ptr = pt_ps + 1;
			}
			else
			{
				ll pt_ps = min(n, arr[ptr] / a);
				ll last_ps = min(n, last_cl / a);
				
				if (last_ps < pt_ps)
				{
					a_ptr = last_ps + 1;
				}
				else
				{
					a_ptr = pt_ps + 1;
				}
			}
		}
	}
	
	--m;
	while (ptr < m)
	{
		if (last_cl < arr[ptr])
		{
			++ans;
			last_cl = arr[ptr] + d;
		}
		++ptr;
	}

	printf("%lld\n", ans);

	return 0;
}