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

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 100 * 1000 + 5;

int n, q;
double arr[MAX_N];
double tree[4 * MAX_N];
double mod[4 * MAX_N];
double mul[4 * MAX_N];

void add(int v, int l, int r, double x)
{
	mod[v] += x;
	tree[v] += (r - l) * x;
}

void mull(int v, int l, int r, double x)
{
	mul[v] *= x;
	tree[v] *= x;
	mod[v] *= x;
}

void push(int v, int l, int r)
{
	int m = (l + r) >> 1;
	mull(2 * v + 1, l, m, mul[v]);
	mull(2 * v + 2, m, r, mul[v]);
	mul[v] = 1;
	add(2 * v + 1, l, m, mod[v]);
	add(2 * v + 2, m, r, mod[v]);
	mod[v] = 0;
}

void build(int v, int l, int r)
{
	if (r - l == 1)
	{
		tree[v] = arr[l];
		mul[v] = 1;
		mod[v] = 0;
	}
	else
	{
		int m = (l + r) >> 1;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);

		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
		mul[v] = 1;
		mod[v] = 0;
	}
}

double get(int v, int l, int r, int x, int y)
{
	if (r <= x || y <= l) return 0;
	else if (x <= l && r <= y) return tree[v];
	else
	{
		push(v, l, r);
		int m = (l + r) >> 1;
		return get(2 * v + 1, l, m, x, y) + get(2 * v + 2, m, r, x, y);
	}
}

void upd(int v, int l, int r, int x, int y, double xx)
{
	if (r <= x || y <= l) return;
	else if (x <= l && r <= y) mull(v, l, r, xx);
	else
	{
		push(v, l, r);
		int m = (l + r) >> 1;
		upd(2 * v + 1, l, m, x, y, xx);
		upd(2 * v + 2, m, r, x, y, xx);

		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}
}

void add(int v, int l, int r, int x, int y, double xx)
{
	if (r <= x || y <= l) return;
	else if (x <= l && r <= y) add(v, l, r, xx);
	else
	{
		push(v, l, r);
		int m = (l + r) >> 1;
		add(2 * v + 1, l, m, x, y, xx);
		add(2 * v + 2, m, r, x, y, xx);

		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%d", &n, &q);

	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		arr[i] = x;
	}

	build(0, 0, n);

	for (int i = 0; i < q; ++i)
	{
		int type, l1, r1, l2, r2;
		scanf("%d%d%d", &type, &l1, &r1);
		--l1; --r1;	
		if (type == 1)
		{
			scanf("%d%d", &l2, &r2);
			--l2; --r2;
		
			double lf = get(0, 0, n, l1, r1 + 1);
			double rf = get(0, 0, n, l2, r2 + 1);
			double len1 = r1 - l1 + 1;
			double len2 = r2 - l2 + 1;
			
			upd(0, 0, n, l1, r1 + 1, (len1 - 1) / len1);
			upd(0, 0, n, l2, r2 + 1, (len2 - 1) / len2);

			add(0, 0, n, l1, r1 + 1, rf / (len1 * len2));
			add(0, 0, n, l2, r2 + 1, lf / (len1 * len2));
		}
		else
		{
			printf("%.10lf\n", get(0, 0, n, l1, r1 + 1));
		}
	}

	return 0;
}