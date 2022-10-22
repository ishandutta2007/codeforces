/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int n = a + b + 2 * c + 2 * d;
	string s;
	cin >> s;
	int ca = 0, cb = 0;
	for (char c : s) {
		if (c == 'A')
			ca++;
		else
			cb++;
	}
	if (ca != a + c + d || cb != b + c + d) {
		cout << "NO\n";
		return;
	}
	int lst = 0;
	vector <int> A, B;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || s[i] == s[i + 1]) {
			int l = lst;
			int r = i;
			int sz = (r - l + 1);
			sum += (sz - 1) / 2;
			if (sz % 2 == 0) {
				if (s[l] == 'A')
					A.push_back(sz / 2);
				else
					B.push_back(sz / 2);
			}
			lst = r + 1;
		}
	}
	int nc = c, nd = d;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i : A) {
		if (nc < i)
			break;
		sum++;
		nc -= i;
	}
	for (int i : B) {
		if (nd < i)
			break;
		sum++;
		nd -= i;
	}
	cout << (sum < c + d ? "NO" : "YES") << '\n';
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