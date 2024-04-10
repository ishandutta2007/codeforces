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

const int MAX_N = 1000 * 100 + 5;

int n, p;
pair<int, int> arr[MAX_N];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	
	
	ll ch = 0;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &arr[i].first, &arr[i].second);
		ch += arr[i].first;
	}
	
	long double l = 0;
	long double r = 10.0 * LLINF;
	for (int it = 0; it < 450; ++it)
	{
		long double m = (l + r) / 2.0;
		long double tm = 0;
		for (int i = 0; i < n; ++i)
			tm += max((long double)0.0, (m * arr[i].first - arr[i].second) / (long double)p);
		if (tm > m)
			r = m;
		else
			l = m;
	}
	
	if (ch <= p)
	{
		printf("-1\n");
	}
	else
	{
		cout << fixed;
		cout << setprecision(20);
		cout << l << endl;
	}

	return 0;
}