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

const int N = 1e5 + 10, mod = 1e9 + 7;

ll solve(ll r);
ll ap_sum(ll a, ll n, ll d);

int main() {
	fast_cin();
	ll l, r;
	cin >> l >> r;
	ll ans = (solve(r) - solve(l - 1) + mod) % mod;
	cout << ans << endl;
}

ll solve(ll r) {
	ll ans = 0;
	ll nxt = 1, other = 2, sz = 1, start = 1;
	while (start <= r) {
		ll temp = min(r - start + 1, sz) % mod;
		ans += ap_sum(nxt, temp, 2);
		ans %= mod;
		nxt += 2 * sz;
		nxt %= mod;
		start += sz;
		swap(nxt, other);
		sz *= 2;
	}
	return ans;
}

ll ap_sum(ll a, ll n, ll d) {
	ll ans = (n * (n - 1)) / 2;
	ans %= mod;
	ans *= d;
	ans %= mod;
	ans += a * n;
	return ans % mod;
}