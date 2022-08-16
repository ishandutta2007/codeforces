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

const int N = 1e5 + 10, inf = 1e9 + 42;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		vector<int> pref(n, inf), suff(n, -inf);
		stack<int> stk;
		for (int i = 0; i < n; ++i) {
			while (stk.size() >= 2 and stk.top() < a[i]) {
				stk.pop();
			}
			if (stk.empty() or stk.top() > a[i]) {
				stk.push(a[i]);
			}
			if (stk.size() == 1) {
				pref[i] = stk.top();
			}
		}
		while (!stk.empty()) {
			stk.pop();
		}
		for (int i = n - 1; i >= 0; --i) {
			while (stk.size() >= 2 and stk.top() > a[i]) {
				stk.pop();
			}
			if (stk.empty() or stk.top() < a[i]) {
				stk.push(a[i]);
			}
			if (stk.size() == 1) {
				suff[i] = stk.top();
			}
		}
		bool ok = false;
		for (int i = 0; i < n - 1; ++i) {
			if (pref[i] < suff[i + 1]) {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}