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

const int MAX_N = 1005;

struct point
{
	ll x;
	ll y;
};

int n;
point arr[MAX_N];

struct line
{
	ll a;
	ll b;
	ll c;
};

line make_line(point a, point b)
{
	line ans;
	ans.a = a.y - b.y;
	ans.b = b.x - a.x;
	ans.c = a.x * b.y - a.y * b.x;

	return ans;
}

long double get_dist(line a, point b)
{
	long double ans = abs(a.a * b.x + a.b * b.y + a.c) / sqrtl(a.a * a.a + a.b * a.b);
	return ans;
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

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld %lld", &arr[i].x, &arr[i].y);
	}
	arr[n] = arr[0];
	arr[n + 1] = arr[1];
	arr[n + 2] = arr[2];

	long double ans = LLINF;
	for (int i = 0; i <= n; ++i)
	{
		line gg = make_line(arr[i], arr[i + 2]);
		ans = min(ans, get_dist(gg, arr[i + 1]) / 2.0);
	}

	cout << fixed;
	cout << setprecision(20);
	cout << ans;

	return 0;
}