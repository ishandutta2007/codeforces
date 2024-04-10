/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int cnt[N], x[N];

void solve() {
	int n, l;
	cin >> n >> l;
	int ans = 0;
	for (int i = 0; i < N; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		for (int j = 0; j < l; j++)  {
			cnt[j] += x[i] % 2;
			x[i] /= 2;
		}
	}
	for (int i = 0; i < l; i++) {
		if (cnt[i] > n / 2) 
			ans += (1 << i);
	}
	cout << ans << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}