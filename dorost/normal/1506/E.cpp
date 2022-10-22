/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], mx[N], mn[N];

void solve() {
	int n;
	cin >> n;
	deque <int> st, st2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mxx = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || a[i] != a[i - 1]) {
			mx[i] = a[i];
			mn[i] = a[i];
			for (int j = mxx + 1; j < a[i]; j++) {
				st.push_back(j);
				st2.push_back(j);
			}
			mxx = a[i];
		} else {
			int x = st.front();
			int y = st2.back();
			st.pop_front();
			st2.pop_back();
			mx[i] = y;
			mn[i] = x;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << mn[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << mx[i] << ' ';
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