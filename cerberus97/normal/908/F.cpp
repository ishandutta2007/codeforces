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

const int N = 3e5 + 10;
const ll inf = 1e15;

set <ll> red, blue, green;

ll solve(set <ll> &s, ll l, ll r);

int main() {
	fast_cin();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		ll x; char c;
		cin >> x >> c;
		if (c == 'G') {
			green.insert(x);
		} else if (c == 'R') {
			red.insert(x);
		} else {
			blue.insert(x);
		}
	}

	ll ans = 0;
	if (green.empty()) {
		if (!red.empty()) {
			ans += *red.rbegin() - *red.begin();
		}
		if (!blue.empty()) {
			ans += *blue.rbegin() - *blue.begin();
		}
		// if (!red.empty() and !blue.empty()) {
		// 	ll temp = inf;
		// 	for (auto &i : red) {
		// 		auto it = blue.upper_bound(i);
		// 		if (it != blue.end()) {
		// 			temp = min(temp, *it - i);
		// 		}
		// 		if (it != blue.begin()) {
		// 			--it;
		// 			temp = min(temp, i - *it);
		// 		}
		// 	}

		// 	ans += temp;
		// }
	} else {
		ans = *green.rbegin() - *green.begin();
		green.insert(inf);
		green.insert(-inf);
		auto cur = green.begin();
		auto nxt = cur;
		++nxt;
		while (nxt != green.end()) {
			ll t1 = solve(blue, *cur, *nxt);
			ll t2 = solve(red, *cur, *nxt);
			ll ch = (*nxt - *cur) - t1 - t2;
			ans += t1 + t2;
			if (t1 and t2 and ch < 0) {
				ans += ch;
			}

			cur = nxt++;
		}
	}

	cout << ans << endl;
}

ll solve(set <ll> &s, ll l, ll r) {
	auto st = s.upper_bound(l);
	auto en = s.upper_bound(r);
	if (st == en) {
		return 0;
	}

	--en;
	ll ans = max(*st - l, r - *en);
	while (st != en) {
		auto temp = st;
		++temp;
		ans = max(ans, *temp - *st);
		st  = temp;
	}

	return r - l - ans;
}