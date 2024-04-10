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
	int t = 1;
	cin >> t;
	while (t--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (b >= a){
			cout << b << endl;
			continue;
		}
		if (d >= c){
			cout << -1 << endl;
			continue;
		}
		a -= b;
		int x = c - d;
		cout << ((a + x - 1) / x) * c + b << endl;
	}
}