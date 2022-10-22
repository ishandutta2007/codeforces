/*	* In the name of GOD
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		int ans = 0;
		int x = k / (n - 1);
		ans += x * n;
		ans += k % (n - 1);
		if (k % (n - 1) == 0)
			ans --;
		cout << ans << '\n';
	}
}