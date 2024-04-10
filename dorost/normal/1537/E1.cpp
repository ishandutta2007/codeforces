/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012;
string r[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s;
	for (int i = 0; i < n; i++) {
		t += s[i];
		r[i] = t;
		while (r[i].size() < k) {
			r[i] += t;
		}
	}
	string mn;
	for (int i = 0; i < n; i++) {
		if (i == 0)
			mn = r[i];
		else {
			mn = min(mn, r[i]);
		}
	}
	for (int i = 0; i < k; i++) {
		cout << mn[i];
	}
}