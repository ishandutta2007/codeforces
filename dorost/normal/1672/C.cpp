/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n;
	int fst = N, lst = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1])
			fst = min(fst, i);
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1])
			lst = max(lst, i);
	}
	if (fst == N || fst > lst) {
		cout << 0 << '\n';
	} else {
		cout << max(1, lst - fst) << '\n';
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