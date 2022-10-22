/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345;
bool f[N];
int ps[N];

void solve() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i <= c; i++) {
		f[i] = false;
		ps[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		f[x] = true;
	}
	if (!f[1]) {
		cout << "No\n";
		return;
	}
	ps[0] = 0;
	for (int i = 1; i <= c; i++) {
		ps[i] = ps[i - 1] + f[i];
	}
	for (int i = 2; i <= c; i++) {
		if (!f[i]) {
			for (int y = 1; y <= c / i; y++) {
				if (f[y]) {
					int l = y * i, r = y * (i + 1) - 1;
					if (ps[min(r, c)] - ps[l - 1] != 0) {
						cout << "No\n";
						return;
					}
				}
			}
		}
	}
	cout << "Yes\n";
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}