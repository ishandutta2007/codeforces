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

const int N = 1e5 + 10, B = 61;

ll b[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	for (int j = B; j >= 0; --j) {
		vector<ll> v, e, g, rest;
		for (int i = 1; i <= n; ++i) {
			if (b[i] & (1ll << j)) {
				if ((b[i] >> (j + 1))) {
					g.pb(b[i]);
					v.pb(b[i]);
				} else {
					e.pb(b[i]);
				}
			} else if (b[i] >> (j + 1)) {
				g.pb(b[i]); 
			} else {
				rest.pb(b[i]);
			}
		}
		if (v.size() + 1 < e.size()) {
			cout << "No\n";
			return 0;
		}
		int vi = 0, ei = 0, gi = 0, ri = 0, i = 1;
		while (ei < e.size()) {
			b[i++] = e[ei++];
			if (vi < v.size()) {
				while (g[gi] != v[vi]) {
					b[i++] = g[gi++];
				}
				b[i++] = v[vi++];
				++gi;
			}
		}
		while (gi < g.size()) {
			b[i++] = g[gi++];
		}
		while (ri < rest.size()) {
			b[i++] = rest[ri++];
		}
		// if (i != n + 1) {
		// 	cout << "err";
		// }
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; ++i) {
		cout << b[i] << ' ';
	}
	// cout << endl;
	// for (int i = 1; i <= n; ++i) {
	// 	b[i] = b[i] ^ b[i - 1];
	// 	cout << b[i] << ' ';
	// }
}