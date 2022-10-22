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
	while (t--) {
		int l, r;
		cin >> l >> r;
		if (l * 2 > r)
			cout << "-1 -1" << endl;
		else
			cout << l << ' ' << l * 2 << endl;
	}
}