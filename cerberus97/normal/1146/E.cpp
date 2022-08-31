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

int a[N], x[N], ans[N];
char s[N];

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; ++i) {
		cin >> s[i] >> x[i];
	}
	int max_done = N, parity = 0;
	for (int i = q; i >= 1; --i) {
		if (s[i] == '<') {
			if (x[i] >= 0) {
				for (int j = x[i]; j < max_done; ++j) {
					ans[j] = parity;
				}
				parity = !parity;
				max_done = min(max_done, x[i]);
			} else {
				for (int j = abs(x[i]) + 1; j < max_done; ++j) {
					ans[j] = parity;
				}
				max_done = min(max_done, abs(x[i]) + 1);
			}
		} else {
			if (x[i] <= 0) {
				for (int j = abs(x[i]); j < max_done; ++j) {
					ans[j] = !parity;
				}
				parity = !parity;
				max_done = min(max_done, abs(x[i]));
			} else {
				for (int j = x[i] + 1; j < max_done; ++j) {
					ans[j] = !parity;
				}
				max_done = min(max_done, x[i] + 1);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int val = abs(a[i]);
		if (max_done <= val) {
			a[i] = (ans[val] ? -val : val);
		} else {
			a[i] = (parity ? -a[i] : a[i]);
		}
		cout << a[i] << ' ';
	}
}