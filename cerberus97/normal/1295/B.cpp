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
		int n, x; string s;
		cin >> n >> x >> s;
		int all = 0;
		for (auto& c : s) {
			if (c == '0') {
				++all;
			} else {
				--all;
			}
		}
		int ans = 0, cur = 0;
		for (auto& c : s) {
			if (all == 0) {
				if (cur == x) {
					ans = -1;
					break;
				}
			} else if ((x - cur) % all == 0 and (x - cur) / all >= 0) {
				++ans;
			}
			if (c == '0') {
				++cur;
			} else {
				--cur;
			}
		}
		cout << ans << '\n';
	}
}