/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int ctr_s[N], ctr_t[N], a_s[N], a_t[N];

int main() {
	fast_cin();
	string s, t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	for (int i = 1; i <= n; ++i) {
		ctr_s[i] = ctr_s[i - 1] + (s[i - 1] != 'A');
		if (s[i - 1] == 'A') {
			a_s[i] = 1 + a_s[i - 1];
		}
	}
	for (int i = 1; i <= m; ++i) {
		ctr_t[i] = ctr_t[i - 1] + (t[i - 1] != 'A');
		if (t[i - 1] == 'A') {
			a_t[i] = 1 + a_t[i - 1];
		}
	}
	int q; cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = ctr_s[b] - ctr_s[a - 1];
		int y = ctr_t[d] - ctr_t[c - 1];
		int e = min(b - a + 1, a_s[b]);
		int f = min(d - c + 1, a_t[d]);
		if ((x & 1) != (y & 1) or x > y or e < f) {
			cout << 0;
		} else if (!x and y and e == f) {
			cout << 0;
		} else if ((e % 3) == (f % 3)) {
			cout << 1;
		} else if (x < y) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
}