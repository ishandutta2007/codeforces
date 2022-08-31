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

const int N = 50 + 10;
const ll inf = 2e18 + 42;

ll fact[N], cycles[N], dp[N];
int ans[N], inv[N];

int main() {
	fast_cin();
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		ld test = (ld(i) * fact[i - 1]);
		if (test > inf) {
			fact[i] = inf;
		} else {
			fact[i] = i * fact[i - 1];
		}
		cycles[i] = (i == 1 ? 1 : fact[i - 2]);
	}
	dp[0] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= i; ++j) {
			ld test = ld(dp[i]) + cycles[j] * dp[i - j];
			if (test > inf) {
				dp[i] = inf;
				break;
			} else {
				dp[i] += cycles[j] * dp[i - j];
			}
		}
	}
	int t; cin >> t;
	while (t--) {
		int n; ll k;
		cin >> n >> k;
		if (dp[n] < k) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			ans[i] = inv[i] = -1;
		}
		for (int l = 1; l <= n;) {
			int r = l;
			for (; r <= n; ++r) {
				ll here = cycles[r - l + 1] * dp[n - r];
				if (here < k) {
					k -= here;
				} else {
					break;
				}
			}
			ans[l] = r;
			inv[r] = l;
			ll step = dp[n - r];
			ll cur = (k - 1) / step + 1;
			k = ((k - 1) % step) + 1;
			for (int p = l + 1; p <= r; ++p) {
				int b = p;
				while (inv[b] != -1) {
					b = inv[b];
				}
				for (int x = l; x <= r; ++x) {
					if (inv[x] != -1 or (x == b and p < r)) {
						continue;
					}
					if (cycles[r - p + 1] < cur) {
						cur -= cycles[r - p + 1];
					} else {
						ans[p] = x;
						inv[x] = p;
						break;
					}
				}
			}
			l = r + 1;
		}
		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}