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

const int N = 1e5 + 5, E = 11;

struct node
{
	int f[E][E][4];
};

node* tree[3 * N];
char s[N];

void build_tree(int i, int l, int r);
void update(int i, int l, int r, int x, int c1, int c2);
int query(int i, int l, int r, int ql, int qr, int j, int e, int c);
inline int transform(char c);

int main()
{
	fast_cin();
	int q;
	cin >> s >> q;
	int n = strlen(s);
	build_tree(1, 1, n);
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x; char c;
			cin >> x >> c;
			if (s[x - 1] == c)
				continue;

			update(1, 1, n, x, transform(s[x - 1]), transform(c));
			s[x - 1] = c;
		}

		else
		{
			int l, r; string e;
			cin >> l >> r >> e;
			int ans = 0, m = e.size();
			for (int j = 0; j < m; ++j)
				ans += query(1, 1, n, l, r, (j + l) % m, m, transform(e[j]));

			cout << ans << '\n';
		}
	}
}

void build_tree(int i, int l, int r)
{
	tree[i] = new node();
	memset(tree[i]->f, 0, sizeof(tree[i]->f));
	if (l == r)
	{
		int c = transform(s[l - 1]);
		for (int e = 1; e < E; ++e)
			tree[i]->f[l % e][e][c] = 1;

		return;
	}

	int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
	build_tree(lc, l, mid);
	build_tree(rc, mid + 1, r);

	for (int e = 1; e < E; ++e)
		for (int j = 0; j < e; ++j)
			for (int c = 0; c < 4; ++c)
				tree[i]->f[j][e][c] = tree[lc]->f[j][e][c] + tree[rc]->f[j][e][c];
}

void update(int i, int l, int r, int x, int c1, int c2)
{
	for (int e = 1; e < E; ++e)
	{
		--tree[i]->f[x % e][e][c1];
		++tree[i]->f[x % e][e][c2];
	}

	if (l == r)
		return;

	int mid = (l + r) / 2;
	if (x <= mid)
		update(2 * i, l, mid, x, c1, c2);

	else
		update(2 * i + 1, mid + 1, r, x, c1, c2);
}

int query(int i, int l, int r, int ql, int qr, int j, int e, int c)
{
	if (l > qr or ql > r)
		return 0;

	if (ql <= l and r <= qr)
		return tree[i]->f[j][e][c];

	int mid = (l + r) / 2;
	return query(2 * i, l, mid, ql, qr, j, e, c) + query(2 * i + 1, mid + 1, r, ql, qr, j, e, c);
}

inline int transform(char c)
{
	if (c == 'A')
		return 0;
	if (c == 'T')
		return 1;
	if (c == 'G')
		return 2;
	return 3;
}