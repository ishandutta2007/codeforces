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
	ll n, d, m;
	cin >> n >> d >> m;
	vector<ll> small, large;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		if (a <= m) {
			small.pb(a);
		} else {
			large.pb(a);
		}
	}
	sort(small.begin(), small.end(), greater<ll>());
	sort(large.begin(), large.end(), greater<ll>());
	ll sum = 0;
	for (auto& i : small) {
		sum += i;
		i = sum;
	}
	sum = 0;
	for (auto& i : large) {
		sum += i;
		i = sum;
	}
	ll best = 0;
	for (ll m_days = 0; m_days <= n; ++m_days) {
		ll need_large = (m_days + d) / (d + 1);
		ll need_small = n - m_days;
		if (need_large <= large.size() and need_small <= small.size()) {
			ll cand = (need_small == 0 ? 0 : small[need_small - 1]);
			cand   += (need_large == 0 ? 0 : large[need_large - 1]);
			best = max(best, cand);
		}
	}
	cout << best << '\n';
}