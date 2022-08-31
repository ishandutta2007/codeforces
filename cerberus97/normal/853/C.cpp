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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, M = 5e6 + 5;

int val[M], lc[M], rc[M];
int p[N], root[N], ctr = 0;

void build(int i, int l, int r, int p);
void build_persistent(int i, int j, int l, int r, int p);
inline ll query(int n, int i1, int i2, int j1, int j2);
int query_tree(int i, int l, int r, int ql, int qr);
inline ll c2(ll x) {return (x * (x - 1)) / 2;}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);

	root[1] = ctr++;
	build(root[1], 1, n, p[1]);
	for (int i = 2; i <= n; ++i)
	{
		root[i] = ctr++;
		build_persistent(root[i], root[i - 1], 1, n, p[i]);
	}

	while (q--)
	{
		int l, u, r, d;
		scanf("%d%d%d%d", &l, &u, &r, &d);
		ll ans = c2(n);
		ans -= c2(query(n, 1, u - 1, 1, n));
		ans -= c2(query(n, d + 1, n, 1, n));
		ans -= c2(query(n, 1, n, 1, l - 1));
		ans -= c2(query(n, 1, n, r + 1, n));
		ans += c2(query(n, 1, u - 1, 1, l - 1));
		ans += c2(query(n, 1, u - 1, r + 1, n));
		ans += c2(query(n, d + 1, n, 1, l - 1));
		ans += c2(query(n, d + 1, n, r + 1, n));
		printf("%lld\n", ans);
	}
}

void build(int i, int l, int r, int p)
{
	if (l <= p and p <= r)
		++val[i];

	if (l == r)
		return;

	int mid = (l + r) / 2;
	lc[i] = ctr++;
	rc[i] = ctr++;
	build(lc[i], l, mid, p);
	build(rc[i], mid + 1, r, p);
}

void build_persistent(int cur, int prev, int l, int r, int p)
{
	while (true)
	{
		val[cur] = 1 + val[prev];
		if (l == r)
			break;

		int mid = (l + r) >> 1;
		if (p <= mid)
		{
			lc[cur] = ctr++;
			rc[cur] = rc[prev];
			cur = lc[cur];
			prev = lc[prev];
			r = mid;
		}

		else
		{
			rc[cur] = ctr++;
			lc[cur] = lc[prev];
			cur = rc[cur];
			prev = rc[prev];
			l = mid + 1;
		}
	}
}

inline ll query(int n, int i1, int i2, int j1, int j2)
{
	if (i2 < i1 or j2 < j1)
		return 0;

	return query_tree(root[j2], 1, n, i1, i2) - ((j1 == 1) ? 0 : query_tree(root[j1 - 1], 1, n, i1, i2));
}

int query_tree(int i, int l, int r, int ql, int qr)
{
	if (l > qr or ql > r)
		return 0;

	if (ql <= l and r <= qr)
		return val[i];

	int mid = (l + r) >> 1;
	return query_tree(lc[i], l, mid, ql, qr) + query_tree(rc[i], mid + 1, r, ql, qr);
}