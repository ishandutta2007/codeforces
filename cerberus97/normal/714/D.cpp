/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <pii, pii> rectangle;

const int N = 1e5 + 5;

bool found = false;
rectangle ans[2];

void find_rectangle(int n, int i);
int query(rectangle r);
bool is_enclosed(rectangle r1, rectangle r2);

int main()
{
	int n;
	scanf("%d", &n);
	find_rectangle(n, 0);
	found = true;
	find_rectangle(n, 1);
	printf("! ");
	for (int i = 0; i < 2; ++i)
		printf("%d %d %d %d%c", ans[i].x1, ans[i].y1, ans[i].x2, ans[i].y2, " \n"[i]);

	fflush(stdout);
}

void find_rectangle(int n, int i)
{
	ans[i] = {{1, 1}, {n, n}};
	int l = 2, r = n;
	while (l <= r)
	{
		int mid = ans[i].x1 = (l + r) / 2;
		if (query(ans[i]))
			l = mid + 1;
		else
			r = mid - 1;
	}

	ans[i].x1 = l - 1;
	l = ans[i].x1, r = n - 1;
	while (l <= r)
	{
		int mid = ans[i].x2 = (l + r) / 2;
		if (query(ans[i]))
			r = mid - 1;
		else
			l = mid + 1;
	}

	ans[i].x2 = r + 1;
	l = 2, r = n;
	while (l <= r)
	{
		int mid = ans[i].y1 = (l + r) / 2;
		if (query(ans[i]))
			l = mid + 1;
		else
			r = mid - 1;
	}

	ans[i].y1 = l - 1;
	l = ans[i].y1, r = n - 1;
	while (l <= r)
	{
		int mid = ans[i].y2 = (l + r) / 2;
		if (query(ans[i]))
			r = mid - 1;
		else
			l = mid + 1;
	}

	ans[i].y2 = r + 1;
}

int query(rectangle r)
{
	int res = 0;
	printf("? %d %d %d %d\n", r.x1, r.y1, r.x2, r.y2);
	fflush(stdout);
	scanf("%d", &res);
	if (found and is_enclosed(ans[0], r))
		--res;

	return res;
}

bool is_enclosed(rectangle r1, rectangle r2)
{
	return (r2.x1 <= r1.x1 and r2.y1 <= r1.y1 and r2.x2 >= r1.x2 and r2.y2 >= r1.y2);
}