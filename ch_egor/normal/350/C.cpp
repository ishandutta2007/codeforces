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

const int MAX_N = 2000 * 100 + 5;

struct point
{
	int x;
	int y;
};

struct ans
{
	int type;
	int mm;
	char d;

	ans(int _type, int _mm, char _d)
	{
		type = _type;
		mm = _mm;
		d = _d;
	}
};

int n;
point arr[MAX_N];
vector<ans> answer;

int my_abs(int x)
{
	return (x > 0) ? x : -x;
}

bool cmp(const point &a, const point &b)
{
	return my_abs(a.x) + my_abs(a.y) < my_abs(b.x) + my_abs(b.y);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", &arr[i].x, &arr[i].y);

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; ++i)
	{
		if (arr[i].x != 0)
		{
			answer.push_back(ans(1, my_abs(arr[i].x), (arr[i].x > 0) ? 'R' : 'L'));
		}
		if (arr[i].y != 0)
		{
			answer.push_back(ans(1, my_abs(arr[i].y), (arr[i].y > 0) ? 'U' : 'D'));
		}

		answer.push_back(ans(2, 0, 0));
		if (arr[i].x != 0)
		{
			answer.push_back(ans(1, my_abs(arr[i].x), (arr[i].x < 0) ? 'R' : 'L'));
		}
		if (arr[i].y != 0)
		{
			answer.push_back(ans(1, my_abs(arr[i].y), (arr[i].y < 0) ? 'U' : 'D'));
		}
		answer.push_back(ans(3, 0, 0));
	}

	printf("%d\n", (int)answer.size());
	
	for (int i = 0; i < answer.size(); ++i)
	{
		if (answer[i].type == 1)
		{
			printf("%d %d %c\n", answer[i].type, answer[i].mm, answer[i].d);
		}
		else
		{
			printf("%d\n", answer[i].type);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}