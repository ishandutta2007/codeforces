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
		int n, k;
		cin >> n >> k;
		int ans = 0;
		while (true){
			ans += n % k;
			n -= (n % k);
			if (n == 0)
				break;
			n /= k;
			ans ++;
			if (n == 0)
				break;
		}
		cout << ans << endl;
	}
}