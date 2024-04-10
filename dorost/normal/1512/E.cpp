/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 505;
int a[N];

void solve() {
	int n, l, r, s;
	cin >> n >> l >> r >> s;
	l--;
	for (int i = l; i < r; i++) {
		a[i] = i - l + 1;
		s -= (i - l + 1);
	}
	if (s < 0) {
		cout << -1 << '\n';
		return;
	}
	for (int i = r - 1; i >= l; i--) {
		int mx = n - (r - i - 1);
		if (mx - a[i] <= s) {
			s -= (mx - a[i]);
			a[i] = mx;
		} else {
			a[i] += s;
			s = 0;
		}
	}
	if (s != 0) {
		cout << -1 << '\n';
		return;
	}
	set <int> st;
	for (int i = 1; i <= n; i++)
		st.insert(i);
	for (int i = l; i < r; i++) {
		st.erase(a[i]);
	}
	for (int i = 0; i < l; i++) {
		a[i] = *st.begin();
		st.erase(st.begin());
	}
	for (int i = r; i < n; i++) {
		a[i] = *st.begin();
		st.erase(st.begin());
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
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