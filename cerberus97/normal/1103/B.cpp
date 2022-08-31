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

const int N = 1e5 + 10;

bool ask(ll x, ll y);

int main() {
	fast_cin();
	string status;
	ll one = 1;
	while (true) {
		cin >> status;
		if (status == "end" or status == "mistake") {
			return 0;
		}
		if (ask(0, 1)) {
			cout << "! " << 1 << endl;
			continue;
		}
		ll i = 0;
		while (true) {
			bool geq = ask((one << i), (one << (i + 1)));
			if (geq == false) {
				++i;
			} else {
				break;
			}
		}
		ll lo = (one << i) + 1, hi = (one << (i + 1)) - 1;
		while (lo <= hi) {
			ll mid = (lo + hi) / 2;
			if (ask(mid, (one << i))) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout << "! " << hi + 1 << endl;
	}
}

bool ask(ll x, ll y) {
	cout << "? " << x << ' ' << y << endl;
	char c; cin >> c;
	if (c == 'e') {
		exit(0);
	} else {
		return c == 'x';
	}
}