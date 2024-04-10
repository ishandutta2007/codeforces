/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], ans[N];

void solve() {
	int n;
	cin >> n;
	set <int> st, st2;
	for (int i = 0; i < n; i++) {
		ans[i] = 0;
		cin >> a[i];
		st.insert(i + 1);
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (st2.count(a[i])) {
			continue;
		}
		st2.insert(a[i]);
		st.erase(a[i]);
		ans[i] = a[i];
	}
	cout << st2.size() << '\n';
	for (int i = 0; i < n; i++) {
		if (ans[i] == 0) {
			bool h = st.count(i + 1);
			if (h)
				st.erase(i + 1);
			if (st.empty()) {
				f = false;
				break;
			}
			int x = *st.rbegin();
			st.erase(x);
			ans[i] = x;
			if (h)
				st.insert(i + 1);
		}
	}
	if (!f) {
		st.clear();
		st2.clear();
		for (int i = 0; i < n; i++)
			ans[i] = 0;
		for (int i = 0; i < n; i++) {
			st.insert(i + 1);
		}
		for (int i = n - 1; i >= 0; i--) {
			if (st2.count(a[i])) {
				continue;
			}
			st2.insert(a[i]);
			st.erase(a[i]);
			ans[i] = a[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			if (ans[i] == 0) {
				bool h = st.count(i + 1);
				if (h)
					st.erase(i + 1);
				if (st.empty()) {
					assert(1);
				}
				int x = *st.rbegin();
				st.erase(x);
				ans[i] = x;
				if (h)
					st.insert(i + 1);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
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