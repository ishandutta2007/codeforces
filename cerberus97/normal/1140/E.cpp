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

const int N = 2e5 + 10, mod = 998244353;

int a[N];
ll dp1[N], dp2[N];

ll solve(vector<int> v, int k);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i + 2 <= n; ++i) {
		if (a[i] != -1 and a[i + 2] != -1 and a[i] == a[i + 2]) {
			cout << 0 << endl;
			return 0;
		}
	}
	dp1[1] = 0;
	dp2[1] = 1;
	dp1[2] = 1;
	dp2[2] = 0;
	for (int i = 3; i <= n; ++i) {
		dp1[i] = (k - 2) * dp1[i - 1] + dp2[i - 1];
		dp2[i] = (k - 1) * dp1[i - 1];
		dp1[i] %= mod; dp2[i] %= mod;
	}
	ll ans = 1;
	vector<int> v[2];
	for (int i = 1; i <= n; ++i) {
		v[i % 2].pb(a[i]);
	}
	ans *= solve(v[0], k);
	ans %= mod;
	ans *= solve(v[1], k);
	ans %= mod;
	cout << ans << endl;
}

ll solve(vector<int> v, int k) {
	int n = v.size();
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		if (v[0] == -1) {
			return k;
		} else {
			return 1;
		}
	}
	int l = -1;
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		if (v[i] != -1) {
			int s = (i - l + 1);
			if (l == -1) {
				--s;
				ans *= ((k - 1) * dp1[s]) % mod + dp2[s];
			} else if (v[l] != v[i]) {
				ans *= dp1[s];
			} else {
				ans *= dp2[s];
			}
			ans %= mod;
			l = i;
		}
	}
	int s = n - l;
	if (l == -1) {
		--s;
		ll temp = (k - 1) * dp1[s] + dp2[s];
		temp %= mod;
		temp *= k;
		temp %= mod;
		ans *= temp;
		ans %= mod;
	} else {
		ll temp = (k - 1) * dp1[s] + dp2[s];
		temp %= mod;
		ans *= temp;
		ans %= mod;
	}
	return ans;
}