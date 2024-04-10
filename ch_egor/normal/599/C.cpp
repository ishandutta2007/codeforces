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
const int64 LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 2000 * 100 + 5;

struct point
{
	int x;
	int y;

	point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

int n;
int arr[MAX_N];
int cpy_arr[MAX_N];
map<int, int> min_at;
map<int, int> max_at;
map<int, int> last;
map<int, int> first;
vector<point> line;
stack<point> answer;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		cpy_arr[i] = arr[i];
	}

	sort(cpy_arr, cpy_arr + n);

	for (int i = 0; i < n; ++i)
	{
		if (min_at.find(cpy_arr[i]) == min_at.end())
		{
			min_at[cpy_arr[i]] = i;
		}
		max_at[cpy_arr[i]] = i;
	}

	int start = 0;
	int next = 0;
	for (int i = 0; i < n; ++i)
	{
		if (min_at[arr[i]] > next)
		{
			next = min_at[arr[i]];
			++min_at[arr[i]];
		}
		if (max_at[arr[i]] < start)
		{
			start = max_at[arr[i]];
			--max_at[arr[i]];
		}
		if (next == i)
		{
			line.push_back(point(start, next));
			start = i + 1;
			next = i + 1;
		}
	}

	for (int i = 0; i < line.size(); ++i)
	{
		while (answer.size() > 0 && line[i].x <= answer.top().y)
		{
			answer.pop();
		}
		answer.push(line[i]);
	}

	printf("%d", (int)answer.size());

	fclose(stdin);
	fclose(stdout);

	return 0;
}