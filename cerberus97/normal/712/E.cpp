/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include "iomanip"
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;

const int N = 1e5 + 5;

double f[3*N], g[3*N], p[N];

void update(int i, int l, int r, int x);
pdd query(int i, int l, int r, int ql, int qr);

int main()
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
	{
		int a, b;
		cin >> a >> b;
		p[i] = (double)a / b;
		update(1, 1, n, i);
	}

	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int i; double a, b;
			cin >> i >> a >> b;
			p[i] = (double)a / b;
			update(1, 1, n, i);
		}

		else
		{
			int l, r;
			cin >> l >> r;
			cout << fixed << setprecision(6) << query(1, 1, n, l, r).first << '\n';
		}
	}
}

void update(int i, int l, int r, int x)
{
	if (l == r)
	{
		f[i] = g[i] = p[l];
		return;
	}

	int mid = (l + r)/2;
	if (x <= mid)
		update(2*i, l, mid, x);
	else
		update(2*i + 1, mid + 1, r, x);

	double l1 = f[2*i], l2 = f[2*i + 1], r1 = g[2*i], r2 = g[2*i + 1];
	f[i] = (l1 * l2) / (1 - r1 * (1 - l2));
	g[i] = r2 + (r1 * l2 * (1 - r2)) / (1 - r1 * (1 - l2));
}

pdd query(int i, int l, int r, int ql, int qr)
{
	if (ql == l and qr == r)
		return {f[i], g[i]};

	int mid = (l + r) / 2;
	if (qr <= mid)
		return query(2*i, l, mid, ql, qr);
	if (ql > mid)
		return query(2*i + 1, mid + 1, r, ql, qr);

	pdd p1 = query(2*i, l, mid, ql, mid), p2 = query(2*i + 1, mid + 1, r, mid + 1, qr);
	double l1 = p1.first, r1 = p1.second, l2 = p2.first, r2 = p2.second;
	return {(l1 * l2) / (1 - r1 * (1 - l2)), r2 + (r1 * l2 * (1 - r2)) / (1 - r1 * (1 - l2))};
}