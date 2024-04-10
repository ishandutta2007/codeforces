/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 301234;
int a[N], suf[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> a[i], sum += a[i];
	int x = 0;
	for (int i = n - 1; i >= 1; i--) {
		x += a[i];
		suf[i] = x;
	}
	sort(suf + 1, suf + n);
	reverse(suf + 1, suf + n);
	int ans = sum;
	for (int i = 1; i < k; i++) {
		ans += suf[i];
	}
	cout << ans;
}