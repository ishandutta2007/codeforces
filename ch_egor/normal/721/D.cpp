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

const int MAX_N = 200 * 1000 + 5;

int n, k;
ll x;
ll arr[MAX_N];

ll my_abs(ll x)
{
	return (x > 0) ? x : -x;
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
    
	ll cnt_neg = 0;
	ll cnt_z = 0;
	ll max_neg = -INF;
	ll min_pos = INF;
    scanf("%d%d%lld", &n, &k, &x);
    for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &arr[i]);

		if (arr[i] == 0)
		{
			++cnt_z;
		}
		else if (arr[i] > 0)
		{
			min_pos = min(min_pos, arr[i]);
		}
		else if (arr[i] < 0)
		{
			max_neg = max(max_neg, arr[i]);
			++cnt_neg;
		}
	}

	if (cnt_z > k)
	{
		arr[0] = x * k + arr[0];
		for (int i = 0; i < n; ++i)
		{
			printf("%lld ", arr[i]);
		}
		return 0;
	}

	if (cnt_neg % 2 == 0)
	{
		if (cnt_z != 0)
		{
			for (int i = 0; i < n; ++i)
			{
				if (arr[i] == 0)
				{
					arr[i] -= x;
					--k;
					break;
				}
			}
		}
		else
		{
			if (my_abs(min_pos) < my_abs(max_neg))
			{
				for (int i = 0; i < n; ++i)
				{
					if (arr[i] == min_pos)
					{
						int need = (min_pos + x) / x;
						if (need > k)
						{
							arr[i] -= x * k;
							for (int i = 0; i < n; ++i)
							{
								printf("%lld ", arr[i]);
							}
							return 0;
						}
						else
						{
							k -= need;
							arr[i] -= x * need;
						}
						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < n; ++i)
				{
					if (arr[i] == max_neg)
					{
						int need = (-max_neg + x) / x;
						if (need > k)
						{
							arr[i] += x * k;
							for (int i = 0; i < n; ++i)
							{
								printf("%lld ", arr[i]);
							}
							return 0;
						}
						else
						{
							k -= need;
							arr[i] += x * need;
						}
						break;
					}
				}
			}

		}
	}

	if (true)
	{
		set<pair<ll, int> > gg;
		for (int i = 0; i < n; ++i)
		{
			gg.insert(make_pair(my_abs(arr[i]), i));
		}
		while (k--)
		{
			auto t1 = gg.begin();
			gg.erase(t1);
			if (arr[t1 -> second] < 0)
			{
				arr[t1 -> second] -= x;
			}
			else
			{
				arr[t1 -> second] += x;
			}
			gg.insert(make_pair(my_abs(arr[t1 -> second]), t1 -> second));
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		printf("%lld ", arr[i]);
	}

	return 0;
}