#include <bits/stdc++.h>
using namespace std;

void solve() {
	int l, r, k;
	cin >> l >> r >> k;
	int odd = (r-l+1) - (r/2 - (l-1)/2);
	if(odd <= k || (l == r && l != 1)) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}