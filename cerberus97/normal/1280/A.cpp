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
 
const int N = 1e5 + 10, mod = 1e9 + 7;
 
int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int x; string s;
		cin >> x >> s;
		int len = s.length(), n = len;
		vector<pii> blocks = {{1, n}};
		s = " " + s;
		int bid = 0, off = 0;
		for (int l = 1; l <= x; ++l) {
			int id = blocks[bid].first + off;
			if (l > n) {
				s += s[id];
			}
			for (int j = 0; j < s[id] - '0' - 1; ++j) {
				blocks.pb({l + 1, len});
			}
			len += (ll(s[id] - '0' - 1) * (len - l + mod)) % mod;
			len %= mod;
			if (id < blocks[bid].second) {
				++off;
			} else {
				++bid;
				off = 0;
			}
		}
		cout << len << '\n';
	}
}