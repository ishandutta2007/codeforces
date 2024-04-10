/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

int32_t main() {
	int n;
	cin >> n;
	int mn = 0, mx = 0;
	int x = 0;
	set <int> st = {0};
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
		x += a[i];
		st.insert(x);
		mx = max(mx, x);
		mn = min(mn, x);
	}
	if (st.size() != n || *st.rbegin() - *st.begin() != n - 1) {
		cout << -1;
		return 0;
	}
	x = abs(mn);
	cout << x + 1 << ' ';
	for (int i = 0; i < n - 1; i++)  {
		x += a[i];
		cout << x + 1 << ' ';
	}
}