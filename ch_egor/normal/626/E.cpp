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
const int MAX_N = 200005;

int n;
double80 answer = 0.0;
vector<int64> ans_arr;
int64 arr[MAX_N];
int64 sums[MAX_N];
int answer_at = -1;

int64 get_sum(int l, int r)
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

void try_one(int x, int delta, int at, bool restote)
{
	if (delta < 0) return;
	int l = 0;
	int r = delta;
	int x1, x2;

	while (r - l > 3)
	{
		x1 = (2 * l + r) / 3;
		x2 = (l + 2 * r) / 3;

		if ((get_sum(at - x1, at) + get_sum(n - x1 - 1, n - 1) + x) / (double80)(2 * (x1 + 1) + 1) - x >
			(get_sum(at - x2, at) + get_sum(n - x2 - 1, n - 1) + x) / (double80)(2 * (x2 + 1) + 1) - x)
		{
			r = x2;
		}
		else
		{
			l = x1;
		}
	}

	for (int i = l; i <= r; ++i)
	{
		if ((get_sum(at - i, at) + get_sum(n - i - 1, n - 1) + x) / (double80)(2 * (i + 1) + 1) - x >= answer)
		{
			answer = (get_sum(at - i, at) + get_sum(n - i - 1, n - 1) + x) / (double80)(2 * (i + 1) + 1) - x;
			answer_at = at + 1;
			if (restote)
			{
				ans_arr.clear();
				for (int j = at - i; j <= at; ++j)
				{
					ans_arr.push_back(arr[j]);
				}
				ans_arr.push_back(x);
				for (int j = n - i - 1; j < n; ++j)
				{
					ans_arr.push_back(arr[j]);
				}
			}
		}
	}
}

void try_two(int x, int y, int delta, int at, bool restore)
{
	if (delta < 0) return;
	int l = 0;
	int r = delta;
	int x1, x2;

	while (r - l > 3)
	{
		x1 = (2 * l + r) / 3;
		x2 = (l + 2 * r) / 3;

		if ((get_sum(at - x1, at) + get_sum(n - x1 - 1, n - 1) + x + y) / (double80)(2 * (x1 + 1) + 2) - (x + y) / 2.0 >
			(get_sum(at - x1, at) + get_sum(n - x2 - 1, n - 1) + x + y) / (double80)(2 * (x2 + 1) + 2) - (x + y) / 2.0)
		{
			r = x2;
		}
		else
		{
			l = x1;
		}
	}

	for (int i = l; i <= r; ++i)
	{
		if ((get_sum(at - i, at) + get_sum(n - i - 1, n - 1) + x + y) / (double80)(2 * (i + 1) + 2) - (x + y)/2.0 >= answer)
		{
			answer = (get_sum(at - i, at) + get_sum(n - i - 1, n - 1) + x + y) / (double80)(2 * (i + 1) + 2) - (x + y) / 2.0;
			answer_at = at + 1;

			if (restore)
			{
				ans_arr.clear();
				for (int j = at - i; j <= at; ++j)
				{
					ans_arr.push_back(arr[j]);
				}
				ans_arr.push_back(x);
				ans_arr.push_back(y);
				for (int j = n - i - 1; j < n; ++j)
				{
					ans_arr.push_back(arr[j]);
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d", &arr[i]);
	}
	sort(arr, arr + n);

	sums[0] = arr[0];
	ans_arr.push_back(arr[0]);
	for (int i = 1; i < n; ++i)
	{
		sums[i] = sums[i - 1] + arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		try_one(arr[i], min(i - 1, n - i - 2), i - 1, false);
	}
	for (int i = 0; i < n - 1; ++i)
	{
		try_two(arr[i], arr[i + 1], min(i - 1, n - i - 3), i - 1, false);
	}

	if (answer_at != -1)
	{
		try_one(arr[answer_at], min(answer_at - 1, n - answer_at - 2), answer_at - 1, true);
		try_two(arr[answer_at], arr[answer_at + 1], min(answer_at - 1, n - answer_at - 3), answer_at - 1, true);
	}

	//cout << answer << endl;
	printf("%d\n", (int)ans_arr.size());
	for (int i = 0; i < ans_arr.size(); ++i)
	{
		printf("%I64d ", ans_arr[i]);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}