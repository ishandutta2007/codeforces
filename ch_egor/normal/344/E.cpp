#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1000 * 100 + 5;

int n, m;
int64 arr1[MAX_N];
int64 arr2[MAX_N];
bool used[MAX_N];

int64 my_abs(int64 x)
{
	return ((x > 0) ? x : -x);
}

bool check(int64 x)
{
	int ptr = 0, ptr_at;

	int ptr1, ptr2;

	int64 need;
	for (int i = 0; i < n; ++i)
	{
		if (ptr == m)
		{
			break;
		}

		if (arr2[ptr] >= arr1[i])
		{
			ptr = upper_bound(arr2, arr2 + m, arr1[i] + x) - arr2;
		}
		else
		{
			need = arr1[i] - arr2[ptr];

			if (need > x)
			{
				return 0;
			}
			else if (2 * need >= x)
			{
				ptr = max(upper_bound(arr2, arr2 + m, arr1[i]) - arr2,
					      upper_bound(arr2, arr2 + m, arr1[i] + ((x - need) >> 1)) - arr2);
			}
			else
			{ 
				ptr = max(upper_bound(arr2, arr2 + m, arr1[i] + ((x - need) >> 1)) - arr2,
					      upper_bound(arr2, arr2 + m, arr1[i] + x - 2 * need) - arr2);
			}
		}
	}

	return ptr == m;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d", &arr1[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%I64d", &arr2[i]);
	}

	int64 l = -1;
	int64 r = LLINF;
	int64 m;

	while (r - l > 1)
	{
		m = (l + r) >> 1;
		if (check(m))
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}


	cout << r;

	fclose(stdin);
	fclose(stdout);

	return 0;
}