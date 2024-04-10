/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 26;
int w[N];

void solve() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < 26; i++) {
		w[a[i] - 'a'] = i;
	}
	int ans = 0, lst = -1;
	for (auto c : b) {
		int x = w[c - 'a'];
		if (lst != -1) 
			ans += abs(x - lst);
		lst = x;
	}
	cout << ans << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}