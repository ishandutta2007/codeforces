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

const int N = 5e5 + 10;

int main() {
	fast_cin();
	int n; ll k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	ll ans = 0, cur = 1;
	for (int i = 0; i < n; ++i) {
		if (cur < k) {
			if (cur == 1) {
				if (s[i] != t[i]) {
					cur = 2;
				}
			} else {
				cur = 2 * (cur - 2) + 2;
				if (s[i] == 'a') {
					++cur;
				}
				if (t[i] == 'b') {
					++cur;
				}
			}
		}
		ans += min(cur, k);
	}
	cout << ans << endl;
}