/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], cnt[N];

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n + 100; i++)
			cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		int mx = 0;
		for (int i = 0; i <= n; i++) {
			mx = max(mx, cnt[i]);
		}
		int ans = 0;
		for (int i =0; i <= n; i++) {
			if (cnt[i] == mx)
				ans ++;
		}
		cout << (n - ans) / (mx - 1) - 1 << endl;
	}
}