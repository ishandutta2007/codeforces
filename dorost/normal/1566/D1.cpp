/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 302;
int a[N];

void solve() {
	int poker_face, m;
	cin >> poker_face >> m;
	int x = 0;
	set <pair <int, int>> st;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		auto dd = st.lower_bound({a[i], -1});
		while (dd != st.begin()) {
			dd--;
			x++;
		}
		st.insert({a[i], i});
	}
	cout << x << ' '; 
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