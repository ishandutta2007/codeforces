#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s; cin >> s;
	int a[s.size()] = {0};
	for (int i = 1; i < s.size(); ++i) {
		a[i] = s[i - 1] == s[i];
	}
	partial_sum(a, a + s.size(), a);
	int m; cin >> m;
	for (int i = 0;  i < m; ++i) {
		int l, r; cin >> l >> r;
		cout << (a[r - 1] - a[l - 1]) << '\n';
	}
	return 0;
}