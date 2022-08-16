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

const int N = 1e5 + 10;

struct query_type
{
	int t, q1, q2;
};

int a[N], b[N], prv[N], lst[N], mp_sz[4 * N];
vector <ll> tree[4 * N];
vector <int> rev[4 * N];
vector <query_type> queries;
set <int> ids[N];
map <int, int> mp[4 * N];

void mp_add(int i, int l, int r, int p, int x);
void build(int i, int l, int r);
void update(int i, int l, int r, int p, int f1, int f2);
ll query(int i, int l, int r, int ql, int qr, int f1);
void tree_update(int t, int i, int l, int r, int p, int x);
ll tree_query(int t, int i, int l, int r, int ql);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	while (m--)
	{
		int t, q1, q2;
		cin >> t >> q1 >> q2;
		queries.pb({t, q1, q2});
	}

	for (int k = 0; k < 2; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			a[i] = b[i];
			prv[i] = lst[a[i]];
			lst[a[i]] = i;

			ids[a[i]].insert(i);
			ids[i].insert(0);
			ids[i].insert(n + 1);

			if (!k)
				mp_add(1, 1, n, i, prv[i]);

			else 
				update(1, 1, n, i, prv[i], i - prv[i]);
		}

		for (auto &q : queries)
		{
			if (q.t == 1)
			{
				int p = q.q1, x = a[p], y = q.q2, nxt = *(ids[x].upper_bound(p));
				ids[x].erase(p);
				prv[nxt] = prv[p];
				if (k)
				{
					update(1, 1, n, p, prv[p], prv[p] - p);
					if (nxt <= n)
					{
						update(1, 1, n, nxt, p, p - nxt);
						update(1, 1, n, nxt, prv[nxt], nxt - prv[nxt]);
					}
				}
					
				else if (nxt <= n)
					mp_add(1, 1, n, nxt, prv[nxt]);

				ids[y].insert(p);
				nxt = *(ids[y].upper_bound(p));
				prv[p] = *(--ids[y].find(p));
				prv[nxt] = p;
				a[p] = y;
				if (k)
				{
					update(1, 1, n, p, prv[p], p - prv[p]);
					if (nxt <= n)
					{
						update(1, 1, n, nxt, prv[p], prv[p] - nxt);
						update(1, 1, n, nxt, prv[nxt], nxt - prv[nxt]);
					}
				}

				else
				{
					mp_add(1, 1, n, p, prv[p]);
					if (nxt <= n)
						mp_add(1, 1, n, nxt, prv[nxt]);
				}
			}

			else if (k)
			{
				int l = q.q1, r = q.q2;
				cout << query(1, 1, n, l, r, l) << '\n';
			}
		}

		// for (int i = 1; i <= n; ++i)
		// 	cout << a[i] << ' ';
		// cout << endl;
		// for (int i = 1; i <= n; ++i)
		// 	cout << prv[i] << ' ';
		// cout << endl;

		if (!k)
		{
			build(1, 1, n);
			for (int i = 1; i <= n; ++i)
			{
				ids[i].clear();
				lst[i] = 0;
			}
		}
	}
}

void mp_add(int i, int l, int r, int p, int x)
{
	mp[i][x];
	if (l == r)
		return;

	int mid = (l + r) / 2;
	if (p <= mid)
		mp_add(2 * i, l, mid, p, x);
	else
		mp_add(2 * i + 1, mid + 1, r, p, x);
}

void build(int i, int l, int r)
{
	mp_sz[i] = mp[i].size();
	tree[i].resize(4 * mp_sz[i]);
	rev[i].resize(mp_sz[i] + 1);
	for (auto &j : tree[i])
		j = 0;

	int j = 1;
	for (auto &e: mp[i])
	{
		e.second = j;
		rev[i][j] = e.first;
		++j;
	}

	if (l == r)
		return;

	int mid = (l + r) / 2;
	build(2 * i, l, mid);
	build(2 * i + 1, mid + 1, r);
}

void update(int i, int l, int r, int p, int f1, int f2)
{
	// if (i == 1 and p <= 5)
	// 	cout << p << ' ' << f1 << ' ' << f2 << endl;

	tree_update(i, 1, 1, mp_sz[i], mp[i][f1], f2);
	if (l == r)
		return;

	int mid = (l + r) / 2;
	if (p <= mid)
		update(2 * i, l, mid, p, f1, f2);
	else
		update(2 * i + 1, mid + 1, r, p, f1, f2);
}

ll query(int i, int l, int r, int ql, int qr, int f1)
{
	if (l > qr or ql > r)
		return 0;

	if (ql <= l and r <= qr)
	{
		int lo = 1, hi = mp_sz[i];
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (rev[i][mid] >= f1)
				hi = mid - 1;
			else
				lo = mid + 1;
		}

		// for (int j = 1; j <= 4; ++j)
		// 	cout << rev[i][j] << ' ' << mp[i][rev[i][j]] << endl;

		return tree_query(i, 1, 1, mp_sz[i], hi + 1);
	}

	int mid = (l + r) / 2;
	return query(2 * i, l, mid, ql, qr, f1) + query(2 * i + 1, mid + 1, r, ql, qr, f1);
}

void tree_update(int t, int i, int l, int r, int p, int x)
{
	// if (t == 2 and i == 1)
	// 	cout << p << ' ' << x << endl;

	tree[t][i] += x;
	if (l == r)
		return;

	int mid = (l + r) / 2, lc = 2 * i, rc = 1 + lc;
	if (p <= mid)
		tree_update(t, lc, l, mid, p, x);
	else
		tree_update(t, rc, mid + 1, r, p, x);
}

ll tree_query(int t, int i, int l, int r, int ql)
{
	// if (t == 2)
	// 	cout << i << ' ' << l << ' ' << r << ' ' << tree[t][i] << endl;

	if (ql > r)
		return 0;

	if (ql <= l)
		return tree[t][i];

	int mid = (l + r) / 2;
	return tree_query(t, 2 * i, l, mid, ql) + tree_query(t, 2 * i + 1, mid + 1, r, ql);
}