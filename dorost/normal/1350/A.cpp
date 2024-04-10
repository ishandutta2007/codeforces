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
	int t = 1;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		int ans = -1;
		for (int i = 2; i <= n; i++){
			if (n % i == 0){
				ans = i;
				break;
			}
		}
		if (n % 2){
			cout << ans + k * 2 + n - 2 << endl;
		}else{
			cout << ans * k + n << endl;
		}
	}
}