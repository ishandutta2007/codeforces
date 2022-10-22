/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int n, a, b, ans = 0;
	cin >> n >> a >> b;
	for (int i = 1; i < n; i++) {
		int x = i, y = n - i;
		ans = max(ans, min(a / x, b / y));
	}
	cout << ans;
}