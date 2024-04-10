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
const int MAX_N = 2005;
const int MAX_DELTA = 5005;
const int ADD = 0;

int n;
int arr[MAX_N];
double dp[MAX_DELTA];
int cnt_delta[MAX_DELTA];
int all = 0;
int sums[MAX_DELTA];

int get_sum(int l, int r)
{
	if (l == 0)
	{
		return sums[r];
	}
	else
	{
		return sums[r] - sums[l - 1];
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < MAX_DELTA; ++i)
	{
		dp[i] = 0;
		cnt_delta[i] = 0;
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			++cnt_delta[arr[j] - arr[i]];
			++all;
		}
	}

	sums[0] = cnt_delta[0];
	for (int i = 1; i < MAX_DELTA; ++i)
	{
		sums[i] = sums[i - 1] + cnt_delta[i];
	}

	double80 answer = 0;
	double80 first, second;
	int next;
	for (int i = 0; i < MAX_DELTA; ++i)
	{
		for (int j = 0; j < MAX_DELTA; ++j)
		{
			if (cnt_delta[i] != 0 && cnt_delta[j] != 0)
			{
				first = cnt_delta[i] / (double80)all;
				second = cnt_delta[j] / (double80)all;
				next = i + j;

				if (next + 1 < MAX_DELTA)
				{
					answer += first*second*(get_sum(next + 1, MAX_DELTA - 1) / (double80)all);
				}
			}
		}
	}

	cout << fixed << setprecision(9) << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}