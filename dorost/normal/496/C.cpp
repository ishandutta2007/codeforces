/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101;
string s[N], t[N], t2[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			t2[j] = t[j];
			t2[j] += s[j][i];
		}
		if (is_sorted(t2, t2 + n)) {
			for (int j = 0; j < n; j++) {
				t[j] = t2[j];
			}
		}
	}
	cout << m - t[rand() % n].size();
}

int32_t main() {
	solve();
}