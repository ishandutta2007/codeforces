/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345;
int ps[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x = 0;
	string s;
	cin >> n >> s;
	int ok = n - 1;
	for (int i = 0; i < n; i++) {
		x += (s[i] == '(' ? 1 : -1);
		ps[i] = x;
		if (ps[i] < 0 && ok == n - 1) {
			ok = i - 1;
		}
	}
	if (x != 2 && x != -2) {
		cout << 0;
		return 0;
	}
	int ok2 = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (ps[i] - x < 0 && ok2 == 0) {
			ok2 = i + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == (x == 2 ? '(' : ')')) {
			if (i - 1 <= ok && i >= ok2) {
				ans++;
			}
		}
	}
	cout << ans;
}