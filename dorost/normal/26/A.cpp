/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_prime (int x){
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int32_t main(){
	int x, ans = 0;
	cin >> x;
	for (int n = 1; n <= x; n++){
		int cnt = 0;
		for (int i = 2; i <= n; i++) {
			if (n % i == 0 && is_prime (i)){
				cnt++;
			}
			if (cnt > 2)
				break;
		}
		(cnt == 2 ? ans ++ : ans = ans);
	}
	cout << ans << endl;
}