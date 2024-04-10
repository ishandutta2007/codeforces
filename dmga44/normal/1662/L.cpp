#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

set<pair<int, int>> st[2 * 400005];

int query(int x, int b, int e, int lo, int hi, int ys)
{
	if (lo <= b && e <= hi)
	{
		auto it = st[x].lower_bound({ ys + 1, -1e9 });
		if (it != st[x].begin()) return prev(it)->second;
		return -1e9;
	}

	int m = (b + e) >> 1;
	int y = x + ((m - b) << 1);

	if (m >= hi) return query(x + 1, b, m, lo, hi, ys);
	if (m <= lo) return query(y, m, e, lo, hi, ys);
	return max(query(x + 1, b, m, lo, hi, ys), query(y, m, e, lo, hi, ys));
}

void update(int x, int b, int e, int lo, int hi, int zs)
{
	auto it = st[x].lower_bound({ hi, 1e9 });
	if (it == st[x].begin() || prev(it)->second < zs)
	{
		auto l = st[x].insert({ hi, zs }).first;
		auto r = l;
		while (next(r) != st[x].end() && zs >= next(r)->second) ++r;
		st[x].erase(next(l), next(r));
	}

	if (b + 1 == e)
		return;

	int m = (b + e) >> 1;
	int y = x + ((m - b) << 1);

	if (lo < m) update(x + 1, b, m, lo, hi, zs);
	else update(y, m, e, lo, hi, zs);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, v;
	cin >> n >> v;
	vector<int> t(n), a(n);
	for (auto &i : t) cin >> i;
	for (auto &i : a) cin >> i;

	vector<ll> p;
	for (int i = 0; i < n; ++i)
	{
		p.push_back((ll)v * t[i] + a[i]);
		p.push_back((ll)v * t[i] - a[i]);
	}

	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());

	auto get = [&](ll x)
	{
		return lower_bound(p.begin(), p.end(), x) - p.begin();
	};

	// vector<tuple<int, int, int>> g;
	auto query_ = [&](int x, int y)
	{
		debug(x, y, query(0, 0, p.size(), 0, x + 1, y));
		return query(0, 0, p.size(), 0, x + 1, y);
		// int r = -1e9;
		// for (auto [i, j, k] : g)
		// 	if (i <= x && j <= y)
		// 		r = max(r, k);
		// return r;
	};

	auto update_ = [&](int x, int y, int z)
	{
		debug(x, y, z);
		update(0, 0, p.size(), x, y, z);
		// g.emplace_back(x, y, z);
	};

	int ans = 0;
	vector<int> dp(n, -1e9);
	for (int i = 0; i < n; ++i)
	{
		if (abs(a[i]) <= (ll)v * t[i]) dp[i] = 1;
		int x = get((ll)v * t[i] + a[i]);
		int y = get((ll)v * t[i] - a[i]);
		dp[i] = max(dp[i], query_(x, y) + 1);
		update_(x, y, dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";

	return 0;
}