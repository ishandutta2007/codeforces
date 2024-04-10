/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N];

void solve() {
	int n;
	cin >> n;
	set <int> st;
	vector <int> v;
	for (int i = 0; i <= 100; i++) {
		st.insert(i);
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0)
			f = false;
		st.erase(a[i]);
	}
	if (!f) {
		cout << "NO\n";
		return;
	}
	cout << "Yes\n";
	for (auto x : st) {
		v.push_back(x);
	}
	cout << n + v.size() << '\n';
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	for (auto x : v) {
		cout << x << ' ';
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