/*	* In the name of GOD
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
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++){
			ans += (i + 1) * (n - i);
		}
		ans *= 2;
		ans -= n * (n + 1);
		cout << ans << endl;
	}
}