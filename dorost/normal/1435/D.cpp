/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
pair <bool, int> a[2 * N];

void solve() {
	int n;
	cin >> n;
	set <int> st;
	for (int i = 0; i < 2 * n; i++) {
		char c;
		cin >> c;
		if (c == '+') {
			a[i] = {1, 0};
		} else {
			int x;
			cin >> x;
			a[i] = {0, x};
		}
	}
	if (a[2 * n - 1].F == 1) {
		cout << "NO";
		return;
	}
	bool f = true;
	for (int i = 0; i < n * 2; i++) {
		if (a[i].F) {
			st.insert(i);
		} else {
			if (st.empty())
				f = false;
			int x = *st.rbegin();
			st.erase(x);
			a[x].S = a[i].S;
		}
	}
	if (!f) {
		cout << "NO";
		return;
	}
	st = {};
	for (int i = 0; i < n * 2; i++) {
		if (a[i].F) {
			st.insert(a[i].S);
		} else {
			int x = *st.begin();
			if (x != a[i].S)
				f = false;
			st.erase(x);
		}
	}
	if (!f) {
		cout << "NO";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < n * 2; i++)
		if (a[i].F)
			cout << a[i].S << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}