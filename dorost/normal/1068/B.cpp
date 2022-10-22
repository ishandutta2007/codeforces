/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i * i <= n; i++) {
		if (n % i)
			continue;
		ans++;
		if (i * i != n)
			ans++;
	}
	cout << ans;
}