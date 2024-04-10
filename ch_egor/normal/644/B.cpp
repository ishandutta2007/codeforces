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
const int MAX_N = 200 * 1000 + 5;

struct ev
{
	int64 number;
	int64 start_time;
	int64 need_time;

	ev(int64 _number, int64 _start_time, int64 _need_time)
	{
		number = _number;
		start_time = _start_time;
		need_time = _need_time;
	}
};

int n, b;
int64 answer[MAX_N];
deque<ev> arr;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &b);

	b += 1;
	int64 time, exp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d %I64d", &time, &exp);

		while (!arr.empty() && arr.front().start_time + arr.front().need_time <= time)
		{
			answer[arr.front().number] = arr.front().start_time + arr.front().need_time;
			arr.pop_front();
		}

		if (arr.size() < b)
		{
			if (arr.empty())
			{
				arr.push_back(ev(i, time, exp));
			}
			else
			{
				arr.push_back(ev(i, arr.back().start_time + arr.back().need_time, exp));
			}
		}
		else
		{
			answer[i] = -1;
		}
	}

	while (!arr.empty())
	{
		answer[arr.front().number] = arr.front().start_time + arr.front().need_time;
		arr.pop_front();
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%I64d ", answer[i]);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}