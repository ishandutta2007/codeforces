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

int get_type(int i, int a, int b);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		string s; cin >> s;
		vector<ll> piles;
		s += 'X';
		int n = s.length(), cur = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'X') {
				piles.pb(cur);
				cur = 0;
			} else {
				++cur;
			}
		}
		ll cnt_bad = 0, bad_size = 0, cnt_either = 0;
		for (auto &i : piles) {
			int type = get_type(i, a, b);
			if (type == 1) {
				cnt_bad = 2;
				break;
			} else if (type == 2) {
				++cnt_either;
			} else if (type == 3) {
				++cnt_bad;
				bad_size = i;
			}
		}
		if (cnt_bad > 1) {
			cout << "NO\n";
		} else if (cnt_bad == 0) {
			if (cnt_either % 2 == 1) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			bool can_win = false;
			for (int i = 0; i <= bad_size - a; ++i) {
				int l = i, r = bad_size - i - a;
				ll temp = cnt_either;
				l = get_type(l, a, b);
				r = get_type(r, a, b);
				if ((l % 2 == 1) or (r % 2 == 1)) {
					continue;
				}
				temp += (l == 2) + (r == 2);
				if (temp % 2 == 0) {
					can_win = true;
					break;
				}
			}
			if (can_win) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}

int get_type(int i, int a, int b) {
	if (i < b) {
		return 0;
	} else if (i < a) {
		return 1;
	} else if (i < 2 * b) {
		return 2;
	} else {
		return 3;
	}
}