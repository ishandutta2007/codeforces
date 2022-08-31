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

const int N = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 42;

pii a[N];
bool seen[N];
ll dp[N];
int lt[N], rt[N];

ll good(int n, int k);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	// a[0] = {inf, 0};
	// a[n + 1] = {inf, n + 1};
	stack<pii> st;
	st.push({inf, 0});
	for (int i = 1; i <= n; ++i) {
		while (st.top() < a[i]) {
			st.pop();
		}
		lt[i] = st.top().second;
		st.push(a[i]);
	}
	while (!st.empty()) {
		st.pop();
	}
	st.push({inf, n + 1});
	for (int i = n; i >= 1; --i) {
		while (st.top() < a[i]) {
			st.pop();
		}
		rt[i] = st.top().second;
		st.push(a[i]);
	}
	// cout << "wow" << endl;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		// cout << i << ' ' << lt[i] << ' ' << rt[i] << endl;
		int l = i - lt[i] - 1;
		int r = rt[i] - i - 1;
		ll temp = good(l + r + 1, k) - good(l, k) - good(r, k) - 1 + 5ll * mod;
		temp %= mod;
		temp = (temp * a[i].first) % mod;
		ans = (ans + temp) % mod;
	}
	cout << ans << endl;
}

ll good(int n, int k) {
	// cout << n << ' ' << k << endl;
	if (n == 0) {
		return 0;
	} else if (seen[n]) {
		return dp[n];
	} else {
		seen[n] = true;
		dp[n] = good(n - 1, k) + (n - 1) / (k - 1) + 1;
		dp[n] %= mod;
		return dp[n];
	}
}