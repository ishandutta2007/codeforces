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
const ll MAX = (1ll << 32) - 1;

int main() {
	fast_cin();
	int l; cin >> l;
	ll x = 0;
	stack<pll> stk;
	while (l--) {
		string s; cin >> s;
		if (s == "add") {
			++x;
			if (x > MAX) {
				break;
			}
		} else if (s == "for") {
			int n; cin >> n;
			stk.push({x, n});
		} else {
			ll delta = x - stk.top().first;
			x += delta * (stk.top().second - 1);
			stk.pop();
			if (x > MAX) {
				break;
			}
		}
	}
	if (x > MAX) {
		cout << "OVERFLOW!!!\n";
	} else {
		cout << x << endl;
	}
}