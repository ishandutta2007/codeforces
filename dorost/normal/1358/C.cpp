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
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		int X = x1 - x;
		int Y = y1 - y;
//		cout << X << ' ' << Y << endl;
		cout << X * Y + 1 << endl;
	}
}