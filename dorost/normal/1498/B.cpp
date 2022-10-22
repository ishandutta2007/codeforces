/*  * In the name of GOD 
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
	int n, w;
	cin >> n >> w;
	multiset <int> st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(a[i]);
	}
	int ans = 1, rem = w;
	for (int i = 0; ; i++) {
		if (st.size() == 0)
			break;
		auto in = st.upper_bound(rem);
		if (in == st.begin()) {
			ans++;
			rem = w;
			continue;
		} else {
			in--;
			rem -= *in;
			st.erase(in);
		}
	}
	cout << ans << ' ';
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