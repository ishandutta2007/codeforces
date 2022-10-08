/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), ans;
	for (int &x : a) cin >> x;
	for (int l = 0, r = n - 1; l <= r; ) {
		ans.push_back(a[l++]);
		if (l <= r)
			ans.push_back(a[r--]);
	}	
	for (int x : ans) cout << x << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}