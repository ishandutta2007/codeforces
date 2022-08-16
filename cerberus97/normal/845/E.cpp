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

const int N = 500 + 10;
const ll inf = 1e9 + 10;

vector <pair <pll, pll>> events;
multiset <pll> ms;

pll solve(ll n, ll m);
bool not_covered(int l, int r);

int main()
{
	ll x[N], y[N];
	ll n, m; int k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i)
		cin >> x[i] >> y[i];

	ll l = 0, r = inf;
	while (l <= r)
	{
		ll t = (l + r) / 2;
		events.clear();
		for (int i = 0; i < k; ++i)
		{
			events.pb({{max(1ll, y[i] - t), -1ll}, {x[i] - t, x[i] + t}});
			events.pb({{min(y[i] + t + 1, m + 1), 1ll}, {x[i] - t, x[i] + t}});
		}

		pll p = solve(n, m);
		if (p.second - p.first > 2 * t)
		{
			l = t + 1;
			continue;
		}

		events.clear();
		for (int i = 0; i < k; ++i)
		{
			events.pb({{max(1ll, x[i] - t), -1ll}, {y[i] - t, y[i] + t}});
			events.pb({{min(x[i] + t + 1, n + 1), 1ll}, {y[i] - t, y[i] + t}});
		}

		p = solve(m, n);
		if (p.second - p.first > 2 * t)
			l = t + 1;

		else
			r = t - 1;
	}

	cout << r + 1;
}

pll solve(ll n, ll m)
{
	events.pb({{m + 1, -1}, {1, n}});
	sort(events.begin(), events.end());
	ll lo = m + 1, hi = 0, last_y = 1;
	ms.clear();
	for (auto &i : events)
	{
		ll y = i.first.first;
		int type = i.first.second;
		if (last_y < y and not_covered(1, n))
		{
			lo = min(lo, last_y);
			hi = max(hi, y - 1);
		}

		if (type == -1)
			ms.insert(i.second);
		else
			ms.erase(ms.find(i.second));

		last_y = y;
		// if (not_covered(1, n))
		// {
		// 	lo = min(lo, last_y);
		// 	hi = max(hi, y - 1);
		// }
	}

	return {lo, hi};
}

bool not_covered(int l, int r)
{
	ll nxt = l;
	for (auto &i : ms)
	{
		if (i.first <= nxt and i.second >= nxt)
			nxt = i.second + 1;
	}

	return nxt <= r;
}