/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	int x = sqrt(n) + 100;
	set <int> st;
	for (int i = 1; i <= x; i++) {
		if (i * i <= n) {
			st.insert(i * i);
			if ((ll)i * (ll)i * (ll)i <= (ll)n) {
				st.insert(i * i * i);
			}
		}
	}
	cout << (int)st.size() << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}