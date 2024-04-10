/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, m, k;
		cin >> n >> m >> k;
		int x = n / k;
		if (m <= x){
			cout << m << endl;
		}else{
			m -= x;
			m = (m + k - 2) / (k - 1);
			cout << max(0, x - m) << endl;
		}
	}
}