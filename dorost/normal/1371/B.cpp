/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, r;
		cin >> n >> r;
		int ans = 0;
		if (r >= n)
			ans ++;
		int x = min(n - 1, r);
		ans += (x * (x + 1)) / 2;
		cout << ans << endl;
	}
}