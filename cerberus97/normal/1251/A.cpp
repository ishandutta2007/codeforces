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

const int N = 1e5 + 10, A = 26;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.length();
		s += '0';
		char letter = 0;
		int cnt = 0;
		vector<bool> ok(A, false);
		for (int i = 0; i <= n; ++i) {
			if (s[i] == letter) {
				++cnt;
			} else {
				if (cnt % 2 == 1) {
					ok[letter - 'a'] = true;
				}
				letter = s[i];
				cnt = 1;
			}
		}
		string ans;
		for (int i = 0; i < A; ++i) {
			if (ok[i]) {
				ans += char(i + 'a');
			}
		}
		cout << ans << '\n';
	}
}