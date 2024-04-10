/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main() {
	int n;
	cin >> n;
	int n2 = n;
	int x = 0, lst = -1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0){
			x++;
			lst = i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n != 1) {
		x++;
		lst = n;
		n = 1;
	}
	if (x != 1) {
		cout << 1;
		return 0;
	} 
	cout << lst;
}