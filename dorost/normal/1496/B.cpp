/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set <int> st, st2;
	for (int i = 0; i <= n + 2; i++) {
		st.insert(i);
	}
	for (int i = 0; i < n; i++) {
		st.erase(a[i]);
		st2.insert(a[i]);
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, a[i]);
	}
	int mex = *st.begin();
	if (mx == mex || mex == mx + 1) {
		cout << n + k << ' ';
	} else {
		if (k == 0)
			cout << n << ' ';
		else {
			if (!st2.count((mex + mx + 1) / 2)) {
				cout << n + 1 << ' ';
			} else {
				cout << n << ' ';
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}