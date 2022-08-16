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

const int N = 2e5 + 10, MX = 1e6;

ll check(ll x);

ll a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 2; i <= n; i += 2) {
		cin >> a[i];
	}
	ll s = 0;
	bool ok = true;
	for (int i = 1; i <= n; i += 2) {
		ok = false;
		for (ll j = s + 1; j < MX; ++j) {
			a[i] = j * j - s * s;
			ll temp = check(j * j + a[i + 1]);
			if (temp != -1) {
				ok = true;
				s = temp;
				break;
			}
		}
		if (!ok) {
			break;
		}
	}
	if (ok) {
		cout << "Yes\n";
		for (int i = 1; i <= n; ++i) {
			cout << a[i] << ' ';
		}
	} else {
		cout << "No\n";
	}
}

ll check(ll x) {
	ll test = sqrt(x);
	for (ll i = max(0ll, test - 2); i <= test + 2; ++i) {
		if (i * i == x) {
			return i;
		}
	}
	return -1;
}