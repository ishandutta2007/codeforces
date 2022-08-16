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
#include <random>
#include <chrono>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, K = 10, B = 60;

void update(ll &l, ll &r, ll n, int k);
bool query(ll l, ll r);

int main() {
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	fast_cin();
	ll n; int k;
	cin >> n >> k;
	ll l = 1, r = n;
	while (r - l + 1 > B) {
		update(l, r, n, k);
	}
	while (true) {
		ll guess = (uniform_int_distribution<ll>(l, r)(rng));
		if (query(guess, guess)) {
			return 0;
		} else {
			l = max(1ll, l - k);
			r = min(n, r + k);
			while (r - l + 1 > B) {
				update(l, r, n, k);
			}
		}
	}
}

void update(ll &l, ll &r, ll n, int k) {
	ll mid = (l + r) / 2;
	bool q = query(l, mid);
	if (q) {
		l = max(1ll, l - k);
		r = min(n, mid + k);
	} else {
		l = max(1ll, mid + 1 - k);
		r = min(n, r + k);
	}
}

bool query(ll l, ll r) {
	cout << l << ' ' << r << endl;
	string ans; cin >> ans;
	if (ans == "Bad") {
		exit(0);
	} else if (l == r and ans == "Yes") {
		exit(0);
	}
	return (ans == "Yes");
}