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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	ll ans = 0;
	for (auto& i : a) {
		cin >> i;
		ans += i * i;
	}
	sort(a.begin(), a.end());
	vector<vector<ll>> cuts(n);
	priority_queue<pll> q;
	for (int i = 0; i < n; ++i) {
		ll cnt = min((k - n) / (n - i), a[i] - 1);
		ll base = (a[i] * a[i]);
		for (int c = 2; c <= cnt + 1; ++c) {
			ll lo = (a[i] / c), hi = lo + 1;
			ll chi = (a[i] % c), clo = (c - chi);
			ll cost = lo * lo * clo + hi * hi * chi;
			cuts[i].pb(base - cost);
			base = cost;
		}
		cuts[i].pb(-1);
		reverse(cuts[i].begin(), cuts[i].end());
		q.push({cuts[i].back(), i});
	}
	for (int i = 0; i < (k - n); ++i) {
		auto cur = q.top();
		q.pop();
		ans -= cur.first;
		int j = cur.second;
		cuts[j].pop_back();
		q.push({cuts[j].back(), j});
	}
	cout << ans << '\n';
}