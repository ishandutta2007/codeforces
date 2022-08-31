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

const int N = 1e5 + 10, B = 60;
const ll one = 1, inf = 1e15;

ll a[N];

int count_greater_equal(vector<ll> &A, ll target);
int solve(vector<ll> &A, int b, ll v);

int main() {
	fast_cin();
	int n; cin >> n;
	ll mx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = mx - a[i];
	}
	vector<pll> cand = {{0, 0}};
	for (int b = 0; b < B; ++b) {
		vector<ll> temp;
		for (int i = 1; i <= n; ++i) {
			temp.pb(a[i] & ((one << (b + 1)) - 1));
		}
		sort(temp.begin(), temp.end());
		int k = cand.size();
		for (int i = 0; i < k; ++i) {
			cand.pb(cand[i]);
			cand.back().first |= (one << b);
		}
		for (auto &p : cand) {
			p.second += solve(temp, b, p.first);
		}
		sort(cand.begin(), cand.end());
		vector<pll> new_cand;
		for (auto &p : cand) {
			if (new_cand.empty()) {
				new_cand.pb(p);
			} else {
				int id1 = count_greater_equal(temp, (one << (b + 1)) - new_cand.back().first);
				int id2 = count_greater_equal(temp, (one << (b + 1)) - p.first);
				if (id1 != id2) {
					new_cand.pb(p);
				} else if (p.second < new_cand.back().second) {
					new_cand.back() = p;
				}
			}
		}
		cand = new_cand;
	}
	vector<ll> temp;
	for (int i = 1; i <= n; ++i) {
		temp.pb(a[i]);
	}
	sort(temp.begin(), temp.end());
	ll ans = inf;
	for (auto &p : cand) {
		p.second += solve(temp, B, p.first);
		ans = min(ans, p.second);
	}
	cout << ans << '\n';
}

int count_greater_equal(vector<ll> &A, ll target) {
	int n = A.size();
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (A[mid] >= target) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return n - hi - 1;
}

int solve(vector<ll> &A, int b, ll v) {
	int ans = count_greater_equal(A, (one << b) - v);
	ans -= count_greater_equal(A, (one << (b + 1)) - v);
	ans += count_greater_equal(A, (one << b) + (one << (b + 1)) - v);
	ans -= count_greater_equal(A, (one << (b + 2)) - v);
	return ans;
}