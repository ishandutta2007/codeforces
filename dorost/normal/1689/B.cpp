/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N];

void solve() {
	int n;
	cin >> n;
	set <int> st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(i + 1);
	}
	if (n == 1) {
		cout << -1 << '\n';
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		int x = (*st.begin());
		if (x != a[i]) {
			st.erase(x);
			cout << x << ' ';
		} else {
			auto wef = st.begin();
			wef++;
			x = *wef;
			st.erase(x);
			cout << x << ' ';
		}
	}
	int x = (*st.begin());
	int y = (*st.rbegin());
	if (a[n - 2] != x && a[n - 1] != y) {
		cout << x << ' ' << y << '\n';
	} else {
		cout << y << ' ' << x << '\n';
	}
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