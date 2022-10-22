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
	int l, r;
	cin >> l >> r;
	l = (l + 1) / 2 * 2;
	if (r - l < 2){
		cout << -1;
		return 0;
	}
	cout << l << ' ' << l + 1 << ' ' << l + 2; 
}