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

ll f, T, t;
ll a, ta, pa;
ll b, tb, pb;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%lld%lld%lld", &f, &T, &t);
	scanf("%lld%lld%lld", &a, &ta, &pa);
	scanf("%lld%lld%lld", &b, &tb, &pb);

	ll ans = 8e18;
	for (int i = 0; i <= 1.5e7; ++i)
	{
		ll buy = a * i;
		if (buy >= f && f * ta <= T)
		{
			ans = min(ans, pa * i);
			break;
		}

		if (buy >= f)
		{
			break;
		}

		ll cur_time = T - buy * ta;
		ll cur_need = f - buy;

		if (min(tb, t) * cur_need > cur_time) continue;
		if (t <= tb || t * cur_need <= cur_time)
		{
			if (t * cur_need <= cur_time) ans = min(ans, pa * i);
		}
		else if (t > tb)
		{
			ll diff = -cur_time + t * cur_need;
			ll add = -tb + t;
			ll fuck = (diff + add - 1) / add;
			ll cur_fuck = (fuck + b - 1) / b;
			ans = min(ans, pa * i + cur_fuck * pb);
		}
	}
	swap(ta, tb);
	swap(pa, pb);
	swap(a, b);
	for (int i = 0; i <= 1.5e7; ++i)
	{
		ll buy = a * i;
		if (buy >= f && f * ta <= T)
		{
			ans = min(ans, pa * i);
			break;
		}

		if (buy >= f)
		{
			break;
		}

		ll cur_time = T - buy * ta;
		ll cur_need = f - buy;

		if (min(tb, t) * cur_need > cur_time) continue;
		if (t <= tb || t * cur_need <= cur_time)
		{
			if (t * cur_need <= cur_time) ans = min(ans, pa * i);
		}
		else if (t > tb)
		{
			ll diff = -cur_time + t * cur_need;
			ll add = -tb + t;
			ll fuck = (diff + add - 1) / add;
			ll cur_fuck = (fuck + b - 1) / b;
			ans = min(ans, pa * i + cur_fuck * pb);
		}
	}

	if (ans == 8e18)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n", ans);
	}

	return 0;
}