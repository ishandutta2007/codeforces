/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int ask(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	cout.flush();
	int x;
	cin >> x;
	return (r - l + 1) - x;
}

int32_t main() {
	int n, poker_face, k;
	cin >> n >> poker_face >> k;
	int l = 0, r = n - 1;
	int ans = -1;
	while (l < r) {
		int mid = (l + r) / 2;
		int x = ask(1, mid + 1);
		if (x >= k) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if (ans == -1)
		ans = l;
	cout << "! " << ans + 1 << endl;
	cout.flush();
}