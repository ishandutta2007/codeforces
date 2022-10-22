/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, M = 1012345;
int a[N], w[M];

void solve() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = sum + 1; j <= sum + a[i]; j++) {
			w[j] = i + 1;
		}
		sum += a[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		cout << w[x] << ' ';
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}