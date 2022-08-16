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

const int N = 3e5 + 10;

bool check(string &s, int l, int r);

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length(), r = 0;
	ll ans = 0;
	for (int l = 0; l < n; ++l) {
		while (!check(s, l, r)) {
			++r;
			if (r == n) {
				break;
			}
		}
		if (r == n) {
			break;
		}
		ans += n - r;
	}
	cout << ans << endl;
}

bool check(string &s, int l, int r) {
	for (int x = l; x <= r; ++x) {
		for (int k = 1; x + 2 * k <= r; ++k) {
			if (s[x] == s[x + k] and s[x] == s[x + 2 * k]) {
				return true;
			}
		}
	}
	return false;
}