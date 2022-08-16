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

vector<int> s1;
multiset<int> s2;

int main() {
	fast_cin();
	int n; cin >> n;
	int balanced = 0;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		int del = 0, mx_neg = 0;
		for (auto &j : s) {
			if (j == '(') {
				++del;
			} else {
				--del;
				mx_neg = min(mx_neg, del);
			}
		}
		if (mx_neg < 0) {
			if (del == mx_neg) {
				s2.insert(-del);
			}
		} else if (del > 0) {
			s1.pb(del);
		} else if (del == 0) {
			++balanced;
		}
	}
	int ans = 0;
	for (auto &i : s1) {
		if (s2.find(i) != s2.end()) {
			++ans;
			s2.erase(s2.find(i));
		}
	}
	ans += balanced / 2;
	cout << ans << endl;
}