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

ll solve(ll n, ll x);

int main() {
	fast_cin();
	ll n; int q;
	cin >> n >> q;
	while(q--) {
		ll x; cin >> x;
		cout << solve(n, x) << '\n';
	}
	// for (int i = 1; i <= n; ++i) {
	// 	cout << solve(n, i) << ' ';
	// }
}

ll solve(ll n, ll x) {
	ll i = 1;
	while (2 * i <= n) {
		i *= 2;
	}
	ll j = n - i;
	if (j) {
		if (x <= 2 * j) {
			if (x & 1) {
				return (x + 1) / 2;
			} else {
				return j + solve(i, i - j + (x / 2));
			}
		} else {
			return j + solve(i, x - 2 * j);
		}
	} else if (n == 1) {
		return 1;
	} else if (x & 1) {
		return (x + 1) / 2;
	} else {
		return (n / 2) + solve(n / 2, x / 2);
	}
}