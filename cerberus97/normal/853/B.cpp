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

const int N = 1e5 + 10, K = 1e6 + 10;
const ll inf = 1e12;

void update(int i, int l, int r, int ql, int qr, ll x, ll lz);

ll tree[4 * K], lazy[4 * K];
vector <pll> st[N], en[N];

int main()
{
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		ll d, f, t, c;
		cin >> d >> f >> t >> c;
		if (!t)
			st[f].pb({d, c});

		else
			en[t].pb({d, c});
	}

	if (2 > K - k)
	{
		cout << -1;
		return 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		st[i].pb({1, inf});
		st[i].pb({K, inf});
		en[i].pb({1, inf});
		en[i].pb({K, inf});
		sort(st[i].begin(), st[i].end());
		sort(en[i].begin(), en[i].end());
		int s1 = st[i].size(), s2 = en[i].size();
		ll best = inf;
		for (int j = 0; j < s1 - 1; ++j)
		{
			best = min(best, st[i][j].second);
			update(1, 2, K - k, st[i][j].first + 1, st[i][j + 1].first, best, 0);
		}

		best = inf;
		for (int j = s2 - 2; j >= 0; --j)
		{
			best = min(best, en[i][j + 1].second);
			update(1, 2, K - k, en[i][j].first - k + 1, en[i][j + 1].first - k, best, 0);
		}
	}

	if (tree[1] >= inf)
		cout << -1;
	else
		cout << tree[1];
}

void update(int i, int l, int r, int ql, int qr, ll x, ll lz)
{
	// cout << i << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
	tree[i] += lz;
	lazy[i] += lz;
	if (l > qr or ql > r or ql > qr)
		return;

	if (ql <= l and r <= qr)
	{
		tree[i] += x;
		lazy[i] += x;
		return;
	}

	if (l == r)
		return;

	int mid = (l + r) / 2, lc = 2 * i, rc = 1 + lc;
	update(lc, l, mid, ql, qr, x, lazy[i]);
	update(rc, mid + 1, r, ql, qr, x, lazy[i]);
	lazy[i] = 0;
	tree[i] = min(tree[lc], tree[rc]);
}