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

const int N = 2e5 + 10, A = N;

int a[N];
int lo[A], hi[A], cost[A];

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < A; ++i) {
		lo[i] = n + 1;
	}
	vector<pair<pii, int>> intervals;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		lo[a[i]] = min(lo[a[i]], i);
		hi[a[i]] = i;
		++cost[a[i]];
	}
	for (int i = 1; i < A; ++i) {
		if (lo[i] != n + 1) {
			intervals.pb({{lo[i], hi[i]}, cost[i]});
		}
	}
	sort(intervals.begin(), intervals.end());
	int r = 0;
	vector<vector<int>> components;
	for (auto &p : intervals) {
		if (p.first.first > r) {
			components.pb({p.second});
			r = p.first.second;
		} else {
			components.back().pb(p.second);
			r = max(r, p.first.second);
		}
	}
	ll ans = n;
	for (auto &c : components) {
		sort(c.begin(), c.end());
		ans -= c.back();
	}
	cout << ans << endl;
}