/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int tree_x1[4 * N], tree_x2[4 * N], tree_y1[4 * N], tree_y2[4 * N];
int x1[N], x2[N], y1[N], y2[N];

void update(int* tree, int i, int l, int r, int p);
int query(int* tree, int i, int l, int r, int ql, int qr);

int main()
{
	int d, n, m;
	cin >> d >> n >> m;
	for (int i = 1; i <= d; ++i)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		if (x1[i] > x2[i] or y1[i] > y2[i])
		{
			swap(x1[i], x2[i]);
			swap(y1[i], y2[i]);
		}

		update(tree_x1, 1, 1, n, x1[i]);
		update(tree_x2, 1, 1, n, x2[i]);
		update(tree_y1, 1, 1, m, y1[i]);
		update(tree_y2, 1, 1, m, y2[i]);
	}

	int l, r, t, b;
	cin >> l >> r >> t >> b;
	for (int i = 1; i <= d; ++i)
	{
		if (query(tree_x1, 1, 1, n, 1, x2[i] - 1) != l + (x1[i] < x2[i]))
			continue;

		if (query(tree_x2, 1, 1, n, x1[i] + 1, n) != r + (x2[i] > x1[i]))
			continue;

		if (query(tree_y1, 1, 1, m, 1, y2[i] - 1) != t + (y1[i] < y2[i]))
			continue;

		if (query(tree_y2, 1, 1, m, y1[i] + 1, m) != b + (y2[i] > y1[i]))
			continue;

		cout << i;
		return 0;
	}

	cout << -1;
}

void update(int* tree, int i, int l, int r, int p)
{
	++tree[i];
	if (l == r)
		return;

	int mid = (l + r) / 2;
	if (p <= mid)
		update(tree, 2 * i, l, mid, p);

	else
		update(tree, 2 * i + 1, mid + 1, r, p);
}

int query(int* tree, int i, int l, int r, int ql, int qr)
{
	if (l > qr or ql > r)
		return 0;

	if (ql <= l and r <= qr)
		return tree[i];

	int mid = (l + r) / 2;
	return query(tree, 2 * i, l, mid, ql, qr) + query(tree, 2 * i + 1, mid + 1, r, ql, qr);
}