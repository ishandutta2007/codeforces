/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101;
int cnt[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < N; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[abs(x)]++;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += min((i == 0 ? 1 : 2), cnt[i]);
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