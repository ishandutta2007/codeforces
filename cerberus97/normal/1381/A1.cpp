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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; string a, b;
		cin >> n >> a >> b;
		int l = 0, r = n - 1, dir = 1, flip = 0;
		reverse(b.begin(), b.end());
		vector<int> ops;
		for (auto& c : b) {
			if (c != (a[r] ^ flip)) {
				if (l == r) {
					ops.pb(1);
				} else {
					if (c == (a[l] ^ flip)) {
						ops.pb(1);
					}
					ops.pb(abs(r - l) + 1);
					l += dir;
					swap(l, r);
					dir *= -1;
					flip ^= 1;
				}
			} else {
				r -= dir;
			}
		}
		cout << ops.size() << ' ';
		for (auto& i : ops) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}