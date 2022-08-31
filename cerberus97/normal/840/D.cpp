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

const int N = 3e5 + 10, K = 4, inf = 2 * N;

void build(int i, int l, int r);
inline void add(int i, int j, int l);
int query(int i, int l, int r, int ql, int qr, int k);

int a[N], ctr[N] = {0}, best[K];
vector <int> mf[4 * N][K];
vector <int> idx[N];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		idx[a[i]].pb(i);
	}

	build(1, 1, n);
	vector <int> ans;
	while (q--)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", query(1, 1, n, l, r, k));
	}
}

void build(int i, int l, int r)
{
	for (int k = 0; k < K; ++k)
		mf[i][k].resize(r - l + 1);

	if (l == r)
	{
		mf[i][0][0] = a[l];
		return;
	}

	int mid = (l + r) / 2;
	memset(best, 0, sizeof(best));
	for (int j = mid; j >= l; --j)
		add(i, j, l);

	for (int j = mid; j >= l; --j)
		ctr[a[j]] = 0;

	memset(best, 0, sizeof(best));
	for (int j = mid + 1; j <= r; ++j)
		add(i, j, l);

	for (int j = mid + 1; j <= r; ++j)
		ctr[a[j]] = 0;

	build(2 * i, l, mid);
	build(2 * i + 1, mid + 1, r);
}

inline void add(int i, int j, int l)
{
	++ctr[a[j]];
	bool chosen = false;
	for (int k = 0; k < K; ++k)
		if (best[k] == a[j])
			chosen = true;

	if (!chosen and ctr[a[j]] > ctr[best[K - 1]])
		best[K - 1] = a[j];

	for (int k = K - 1; k > 0; --k)
		if (ctr[best[k]] > ctr[best[k - 1]])
			swap(best[k], best[k - 1]);

	for (int k = 0; k < K; ++k)
		mf[i][k][j - l] = best[k];
}

int query(int i, int l, int r, int ql, int qr, int k)
{
	if (l == r)
		return a[l];

	int mid = (l + r) / 2;
	if (qr <= mid)
		return query(2 * i, l, mid, ql, qr, k);
	else if (ql > mid)
		return query(2 * i + 1, mid + 1, r, ql, qr, k);

	vector <int> candidates;
	for (int j = 0; j < K; ++j)
	{
		candidates.pb(mf[i][j][ql - l]);
		candidates.pb(mf[i][j][qr - l]);
	}

	int ans = inf;
	for (auto &j : candidates)
	{
		int occ = upper_bound(idx[j].begin(), idx[j].end(), qr) - lower_bound(idx[j].begin(), idx[j].end(), ql);
		if (occ * k > qr - ql + 1 and j < ans)
			ans = j;
	}

	if (ans == inf)
		return -1;

	return ans;
}