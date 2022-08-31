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

int a[N], tree[4 * N] = {0};
vector <pii> v;

int query(int l, int r, int n);
int query_tree(int i, int l, int r, int ql, int qr);
void update_tree(int i, int l, int r, int p, int x);

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		v.pb({a[i], i});
		update_tree(1, 1, n, i, 1);
	}

	sort(v.begin(), v.end());
	int st = 1, l = 0, r = 0;
	ll ans = 0;
	while (l < n)
	{
		while (r + 1 < n and v[r + 1].first == v[l].first)
			++r;

		int pos = v[l].second;
		for (int i = l + 1; i <= r; ++i)
		{
			int cur = v[i].second;
			if (cur < st and pos >= st)
				pos = cur;

			else if (cur < st and pos < st and cur > pos)
				pos = cur;

			else if (cur >= st and pos >= st and cur > pos)
				pos = cur;
		}

		ans += query(st, pos, n);
		for (int i = l; i <= r; ++i)
			update_tree(1, 1, n, v[i].second, -1);

		st = pos + 1;
		if (st == n + 1)
			st = 1;

		l = r + 1;
		r = l;
	}

	cout << ans;
}

int query(int l, int r, int n)
{
	if (l <= r)
		return query_tree(1, 1, n, l, r);

	return query_tree(1, 1, n, l, n) + query_tree(1, 1, n, 1, r);
}

int query_tree(int i, int l, int r, int ql, int qr)
{
	if (l > qr or ql > r)
		return 0;

	if (ql <= l and r <= qr)
		return tree[i];

	int mid = (l + r) / 2;
	return query_tree(2 * i, l, mid, ql, qr) + query_tree(2 * i + 1, mid + 1, r, ql, qr);
}

void update_tree(int i, int l, int r, int p, int x)
{
	tree[i] += x;
	if (l == r)
		return;

	int mid = (l + r) / 2;
	if (p <= mid)
		update_tree(2 * i, l, mid, p, x);
	else
		update_tree(2 * i + 1, mid + 1, r, p, x);
}