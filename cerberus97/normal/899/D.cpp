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

const int N = 1e5 + 10;

ll solve(ll n);
ll brute(ll n);

int main() {
	ll n;
	cin >> n;
	cout << solve(n);
	// for (int i = 1; i <= 10000; ++i) {
	// 	int a1 = solve(i), a2 = brute(i);
	// 	if (a1 != a2) {
	// 		cout << i << ' ' << a1 << ' ' << a2 << endl;
	// 		break;
	// 	}
	// }
}

ll solve(ll n) {
	if (n < 5) {
		return (n * (n - 1)) / 2;
	}

	ll x = 5;
	while (x * 10 <= n) {
		x *= 10;
	}

	ll K = 2 * x - 1;
	if (K >= n) {
		return ((K - 1) / 2) - max(1ll, (K - n)) + 1;
	}

	ll ans = 0, d = n;
	while (d > 9) {
		d /= 10;
	}

	ll m = n - (d * (K + 1));
	for (int i = 0; i <= d; ++i) {
		for (int j = i; j <= d; ++j) {
			// if (n == 19) {
			// 	cout << i << ' ' << j << ' ' << ans << endl;
			// }

			if (!i and !j) {
				ans += x - 1;
			} else if (i == j) {
				if (i == 0) {
					ans += x - 1;
				} else if (i < d) {
					ans += x;
				} else {
					ans += max(0ll, ((K - 1) / 2) - max(0ll, (K - m)) + 1);
				}
			} else {
				if (i == 0 and j == d) {
					ans += min(2 * x - 1, m + 1);
				} else if (i == 0) {
					ans += 2 * x - 1;
				} else if (j == d) {
					ans += m + 1;
				} else {
					ans += 2 * x;
				}
			}
		}
	}

	// if (n == 10) {
	// 	cout << ans << endl;
	// }

	return ans;
}

ll brute(ll n) {
	int mx = 0, mx_ctr = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ll x = i + j;
			int ctr = 0;
			while (x % 10 == 9) {
				++ctr;
				x /= 10;
			}

			// if (n == 15 and ctr == 1) {
			// 	cout << i << ' ' << j << endl;
			// }

			if (ctr > mx) {
				mx = ctr;
				mx_ctr = 1;
			} else if (ctr == mx) {
				++mx_ctr;
			}
		}
	}

	return mx_ctr;
}