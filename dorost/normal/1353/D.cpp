/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int ans[N];

void solve() {
	int n;
	cin >> n;
	int k = 1;
	set <pair <int, pair <int, int>>> st = {make_pair(0, make_pair(0, n - 1))}; // {n - size, {first, last}}
	while (true) {
		pair <int, pair <int, int>> p = *st.begin();
		st.erase(p);
		if (p.F == INT_MAX || p.F == n) {
			break;
		}
		int sz = n - p.F;
		sz--;
		st.insert({n - sz / 2, {p.S.F, p.S.F + sz / 2 - 1}});
		st.insert({INT_MAX, {p.S.F + sz / 2, p.S.F + sz / 2}});
		ans[p.S.F + sz / 2] = k;
		k++;
		st.insert({n - (sz + 1) / 2, {p.S.F + sz / 2 + 1, p.S.S}});
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}