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

const int N = 2e5 + 10, A = 26;

int cnt[N][A];

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length();
	s = " " + s;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < A; ++j) {
			cnt[i][j] = cnt[i - 1][j] + (s[i] - 'a' == j);
		}
	}
	int q; cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (s[l] != s[r] or l == r) {
			cout << "Yes\n";
		} else {
			int diff = 0;
			for (int c = 0; c < A; ++c) {
				if (cnt[r][c] - cnt[l - 1][c]) {
					++diff;
				}
			}
			if (diff >= 3) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
}