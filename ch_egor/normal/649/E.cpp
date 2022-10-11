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

struct point
{
	int64 x;
	int64 d;
	int number;

	point()
	{
	}
	point(int64 _x, int64 _d)
	{
		x = _x;
		d = _d;
	}
};

bool operator<(const point &a, const point &b)
{
	return a.x < b.x || (a.x == b.x && a.d < b.d);
}

int n;
int64 a;
point arr[200228];
set<point> end_of;
set<point> now;

bool check(int x)
{
	end_of.clear();
	now.clear();

	for (int i = 0; i < n; ++i)
	{
		while (!end_of.empty() && end_of.begin()->x <= arr[i].x)
		{
			end_of.erase(end_of.begin());
		}
		if (end_of.size() < x)
		{
			end_of.insert(point(arr[i].x + arr[i].d, arr[i].number));
			now.insert(point(arr[i].x + arr[i].d, arr[i].number));
		}
		else
		{
			if (arr[i].x + arr[i].d < end_of.rbegin()->x)
			{
				now.erase(*end_of.rbegin());
				end_of.erase(--end_of.end());
				end_of.insert(point(arr[i].x + arr[i].d, arr[i].number));
				now.insert(point(arr[i].x + arr[i].d, arr[i].number));
			}
		}
	}

	return now.size() >= a;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %I64d", &n, &a);

	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d %I64d", &arr[i].x, &arr[i].d);
		arr[i].number = i + 1;
	}

	sort(arr, arr + n);

	int l = 0;
	int r = 200228;
	int m = 0;
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

	int cnt = 0;
	printf("%d\n", r);
	check(r);
	for (auto it = now.begin(); it != now.end(); ++it)
	{
		++cnt;
		printf("%I64d ", it->d);
		if (cnt == a)
		{
			break;
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}