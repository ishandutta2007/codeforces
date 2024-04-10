/* 	* In the name of GOD 
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
		int x, y, n;
		cin >> x >> y >> n;
		cout << (n - y) / x * x + y << ' ';
	}
}