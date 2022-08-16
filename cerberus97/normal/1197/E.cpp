/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, mod = 1e9 + 7;
const ll inf = 1e15 + 42;

struct state_t {
	ll r, waste, ctr;
	bool operator>(const state_t &o) const {
		return r > o.r;
	}
};

pll a[N];

void merge(pll &x, pll y);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a + 1, a + 1 + n);
	priority_queue<state_t, vector<state_t>, greater<state_t>> q;
	pll ans = {inf, 0}, dp = {0, 1};
	for (int i = 1; i <= n; ++i) {
		ll l = a[i].first, r = a[i].second;
		while (!q.empty() and q.top().r <= l) {
			merge(dp, {q.top().waste - q.top().r, q.top().ctr});
			q.pop();
		}
		state_t cur = {r, dp.first + l, dp.second};
		q.push(cur);
		if (r > a[n].first) {
			merge(ans, {cur.waste, cur.ctr});
		}
	}
	cout << ans.second << '\n';
}

void merge(pll &x, pll y) {
	if (y.first < x.first) {
		x = y;
	} else if (y.first == x.first) {
		x.second += y.second;
		x.second %= mod;
	}
}