/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mkp make_pair
const int N = 101234;
int a[N];
pii b[N];

void solve() {
	int n;
	cin >> n;
	b[0] = {0, 0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i)
			b[i].F = a[i] - a[i - 1];
		b[i].S = i;
	}
	sort(b, b + n);
	reverse(b, b + n);
	for (int i = 0; i < n; i++) {
		cout << b[i].S + 1 << ' ';
	}
	cout << '\n';
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