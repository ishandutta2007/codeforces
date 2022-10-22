/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
pair <int, int> st[2];
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	st[0] = make_pair(0, -1);
	st[1] = make_pair(n + 1, -2);
	int ps = 0;
	bool f = false;
	int mx = 0, in1 = -1, in2 = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			st[0] = make_pair(0, i);
			st[1] = make_pair(n + 1, -2);
			f = false;
			ps = 0;
			continue;
		}
		if (a[i] == 2 || a[i] == -2)
			ps++;
		if (a[i] < 0)
			f = !f;
		if (st[f].S == -2) 
			st[f] = make_pair(ps, i);
		else {
			if (ps - st[f].F > mx) {
				mx = ps - st[f].F;
				in1 = st[f].S + 2;
				in2 = i + 1;
			}
		}
	}
	if (mx == 0) {
		cout << n << ' ' << 0 << '\n';
	} else {
		cout << in1 - 1 << ' ' << n - in2 << '\n';
	}
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