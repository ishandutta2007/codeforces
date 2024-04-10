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

int64 n, l, r;
map<int64, int64> mem;
map<int64, int64> cnt;

int64 do_of(int64 n)
{
	if (n == 0)
	{
		cnt[n] = 0;
		return 1;
	}
	else if (n == 1)
	{
		cnt[n] = 1;
		return 1;
	}
	else
	{
		if (mem.find(n) != mem.end())
		{
			return mem[n];
		}
		mem[n] = 2 * do_of(n / 2) + 1;
		cnt[n] = cnt[n / 2] * 2 + (n % 2);
		return mem[n];
	}
}

int64 go(int64 n, int64 l1, int64 r1, int64 l, int64 r)
{
	if (l <= l1 && r1 <= r)
	{
		return cnt[n];
	}
	else if (r1 < l || r < l1)
	{
		return 0;
	}
	else
	{
		return go(n / 2, l1, l1 + do_of(n / 2) - 1, l, r) +
			go(n % 2, l1 + do_of(n / 2), l1 + do_of(n / 2), l, r) +
			go(n / 2, l1 + do_of(n / 2) + 1, r1, l, r);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> l >> r;

	do_of(0);
	do_of(1);
	cout << go(n, 1, do_of(n), l, r);

	fclose(stdin);
	fclose(stdout);

	return 0;
}