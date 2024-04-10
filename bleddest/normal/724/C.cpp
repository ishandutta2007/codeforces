#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>

using namespace std;

const long long INFLL = 1e18;

int n, m;

struct state
{
	int x;
	int y;
	int dx;
	int dy;
	state() {};
	state(int x, int y, int dx, int dy) : x(x), y(y), dx(dx), dy(dy) {};
};

bool operator <(const state& a, const state& b)
{
	if (a.x != b.x)
		return a.x < b.x;
	if (a.y != b.y)
		return a.y < b.y;
	if (a.dx != b.dx)
		return a.dx < b.dx;
	return a.dy < b.dy;
}

map<state, long long> d;

pair<state, int> advance(state& a)
{
	int cx = a.x, cy = a.y;
	if (a.dx > 0) cx = n - a.x;
	if (a.dy > 0) cy = m - a.y;
	int curd = min(cx, cy);
	state nw(a.x + a.dx * curd, a.y + a.dy * curd, a.dx, a.dy);
	if (nw.x == 0 || nw.x == n)
		nw.dx *= -1;
	if (nw.y == 0 || nw.y == m)
		nw.dy *= -1;
	return make_pair(nw, curd);
}

long long get_state(int x, int y, int dx, int dy)
{
	int cx = x, cy = y;
	if (dx > 0) cx = n - x;
	if (dy > 0) cy = m - y;
	int cd = min(cx, cy);
	int nx = x + dx * cd;
	int ny = y + dy * cd;
	if (d.count(state(nx, ny, -dx, -dy)))
		return d[state(nx, ny, -dx, -dy)] + cd;
	else
		return INFLL;
}

long long ans(int x, int y)
{
	long long res = INFLL;
	res = min(res, get_state(x, y, 1, 1));
	res = min(res, get_state(x, y, -1, 1));
	res = min(res, get_state(x, y, 1, -1));
	res = min(res, get_state(x, y, -1, -1));
	return res;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &m);
	d[state(0, 0, 1, 1)] = 0;
	queue<state> q;
	q.push(state(0, 0, 1, 1));
	while (!q.empty())
	{
		state z = q.front();
		q.pop();
		auto nz = advance(z);
		if (!d.count(nz.first))
		{
			q.push(nz.first);
			d[nz.first] = d[z] + nz.second;
		}
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int xx, yy;
		scanf("%d %d", &xx, &yy);
		long long cur = ans(xx, yy);
		if (cur == INFLL)
			cur = -1;
		printf("%I64d\n", cur);
	}
	return 0;
}