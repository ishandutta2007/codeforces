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
		int a, b, c;
		cin >> a >> b >> c;
		int x = 1, y = b;
		if (c <= a){
			x = -1;
		}
		if (a * b <= c){
			y = -1;
		}
		cout << x << ' ' << y << endl;
	}
}